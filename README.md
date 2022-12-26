# Project-2-Get_Next_Line

The second project of Codam is Get Next line.
The aim is to write a function that returns a line read from a file descriptor. I tried to read as little as possible each time get_next_line() is called.
Don’t read the whole file and then process each line.

Lessons learned are: proper buffer management, FD's and static variables.

You can compile the project by cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 *.c
The buffer size is dynamic.
