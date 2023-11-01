# Directory for Simple Shell group Project

## Sudo code for the implementation
1. Initialize the Shell
   - Initialize data structures and variables.
   - Display a command prompt.

2. Read and Parse User Input
   - Read the user's input command line.
   - Tokenize the input to separate commands,
     arguments, and operators.

3. Handle Built-In Commands
   - Check if the entered command is a built-in shell command
   
   (e.g., "cd," "exit," "echo").
   - Execute built-in commands directly within the shell.

4. Search for the Executable
   - If the command is not built-in, search for the executable

     file in directories listed in the PATH environment variable.

5. Create a Child Process
   - If an executable is found, fork a child process

     to execute the command.
   - The child process loads the executable.

6. Redirection and Piping
   - Handle input/output redirection (<, >, >>) and

     piping (|) if present in the command.

7. Execute the Command
   - In the child process, use exec() functions

     to replace the child's memory image with the command's image.
   - Execute the external command in the child process.

8. Process Management
   - Handle foreground and background processes.
   - Manage process execution, including
     job control (e.g., fg, bg).

9. I/O Handling
   - Handle input and output streams for the command.
   - Redirect standard input and output if necessary.

10. Environment Variables
    - Manage environment variables, including setting,

      modifying, and using them.

11. Scripting
    - Support shell scripting by interpreting and

      executing shell scripts.

12. Customization
    - Allow users to customize their shell environment

      through configuration files.
    - Support shell startup files (e.g., .bashrc, .bash_profile).

13. Error Handling
    - Handle errors gracefully, display error messages to the user.

14. Cleanup
    - Properly release resources, close files, and

       wait for child processes to complete.

15. Repeat
    - Return to the command prompt and wait for the

      next user input.

16. Termination
    - Handle the "exit" command or a specific exit
      
      condition to exit the shell.

17. Cleanup and Shutdown
    - Perform any necessary cleanup before exiting the shell.

18. Final Exit
    - Terminate the shell.

