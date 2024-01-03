# Get Next Line

## Build and debug

### VS Code

You can build and debug directly in VS Code using the  regular VS Code Debug tab. Currently this is configured to only run `get_next_line_bonus`. We may have to setup a `Makefile` or similar to make it work for both (C function names must be unique). 

### XCode

Additionally, you cand build and debug in XCode (which gives some REALLY interesting results) with the provided project (42_get_next_line), but probably isn't currently configured to compile with both `get_next_line` and `get_next_line_bonus` in the file tree.

### Command line (GCC or Clang)

```
gcc -g get_next_line_bonus/*.c *.c -o get_next_line_bonus
gcc -g get_next_line/*.c *.c -o get_next_line
gcc -g -Wall -Wextra -Werror -D BUFFER_SIZE=1098098 get_next_line_bonus/*.c *.c -o get_next_line_bonus

clang -g get_next_line_bonus/*.c *.c -o get_next_line_bonus
clang -g get_next_line/*.c *.c -o get_next_line
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=1098098 get_next_line/*.c *.c -o get_next_line
```

# Notes

Tester that returns possibly useful debug thangs: https://github.com/xicodomingues/francinette
