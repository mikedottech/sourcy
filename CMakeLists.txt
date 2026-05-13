cmake_minimum_required(VERSION 3.16)
project(compile LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_STANDARD 99)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

if(NOT MSVC)
    # GCC/Clang-only warning suppressions. -Wno-parentheses-equality is Clang-specific
    # but GCC silently ignores unknown -Wno-* flags, so it's safe to keep both.
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-switch -Wno-parentheses-equality")
endif()

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "" FORCE)
endif()

# ----------------------------------------------------------------------------
# Sanitizer build options
#
# Combine with any build type, e.g.:
#     cmake -S . -B build-asan  -DCMAKE_BUILD_TYPE=Debug -DSOURCY_ENABLE_ASAN=ON
#     cmake -S . -B build-ubsan -DCMAKE_BUILD_TYPE=Debug -DSOURCY_ENABLE_UBSAN=ON
#     cmake -S . -B build-san   -DCMAKE_BUILD_TYPE=Debug -DSOURCY_ENABLE_ASAN=ON -DSOURCY_ENABLE_UBSAN=ON
#
# ASan and UBSan are compatible with each other and can be enabled together.
# Both are mutually exclusive with TSan (not provided here).
# ----------------------------------------------------------------------------
option(SOURCY_ENABLE_ASAN  "Build with AddressSanitizer"   OFF)
option(SOURCY_ENABLE_UBSAN "Build with UndefinedBehaviorSanitizer" OFF)

set(_sourcy_sanitizers "")
if(SOURCY_ENABLE_ASAN)
    list(APPEND _sourcy_sanitizers address)
endif()
if(SOURCY_ENABLE_UBSAN)
    list(APPEND _sourcy_sanitizers undefined)
endif()

if(_sourcy_sanitizers)
    list(JOIN _sourcy_sanitizers "," _sourcy_san_list)
    message(STATUS "Sanitizers enabled: ${_sourcy_san_list}")

    if(MSVC)
        # MSVC supports ASan natively since VS 2019 16.9; UBSan is not supported.
        if(SOURCY_ENABLE_UBSAN)
            message(WARNING "UBSan is not supported on MSVC; ignoring SOURCY_ENABLE_UBSAN.")
        endif()
        if(SOURCY_ENABLE_ASAN)
            add_compile_options(/fsanitize=address /Zi)
            # ASan on MSVC: avoid /INCREMENTAL and /RTC1; cmake's Debug default
            # adds /RTC1, which conflicts. Strip it.
            string(REGEX REPLACE "/RTC[^ ]*" "" CMAKE_C_FLAGS_DEBUG   "${CMAKE_C_FLAGS_DEBUG}")
            string(REGEX REPLACE "/RTC[^ ]*" "" CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}")
        endif()
    else()
        # Clang / GCC / AppleClang
        add_compile_options(
            -fsanitize=${_sourcy_san_list}
            -fno-omit-frame-pointer
            -fno-optimize-sibling-calls
            -g)
        add_link_options(-fsanitize=${_sourcy_san_list})

        # UBSan: make every violation abort with a backtrace instead of just
        # printing and continuing — much easier to spot in a noisy run.
        if(SOURCY_ENABLE_UBSAN)
            add_compile_options(-fno-sanitize-recover=undefined)
        endif()
    endif()
endif()

# ----------------------------------------------------------------------------
# Paths
# ----------------------------------------------------------------------------
set(DEPS_DIR     "${CMAKE_CURRENT_SOURCE_DIR}/third_party/antlr3"
    CACHE PATH "Location of the antlr3 deps tree (contains bin/, include/, lib/, libantlr3c-3.4/)")
set(ANTLR3_JAR   "${DEPS_DIR}/bin/antlr-3.4-complete.jar"
    CACHE FILEPATH "Path to antlr-3.4-complete.jar")
set(LIBANTLR3C_DIR "${DEPS_DIR}/libantlr3c-3.4"
    CACHE PATH "Path to the libantlr3c-3.4 source tree")

if(NOT EXISTS "${ANTLR3_JAR}")
    message(FATAL_ERROR "ANTLR3 jar not found at ${ANTLR3_JAR}. Set -DANTLR3_JAR=...")
endif()

# ----------------------------------------------------------------------------
# Java (needed to run the ANTLR3 code generator)
# ----------------------------------------------------------------------------
find_package(Java REQUIRED COMPONENTS Runtime)

# ----------------------------------------------------------------------------
# libantlr3c (C runtime)
# ----------------------------------------------------------------------------
add_library(antlr3c_runtime INTERFACE)

# Build libantlr3c from the bundled source tree.
# The bundled antlr3config.h was generated on Linux and unconditionally
# defines HAVE_MALLOC_H, which breaks on macOS. Generate a platform-correct
# one in the build dir and put it ahead of the bundled one on the include path.
include(CheckIncludeFile)
include(CheckSymbolExists)
check_include_file(malloc.h         HAVE_MALLOC_H)
check_include_file(sys/malloc.h     HAVE_SYS_MALLOC_H)
check_include_file(stdint.h         HAVE_STDINT_H)
check_include_file(inttypes.h       HAVE_INTTYPES_H)
check_include_file(unistd.h         HAVE_UNISTD_H)
check_include_file(strings.h        HAVE_STRINGS_H)
check_include_file(string.h         HAVE_STRING_H)
check_include_file(stdlib.h         HAVE_STDLIB_H)
check_include_file(stdarg.h         HAVE_STDARG_H)
check_include_file(ctype.h          HAVE_CTYPE_H)
check_include_file(memory.h         HAVE_MEMORY_H)
check_include_file(sys/types.h      HAVE_SYS_TYPES_H)
check_include_file(sys/stat.h       HAVE_SYS_STAT_H)
check_include_file(sys/socket.h     HAVE_SYS_SOCKET_H)
check_include_file(netinet/in.h     HAVE_NETINET_IN_H)
check_include_file(netinet/tcp.h    HAVE_NETINET_TCP_H)
check_include_file(netdb.h          HAVE_NETDB_H)
check_include_file(arpa/nameser.h   HAVE_ARPA_NAMESER_H)
check_include_file(resolv.h         HAVE_RESOLV_H)
check_include_file(dlfcn.h          HAVE_DLFCN_H)
check_symbol_exists(memmove string.h HAVE_MEMMOVE)
check_symbol_exists(memset  string.h HAVE_MEMSET)
check_symbol_exists(strdup  string.h HAVE_STRDUP)

set(ANTLR3_CONFIG_DIR "${CMAKE_CURRENT_BINARY_DIR}/antlr3c_config")
file(MAKE_DIRECTORY "${ANTLR3_CONFIG_DIR}")
set(_cfg "${ANTLR3_CONFIG_DIR}/antlr3config.h")
file(WRITE  "${_cfg}" "/* Auto-generated by CMake — do not edit */\n")
file(APPEND "${_cfg}" "#ifndef ANTLR3CONFIG_H\n#define ANTLR3CONFIG_H 1\n")
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    file(APPEND "${_cfg}" "#define ANTLR3_USE_64BIT 1\n")
endif()
foreach(_v
    HAVE_MALLOC_H HAVE_SYS_MALLOC_H HAVE_STDINT_H HAVE_INTTYPES_H
    HAVE_UNISTD_H HAVE_STRINGS_H HAVE_STRING_H HAVE_STDLIB_H
    HAVE_STDARG_H HAVE_CTYPE_H HAVE_MEMORY_H HAVE_SYS_TYPES_H
    HAVE_SYS_STAT_H HAVE_SYS_SOCKET_H HAVE_NETINET_IN_H HAVE_NETINET_TCP_H
    HAVE_NETDB_H HAVE_ARPA_NAMESER_H HAVE_RESOLV_H HAVE_DLFCN_H
    HAVE_MEMMOVE HAVE_MEMSET HAVE_STRDUP)
    if(${_v})
        file(APPEND "${_cfg}" "#define ${_v} 1\n")
    endif()
endforeach()
file(APPEND "${_cfg}" "#define STDC_HEADERS 1\n")
file(APPEND "${_cfg}" "#endif\n")

file(GLOB LIBANTLR3C_SOURCES CONFIGURE_DEPENDS "${LIBANTLR3C_DIR}/src/*.c")
add_library(antlr3c STATIC ${LIBANTLR3C_SOURCES})
target_include_directories(antlr3c PUBLIC
    "${ANTLR3_CONFIG_DIR}"          # our generated antlr3config.h FIRST
    "${LIBANTLR3C_DIR}/include")
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    target_compile_definitions(antlr3c PUBLIC ANTLR3_USE_64BIT=1)
endif()
if(WIN32)
    target_compile_definitions(antlr3c PUBLIC _CRT_SECURE_NO_WARNINGS)
endif()
target_link_libraries(antlr3c_runtime INTERFACE antlr3c)

# ----------------------------------------------------------------------------
# ANTLR3 grammar code generation
# ----------------------------------------------------------------------------
set(GEN_DIR "${CMAKE_CURRENT_BINARY_DIR}/generated")
file(MAKE_DIRECTORY "${GEN_DIR}")

# antlr3_generate(GRAMMAR <name>.g  TOKENS <name>  OUTPUTS f1.c f1.h ...  DEPENDS <tokens-files...>)
function(antlr3_generate)
    cmake_parse_arguments(A "" "GRAMMAR;TOKENS" "OUTPUTS;DEPENDS" ${ARGN})
    set(_outputs "")
    foreach(_out IN LISTS A_OUTPUTS)
        list(APPEND _outputs "${GEN_DIR}/${_out}")
    endforeach()
    if(A_TOKENS)
        list(APPEND _outputs "${GEN_DIR}/${A_TOKENS}.tokens")
    endif()
    get_filename_component(_g_abs "${CMAKE_CURRENT_SOURCE_DIR}/${A_GRAMMAR}" ABSOLUTE)
    add_custom_command(
        OUTPUT  ${_outputs}
        COMMAND ${Java_JAVA_EXECUTABLE}
                -cp "${ANTLR3_JAR}"
                org.antlr.Tool
                -o "${GEN_DIR}"
                -fo "${GEN_DIR}"
                -lib "${GEN_DIR}"
                -message-format vs2005
                "${_g_abs}"
        DEPENDS "${_g_abs}" ${A_DEPENDS}
        WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
        COMMENT "ANTLR3: generating from ${A_GRAMMAR}"
        VERBATIM)
    get_filename_component(_g_name "${A_GRAMMAR}" NAME)
    set(${_g_name}_OUTPUTS "${_outputs}" PARENT_SCOPE)
endfunction()

# Order:
#   def.g       -> def.tokens
#   cns.g       -> cns.tokens   (imports def.tokens)
#   cnscheck.g  -> uses cns.tokens (tokenVocab)
#   luagen.g    -> uses cns.tokens (tokenVocab)

#antlr3_generate(
#    GRAMMAR Grammars/def.g
#    TOKENS  def
#    OUTPUTS defLexer.c defLexer.h defParser.c defParser.h)

antlr3_generate(
    GRAMMAR Grammars/cns.g
    TOKENS  cns
    OUTPUTS cnsLexer.c cnsLexer.h cnsParser.c cnsParser.h
)

#antlr3_generate(
#        GRAMMAR Grammars/cns.g3pl
#        TOKENS cns
#        OUTPUTS cnsLexer.c cnsLexer.h cnsParser.c cnsParser.h)

antlr3_generate(
    GRAMMAR Grammars/cnscheck.g
    OUTPUTS cnscheck.c cnscheck.h
    DEPENDS "${GEN_DIR}/cns.tokens")

antlr3_generate(
    GRAMMAR Grammars/luagen.g
    OUTPUTS luagen.c luagen.h
    DEPENDS "${GEN_DIR}/cns.tokens")

antlr3_generate(
        GRAMMAR Grammars/cppgen.g
        OUTPUTS cppgen.c cppgen.h
        DEPENDS "${GEN_DIR}/cns.tokens")


set(GENERATED_SOURCES
    ${def.g_OUTPUTS}
    ${cns.g_OUTPUTS}
    ${cnscheck.g_OUTPUTS}
    ${luagen.g_OUTPUTS}
    ${cppgen.g_OUTPUTS})

# ----------------------------------------------------------------------------
# Workaround: cap optimization on ANTLR3-generated tree parsers to -O1.
#
# ANTLR 3's C code generator has been frozen since 2014. Modern Clang/GCC at
# -O2+ mis-optimize the generated tree-parser code, breaking AST walks with
# bogus "UnwantedTokenException ... expected <UP>" errors that only appear in
# Release builds. Pinning these specific files to -O1 sidesteps the issue.
#
# Repro: with cloudi.cns + cloudi.cmd, -O2 fails inside cnscheck.c. AddressSan
# and UBSan don't catch it — the UB is in a class neither sanitizer covers.
# Performance impact is negligible: parsing/walking CNS is not the hot path.
#
# Left at default opt level: cnsLexer/cnsParser/defLexer/defParser — those are
# combined lexer+parser, not tree parsers, and don't exhibit the issue.
#
# MSVC: the workaround is GCC/Clang-only for now. The bug has not been observed
# on MSVC; if it ever is, swap `-O1` for `/Od` or `/O1` here.
# ----------------------------------------------------------------------------
if(NOT MSVC)
    set_source_files_properties(
        ${cnscheck.g_OUTPUTS}
        ${luagen.g_OUTPUTS}
        ${cppgen.g_OUTPUTS}
        PROPERTIES COMPILE_OPTIONS "-O1")
endif()

# ----------------------------------------------------------------------------
# Hand-written sources
# ----------------------------------------------------------------------------
set(COMPILE_SOURCES
    main.cpp
    CodeBlock.cpp
    CNSCodeBlock.cpp
    CompilationUnit.cpp
    Pipeline.cpp
    PipelineStage.cpp
    CNSFrontEndPipeline.cpp
    CNSCheckStage.cpp
    CNSFileToAST.cpp
    LUABackEndPipeline.cpp
    CPPBackEndPipeline.cpp
    CNSASTToLUAStage.cpp
    CNSASTToCPPStage.cpp
    ApplicationUsage.cpp
    ArgumentParser.cpp
    CNSControllerElement.cpp
    Version.cpp
    CNSCheckSemanticActions.cpp
    CNSSemanticActions.cpp
    LUAGenSemanticActions.cpp
    CPPGenSemanticActions.cpp
    CNSDataType.cpp
    CNSSemantics.cpp
    PostGenerator.cpp
    LUAPostGenerator.cpp
    CPPPostGenerator.cpp
    antlr3customtokenstream.c
    Helpers.c
    HelpersCpp.cpp)

add_executable(compile ${COMPILE_SOURCES} ${GENERATED_SOURCES})

target_include_directories(compile PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${GEN_DIR}")

target_link_libraries(compile PRIVATE antlr3c_runtime)

# ----------------------------------------------------------------------------
# Platform / compiler hygiene
# ----------------------------------------------------------------------------
if(MSVC)
    target_compile_definitions(compile PRIVATE
        _CRT_SECURE_NO_WARNINGS
        _CRT_NONSTDC_NO_DEPRECATE
        WIN32 _CONSOLE)
    target_compile_options(compile PRIVATE /W3 /wd4996)
else()
    target_compile_options(compile PRIVATE
        -Wno-unused-parameter
        -Wno-unused-variable
        -Wno-unused-function
        -Wno-write-strings
        -Wno-deprecated-declarations
        -Wno-pointer-sign
        -Wno-incompatible-pointer-types
        -fpermissive)
endif()

if(APPLE)
    target_compile_definitions(compile PRIVATE __APPLE__)
endif()

message(STATUS "compile: java=${Java_JAVA_EXECUTABLE}")
message(STATUS "compile: antlr jar=${ANTLR3_JAR}")
message(STATUS "compile: generated sources -> ${GEN_DIR}")
