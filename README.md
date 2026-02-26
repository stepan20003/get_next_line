# 📘 get_next_line

## 📌 Description

`get_next_line` is a function that reads a file descriptor line by line.

Each call returns:
- The next line from the file descriptor
- Including the newline `\n` (if present)
- NULL when EOF or error occurs

This project is part of the 42 curriculum.

---

## 🧠 Prototype

```c
char *get_next_line(int fd);#include <fcntl.h>
#include <stdio.h>

int main()
{
    int fd = open("file.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
}cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c

