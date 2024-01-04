# Get Next Line

## Build and debug

### Command line build for debug, and run

```sh
cd get_next_line_bonus
gcc -g -fsanitize=address -O0 -Wall -Wextra -Werror -D BUFFER_SIZE=1098098 *.c -o get_next_line_bonus
./get_next_line_bonus

cd get_next_line
gcc -g -fsanitize=address -O0 -Wall -Wextra -Werror -D BUFFER_SIZE=1098098 *.c -o get_next_line_bonus

# To compile and run in one command just append ` && get_next_line_bonus` to the above compile command and profit!
```

_Note the additional `-fsanitize=address` param above. Adding that did cause compilation to fail with a detailed buffer / heap overflow debug trace. Importantly that failure happened equally in both Linux and on MacOS. This should be one of the best ways to compile going forward to make sure things are going to work across both platforms, and ultimately to catch memory allocation issues early._

### Command line build and dynamical analysis with `valgrind`

Requires a Linux VM but I can do it on my laptop or set you up. Works great and I think is pointing us in all the right directions:

```sh
cd get_next_line_bonus
gcc -g -O0 -Wall -Wextra -Werror -D BUFFER_SIZE=1098098 *.c -o get_next_line_bonus
valgrind --tool=memcheck --leak-check=full --track-origins=yes -s ./get_next_line_bonus
```

### VS Code

You can build and debug directly in VS Code using the regular VS Code Debug tab. Select a file in the directory of the version you want to build (`get_new_line` or `get_new_line_bonus`). Go to the VS Code Debug area and click play. It should build and debug.

### XCode

Additionally, you can build and debug in XCode (which gives some REALLY interesting results) for `get_next_line_bonus` by opening the provided *42_get_next_line* XCode project in the `get_next_line_bonus` folder.

# Notes

- `while; do; norminette > norminette_results; sleep 5; done` for CLI refreshing norminette output... Probably useless if you have VS Code setup right.
- Tester that returns possibly useful debug thangs: https://github.com/xicodomingues/francinette (so much legacy 42 stuff online, a lot to sort through)
