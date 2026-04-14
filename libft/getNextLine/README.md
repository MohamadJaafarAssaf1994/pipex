*This project has been created as part of the 42 curriculum by mohassaf.*

# get_next_line

## Description

**get_next_line** is a C programming project whose goal is to implement a function
that reads a file descriptor line by line and returns each line on successive calls.

The function must handle:
- Files of any size
- Any `BUFFER_SIZE`
- Multiple file descriptors simultaneously (bonus)
- End-of-file and read errors correctly
- Proper memory management with no leaks

This project strengthens understanding of:
- Static variables
- File descriptors
- Low-level I/O (`read`)
- Dynamic memory allocation
- Robust error handling

---

## Instructions

### Function Prototype

char *get_next_line(int fd);

### Compilation
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
get_next_line.c get_next_line_utils.c

### Usage Example
#include "get_next_line.h"
#include <fcntl.h>

int main(void)
{
	int		fd;
	char	*line;

	fd = open("file.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
### Algorithm Explanation and Justification
The selected algorithm is based on incremental buffered reading combined with a
static memory stash.

Core Principles

Buffered Reading

Data is read in chunks of size BUFFER_SIZE

This avoids reading the entire file into memory at once

Static Stash

A static variable stores leftover data between calls

This allows the function to continue reading from where it stopped

Line Extraction

Each call extracts characters up to the first \n

The remaining content is kept for the next call

End-of-File Handling

If EOF is reached and the stash contains data, it is returned as the last line

Subsequent calls return NULL

Error Handling

If read() returns -1, the stash is cleared and NULL is returned

Prevents undefined behavior in future calls

Bonus (Multiple File Descriptors)

An array of static pointers indexed by file descriptor is used

Each file descriptor maintains its own independent stash

## Resources
### Technical References

Linux read() manual
https://man7.org/linux/man-pages/man2/read.2.html

File descriptors overview
https://man7.org/linux/man-pages/man2/open.2.html

Static variables in C
https://en.cppreference.com/w/c/language/storage_duration

42 get_next_line subject (official documentation)

### AI Usage Disclosure

AI tools were used only as an assistance during the development of this project:

To review logic and identify edge cases

To explain segmentation faults and memory issues

To help restructure functions to respect Norminette constraints

To assist in drafting this README

