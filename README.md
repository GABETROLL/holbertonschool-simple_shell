# Holberton Simple Shell

The Holberton Simple Shell (hsh) is a project assign as part of Holberton School's curriculum. Basically, the hsh is a command language interpreter that execute commands from a command line string, the standard input, or a specified file. It handle the PATH.

## Project Requirements

The project requires complete the following 7 task:

	* Task 0 - Write a README, Write a man for your shell & AUTHOR file.

	* Task 1 - Write a beautiful code that passed the Betty checks

	* Task 2 - Write a UNIX command line interpreter.

	* Task 3 - Handle command lines with arguments

	* Task 4 - Handle the PATH, fork must not be called if the command doesnt exist

	* Task 5 - Implement the exit built-in, that exits the shell

	* Task 6 - Implement the env built-in, that prints the current enviorment

## Project Documentation

### Files Description

	* README.md - File that contains information, instructions and details for the user about the project. THIS FILE!

	* AUTHORS - File that contains the name and email of project's authors.

	* man_1_simple shell - Manual page created to help users understand how to uses our project.

	* main.h - File that contains all functions declarations and macro definitions.

	* main.c - File that contains the primary function, serves as the starting point of our program.

	* token.c - File that contains the function that creates and returns an array of pointers.

	* special_cases.c - File that handle the built-ins.

	* create_fork.c - File that create another process, execute command and print error message.

	* get_path.c - File that handle the PATH.

	* strings.c - File that contains all the string functions created and used for the project (except for comparison).

	* str_cmp.c - File that contains all the compare string functions created and used for the project.

### Installation

***Clone the repo**(in the desired directory)*
```
git clone git@github.com:GABETROLL/holbertonschool-simple_shell.git
```
***Move to the repo's directory***
```
cd holbertonschool-simple_shell/
```
***Compile it***
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

### Usage

The hsh can be used in two modes: interactive and non-interactive.

##### Interactive Mode
  
  The interactive mode takes commands as input from the user and acknowledges the output to the user. In order to use hsh in interactive mode, need to run th executable program.

```
./hsh
```

##### Non-Interactive Mode
  
  The non-interactive mode is a type of shell that doesnt interact with the user. In order to use hsh in a non-interactive mode, need to pass the command and arguments to the executable program.

```
echo [command] [arguments...] | ./hsh
```

##### Built-Ins
  
  A built-in is a command or function called from hsh that is executed in the program itself.

```
- env - This will display curent environment.

- exit - This will close the prompt and get you back to the original shell.

- ctrl - d - This represent EOF(end of files), and it will exit the prompt and return you to the original shell.
```
### Examples:

##### Interactive Mode (using ls command)
```
username@original-prompt:~$ ./hsh
$ ls
env-main.c  exec.c  fork.c  pid.c  ppid.c    prompt   prompt.c  shell_0.3  stat    test_scripting.sh  wait.c
env-environ.c  exec    fork    mypid   ppid   printenv  promptc  shell     shell.c    stat.c  wait
$ exit
username@original-prompt:~$
```
#### Non-Interactive Mode (using ls command)
```
username@original-prompt:~$ echo "ls" | ./hsh
env-main.c  exec.c  fork.c  pid.c  ppid.c    prompt   prompt.c  shell_0.3  stat    test_scripting.sh  wait.c
env-environ.c  exec    fork    mypid   ppid   printenv  promptc  shell     shell.c    stat.c  wait
username@original-prompt:~$
```
### Bugs
At the moment the hsh return value is always 0, exit usual codes do not apply.

- Pressing ``Ctrl+c`` to exit the shell causes one memory leak of 1,144 bytes.
## Authors
### Gabriel Fernandez
- [GitHub](https://github.com/GABETROLL/)
- [LinkedIn](https://www.linkedin.com/in/gabriel-fernandez-415609278/)
- [X](https://twitter.com/gabe_programs)
- [My Portfolio Project](https://github.com/GABETROLL/Tetris3D/)

#### Gabriel - Building this project
At first, I wanted to take over the main structure of the code, but Rafael did a pretty good job on that. The project listed A LOT of builtin C syscalls we could use, and I moved on with trying to understand what the syscalls that Rafael was using did. After a lot of the project was done, I moved on to try to catch as many memory leaks as I could, but ended up not being able to catch them all.
##### Gabriel - Biggest Challenges
- Understanding what the syscalls do
- Learning to be a good teammate
- Understanding and using ``strtok``
- Catching memory leaks
- The stress of knowing this was a very challenging project

### Rafael O. Vega Rodriguez
[GitHub](https://github.com/rvegarodz/)
