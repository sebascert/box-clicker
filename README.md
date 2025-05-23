# box-clicker

## Dependencies

The game uses the [SFML library](https://www.sfml-dev.org/).

## Clang DataBase, Linting and Formatting

Use [clang-tidy](https://clang.llvm.org/extra/clang-tidy/) and
[clang-format](https://clang.llvm.org/docs/ClangFormat.html), for linting and
formatting, correspondingly. Run the lint and format of the source code with:

```bash
make lint
make format
```

Both tools take advantage of the [clang compilation
database](https://clang.llvm.org/docs/JSONCompilationDatabase.html), it's
generation requires [bear](https://github.com/rizsotto/Bear), regenerate it
with:

```bash
make clangdb
```

## Compiling

From the guide on [compiling sfml](https://www.sfml-dev.org/tutorials/3.0/getting-started/linux/#compiling-an-sfml-program)

> If SFML is not installed in a standard path, you need to tell the dynamic
> linker where to find the SFML libraries first by specifying LD_LIBRARY_PATH:

Configure this env var with

```bash
export LD_LIBRARY_PATH=<sfml-install-path>/lib
```

Compile the game with:

```bash
make
# release build
make BUILD=release
```

## Clean Generated Files

Clean the generated files with:

```bash
make clean-all

# compilation files
make clean
# clang database
make clean-clangdb
```
