# Get Next Line

## Build and debug

### Command line build for debug, and run

```
cd get_next_line_bonud
gcc -g -Wall -Wextra -Werror -D BUFFER_SIZE=1098098 get_next_line/*.c -o get_next_line_bonud
./get_next_line_bonus

cd get_next_line
gcc -g -Wall -Wextra -Werror -D BUFFER_SIZE=1098098 get_next_line_bonus/*.c -o build/get_next_line_bonus
./get_next_line
```

### Command line build and dynamical analysis with `valgrind`

Requires a Linux VM but I can do it on my laptop or set you up. Works great and I think is pointing us in all the right directions:

```
cd get_next_line_bonus
gcc -g -O0 -Wall -Wextra -Werror -D BUFFER_SIZE=1098098 *.c -o get_next_line_bonus
valgrind --leak-check=full --track-origins=yes -s ./get_next_line_bonus
```

### VS Code

You can build and debug directly in VS Code using the regular VS Code Debug tab. Select a file in the directory of the version you want to build (`get_new_line` or `get_new_line_bonus`). Go to the VS Code Debug area and click play. It should build and debug.

### XCode

Additionally, you can build and debug in XCode (which gives some REALLY interesting results) for `get_next_line_bonus` by opening the provided *42_get_next_line* XCode project in the `get_next_line_bonus` folder.

# Notes

Tester that returns possibly useful debug thangs: https://github.com/xicodomingues/francinette

# TODOS:

[] Get the code working (duh)
[] Look into getting a normette linter running either form the command line or in VS Code
[] Look into OrbStack or UTM for setting-up a Ubuntu 22.04 instance setup with the tools used at 42 for consistency when debugging this and future projects
