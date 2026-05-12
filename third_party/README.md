# Third-party dependencies

Everything under this directory is **vendored** — copied verbatim from upstream so the project builds with `git clone && cmake -B build && cmake --build build`, no network calls, no extra installs.

## `antlr3/`

[ANTLR 3.4](https://www.antlr3.org/) — parser generator and its C runtime.

| Path | What it is | License |
|------|------------|---------|
| `antlr3/bin/antlr-3.4-complete.jar` | ANTLR 3.4 code generator (Java) | BSD 3-Clause |
| `antlr3/include/` | libantlr3c public headers (prebuilt distribution copy) | BSD 3-Clause |
| `antlr3/lib/antlr3c.lib`, `antlr3cd.lib` | libantlr3c prebuilt static libs (MSVC, Win32) | BSD 3-Clause |
| `antlr3/libantlr3c-3.4/` | libantlr3c full source tree, built from source on macOS / Linux / MinGW | BSD 3-Clause |

ANTLR 3 has been frozen since 2014 (last release: 3.5.3). This project pins **3.4** because that's the version the original 2012 codebase was developed against and tested with. Upgrading would require regenerating and re-validating all four grammars.

Upstream:
- Generator jar: https://www.antlr3.org/download/antlr-3.4-complete.jar
- C runtime source: https://www.antlr3.org/download/C/libantlr3c-3.4.tar.gz

Copyright (c) 2003-2008 Terence Parr and contributors. See the BSD-3 notice at the top of any file in `libantlr3c-3.4/src/`.
