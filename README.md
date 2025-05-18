# box-clicker

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

Clean the generated files with:

```bash
make clean
```
