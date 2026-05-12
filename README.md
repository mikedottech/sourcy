# Sourcy — CNS → Lua Compiler

> **Legacy code, circa 2012.** I wrote this as part of a [MUGEN](https://en.wikipedia.org/wiki/Mugen_(game_engine)) clone I was building back then.
> The MUGEN engine drives characters with a scripting format called **CNS** (Character States) plus **CMD** (Command/Input) files. Sourcy parses those files and emits **Lua** that a Lua-based runtime can execute.
>
> This is being revived from a Visual Studio 2008 project. The original code, the grammars, and the architecture are unchanged — only the build system is new.

---

## What it does

```
compile  krono.cns krono2.cns krono3.cns krono.cmd  --output LUA  --noopwrap
```

Given one or more `.cns` / `.cmd` files describing a MUGEN-style character, Sourcy emits a set of Lua files:

```
crono.lua          ← state blocks from krono.cns
crono2.lua         ← state blocks from krono2.cns
crono3.lua         ← state blocks from krono3.cns
cronocmd.lua       ← command definitions from krono.cmd
cronomain.lua      ← entry point: require()s the other files
```

`cronomain.lua` is the master file — the runtime loads it, which pulls in the per-file modules. Each character state in CNS becomes a Lua function on the character object (e.g. `function crono:state100() ... end`), and the host runtime ticks the state machine on every frame.

A worked example of the input → output translation lives in [`compilerinfo.txt`](./compilerinfo.txt).

---

## Prerequisites

| Tool | Why |
|------|-----|
| **CMake ≥ 3.16** | Build system |
| **A C/C++ compiler** | MSVC, Clang, or GCC. C99 + C++11 |
| **Java (JRE/JDK)** | To run the ANTLR 3.4 code generator at build time |

The ANTLR 3.4 jar and the libantlr3c C runtime source are vendored under [`third_party/antlr3/`](./third_party/), so you don't need to install ANTLR or its C runtime separately. On MSVC the build picks up the prebuilt `.lib`; on macOS / Linux / MinGW it compiles libantlr3c from source.

---

## Build

```bash
cmake -S . -B build
cmake --build build
```

Override the deps location if needed:

```bash
cmake -S . -B build \
    -DDEPS_DIR=/path/to/deps/antlr3 \
    -DANTLR3_JAR=/path/to/antlr-3.4-complete.jar
```

The executable lands at `build/compile` (or `build/Debug/compile.exe` on multi-config generators).

---

## Architecture

Sourcy is structured as a **pipeline of stages** that pass an AST between them. Every stage implements a `PipelineStage` interface and is composed into a `Pipeline`. There are two pipelines — a fixed front-end and an interchangeable back-end:

```
                ┌────────────────────────── FRONT-END (fixed) ──────────────────────────┐
input files ──► │  parser (ANTLR3 lexer+parser)  ──►  AST  ──►  semantic check  ──►  AST │
                └───────────────────────────────────────────────────────────────────────┘
                                                  │
                                                  ▼
                        ┌────────── BACK-END (per output target) ──────────┐
                        │  AST  ──►  code generator  ──►  code blocks       │
                        └──────────────────────────────────────────────────┘
                                                  │
                                                  ▼
                                       Lua source files on disk
```

Conceptually that maps to the source tree like this:

| Stage                              | Class / File |
|-----------------------------------|--------------|
| File → AST                         | `CNSFileToAST` |
| AST semantic & error check         | `CNSCheckStage` (`cnsCheckSemanticActions.cpp`) |
| AST → Lua intermediate code blocks | `CNSASTToLUAStage` (`luagenSemanticActions.cpp`) |
| Per-target code emission           | `LUAPostGenerator` |
| Pipeline plumbing                  | `Pipeline`, `PipelineStage`, `CNSFrontEndPipeline`, `LUABackEndPipeline` |

### Grammars (ANTLR 3)

The lexers, parsers, and tree walkers are written in [ANTLR 3](https://www.antlr3.org/). At build time, CMake invokes `java -cp antlr-3.4-complete.jar org.antlr.Tool` over four grammar files (under `Grammars/`) which emit C code into `build/generated/`:

| Grammar       | Kind                | Produces                          | Purpose |
|---------------|---------------------|-----------------------------------|---------|
| `def.g`       | Combined lexer+parser | `defLexer.{c,h}`, `defParser.{c,h}` | Tokens shared across CNS — pulled in via `tokenVocab` |
| `cns.g`       | Combined lexer+parser | `cnsLexer.{c,h}`, `cnsParser.{c,h}` | CNS source → AST |
| `cnscheck.g`  | Tree parser          | `cnscheck.{c,h}`                    | Walks the AST to validate semantics, emit errors |
| `luagen.g`    | Tree parser          | `luagen.{c,h}`                      | Walks the AST and emits Lua |

The dependency chain matters: `cns.g` imports tokens from `def.g`, and both tree parsers import tokens from `cns.g`. The CMake build models that explicitly via `cns.tokens` / `def.tokens` as build artifacts.

### From characters to state machines

A CNS file is essentially a list of **state blocks**. Each block has a numeric ID and a body containing controllers (`PlaySnd`, `ChangeState`, `HitDef`, …) gated by triggers (`triggerall`, `trigger1`, `trigger2`, …). The compiler emits one Lua function per state block, with controllers translated to function calls and triggers to chained boolean expressions:

```lua
function crono:state100()
    if time() == 0 then
        setStateInfo({ type = "S", movetype = "A", physics = "S" })
    end

    if triggerall and triggerall ... then
        if (trigger1 and trigger1 ...) or
           (trigger2 and trigger2 ...) then
            playSnd({ value = id("S", 10), volumeScale = 1.0 })
        end
    end
end
```

The runtime (not in this repo) provides the `mugenChar` superclass, the per-frame `onTick` / `onRender` loop, input handling, collision/hit boxes, and the controller / trigger primitives that the generated code calls into.

The semantic checker enforces things like **no duplicate state IDs across input files** — that's why multi-file inputs are passed in a single invocation rather than compiled independently.

---

## AST examples

These are real ASTs produced by the front-end during development (rendered to PNG via ANTLR's debug output). They give you a feel for what the parser is doing before code generation kicks in.

### Full state-def block

A complete `[StateDef N]` block with `[State N]` controllers underneath.

![Full statedef AST](tests/fullstatedeftest.png)

### Expression parsing

How MUGEN trigger expressions get parsed — operator precedence, function calls, comparisons.

![Expression AST](tests/exprtest.png)

### Nesting

Nested control structures and how triggers chain.

![Nesting AST](tests/nestingtest.png)

### Intervals

Interval / range trigger expressions (e.g. `time = [0, 10]`).

![Interval AST](tests/intervaltest.png)

A larger CNS corpus used during development is in [`tests/cnstest.txt`](tests/cnstest.txt).

---

## Project layout

```
compile/
├── CMakeLists.txt            ← cross-platform build
├── main.cpp                  ← entry point, arg parsing, pipeline wiring
├── Pipeline*.{cpp,h}         ← pipeline / stage abstractions
├── CNS*.{cpp,h}              ← front-end stages (parse, check)
├── LUA*.{cpp,h}              ← back-end stages (codegen, post-gen)
├── cns*.{cpp,h}              ← semantic-action helpers used by the ANTLR grammars
├── antlr3customtokenstream.* ← custom token stream used by the front-end
├── Grammars/
│   ├── def.g
│   ├── cns.g
│   ├── cnscheck.g
│   └── luagen.g
├── third_party/
│   └── antlr3/               ← vendored ANTLR 3.4 jar + libantlr3c source (BSD-3)
├── tests/                    ← sample inputs and AST screenshots
└── compilerinfo.txt          ← original design notes (2012)
```

---

## Caveats

- Code from 2012, originally targeting **Visual Studio 2008 + Win32**. Expect warnings on modern Clang/GCC — the CMakeLists silences the worst offenders (`-Wno-pointer-sign`, `-Wno-incompatible-pointer-types`, `-fpermissive`) without "fixing" anything.
- The bundled `antlr3config.h` shipped with libantlr3c-3.4 is regenerated at configure time from CMake's own `check_include_file` probes, because the vendored copy assumed Linux (`malloc.h` is not a thing on macOS).
- The runtime that consumes the generated Lua is **not** in this directory — this repo is only the compiler.

---

## Code quality notes

This is **preserved 2012 C++**, not a continuously maintained codebase. The goal of bringing it back was to make it build and run on modern toolchains, not to modernize the source. Treat the contents as a historical snapshot, with a few specific notes for any reader who wants to understand the trade-offs:

- **Global state in semantic actions.** Files like `CNSSemanticActions.cpp`, `CNSCheckSemanticActions.cpp` and `LUAGenSemanticActions.cpp` hold per-walk state in file-scope variables (`pCurController*`, `pCurCodeBlock`, …). This is **inherent to ANTLR 3 with C actions**: grammar callbacks are free functions with no context pointer, so per-walk state has to live somewhere accessible. The compiler runs single-threaded, so this is correct — just not thread-safe. Modern ANTLR 4 grammars don't need this pattern.
- **Raw `new` / `delete` in the pipeline.** `Pipeline` owns its stages via raw pointers and frees them in its destructor. Pre-`unique_ptr` style; functionally fine, idiomatically out of date.
- **`CNSSemantics.cpp` is large (≈8.4k lines).** It is almost entirely a **table of controller / trigger signatures**, not behavior. Conceptually it's a data file disguised as a translation unit. Splitting it would be cosmetic.
- **Tree parser interfaces via `dynamic_cast`.** `Pipeline` uses `dynamic_cast` between `PipelineStage` and the `InputXxx` / `OutputXxx` interfaces. Functionally correct multi-interface composition; today it would be designed with templates or `std::variant` over a state-type tag.
- **Argument parser is permissive.** Bad numeric input falls through `atoi` without error reporting. Tolerable for a tool you invoke yourself; not how you'd write a library.
- **What `--clean-build` would look like.** Were this still an active project, the modernization path would be: `std::unique_ptr` for stage ownership, `std::filesystem::path` for path handling, an explicit walker context struct to replace the file-scope semantic-action globals, and ANTLR 4 to retire the C/C++ interop boundary. None of that is in scope for an archival release.

If you're looking for a model of modern C++ design, **this is not it**. If you're looking for a working ANTLR-3 compiler front-end with a clean pipeline architecture, it's a reasonable starting point.

---

## License

Released under the [MIT License](./LICENSE). Copyright (c) 2012-2026 Miguel Angel Exposito Sanchez (radexx).

You can use, modify, and redistribute this code — including in closed-source derivative products — **as long as the copyright notice and license text are preserved** in the distribution.

### Trademarks

"MUGEN" is a trademark of Elecbyte. This project is unaffiliated with and not endorsed by Elecbyte. It only consumes the CNS/CMD text formats, which are interoperability descriptions and not copyrighted artifacts.

### Third-party components

This project links against [libantlr3c](https://www.antlr3.org/) 3.4 and uses the ANTLR 3.4 code generator, both distributed under the BSD 3-Clause license. Their copyright notices apply to the generated and runtime code.
