*This project has been created as part of the 42 curriculum by mohassaf.*

# pipex

## Description

`pipex` is a 42 project that recreates shell-style piping in C.
The goal is to understand how Unix processes communicate through pipes, how file
descriptors are redirected with `dup2`, and how commands are executed with
`fork`, `execve`, `waitpid`, and the `PATH` environment variable.

The mandatory part reproduces:

< infile cmd1 | cmd2 > outfile

The bonus part extends this behavior with:

- multiple chained commands
- `here_doc` support
- append mode for `here_doc`


## Features

- Mandatory binary: `./pipex`
- Bonus binary: `./pipex`
- Supports commands found through `PATH`
- Supports commands given with absolute or relative paths
- Returns the exit status of the last command
- Handles invalid commands and missing files
- Supports multiple pipes in the bonus part
- Supports `here_doc LIMITER cmd1 cmd2 ... outfile`

## Instructions

### Compilation

Build the mandatory part:

`make`

Build the bonus part:

`make bonus`

Clean object files:

`make clean`

Clean everything:

`make fclean`

Rebuild from scratch:

`make re`

### Mandatory execution

Syntax:

./pipex infile "cmd1" "cmd2" outfile

Example:

./pipex infile "grep hello" "wc -l" outfile

Equivalent shell behavior:

< infile grep hello | wc -l > outfile

### Mandatory part examples

Example 1:
./pipex infile "cat" "wc -l" outfile

Equivalent shell:
< infile cat | wc -l > outfile

Example 2:
./pipex infile "grep 42" "wc -w" outfile

Equivalent shell:
< infile grep 42 | wc -w > outfile

Example 3:
./pipex infile "/bin/cat" "/usr/bin/wc -c" outfile

Equivalent shell:
< infile /bin/cat | /usr/bin/wc -c > outfile

Example 4:
./pipex infile "awk \"{print \$1}\"" "sort" outfile

Equivalent shell:
< infile awk '{print $1}' | sort > outfile

Example 5:
./pipex infile "doesnotexist" "cat" outfile

Equivalent shell:

< infile doesnotexist | cat > outfile


### Bonus execution

Syntax with multiple commands:

./pipex infile "cmd1" "cmd2" "cmd3" ... outfile

Example:
./pipex infile "cat" "grep hello" "wc -l" outfile

Equivalent shell behavior:
< infile cat | grep hello | wc -l > outfile

### Bonus evaluator examples

Example 1:
./pipex infile "cat" "grep 42" "wc -l" outfile

Equivalent shell:
< infile cat | grep 42 | wc -l > outfile

Example 2:
./pipex infile "sort" "uniq" "wc -l" outfile

Equivalent shell:
< infile sort | uniq | wc -l > outfile

Example 3:
./pipex infile "cat" "tr a-z A-Z" "rev" "cat -e" outfile

Equivalent shell:
< infile cat | tr a-z A-Z | rev | cat -e > outfile

Example 4:
./pipex infile "grep hello" "doesnotexist" "wc -c" outfile

Equivalent shell:
< infile grep hello | doesnotexist | wc -c > outfile

### Here_doc execution

Syntax:

./pipex_bonus here_doc LIMITER "cmd1" "cmd2" outfile

Equivalent shell behavior:
cmd1 << LIMITER | cmd2 >> outfile

./pipex here_doc EOF "cat" "wc -l" outfile

Equivalent shell:
cat << EOF | wc -l >> outfile

In `here_doc` mode, the output file is opened in append mode instead of truncate
mode.

## Resources

Classic references used to understand the topic:

- `man pipe`
- `man fork`
- `man dup2`
- `man execve`
- `man waitpid`
- `man open`
- The Linux Programming Interface, Michael Kerrisk
- Beej's Guide to Unix IPC
- 42 subject and peer discussions

AI usage for this project:

- AI was used to help review the project after implementation
- AI was used to suggest additional test cases for mandatory and bonus behavior
- AI was used to help identify and verify a leak in bonus child failure paths
- AI was used to draft and polish this `README.md`

The core project remains a C implementation of `pipex` and `pipex_bonus`
focused on Unix system calls, process control, and file descriptor management.

To test the code, I used this repo: https://github.com/michmos/42_pipex_tester.git
