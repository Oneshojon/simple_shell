#ifndef SHELL_H
#define SHELL_H
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/**** Printer ****/
void _puts(char *ptr);
void printError(char *ptr);
void _putchar(char c);


/*** UTILITIES! **/
unsigned int _strlen(char *str);
char *_strdup(char *str);

/***PID****/
void get_ppid(void);

/** PROMPT **/
void display_prompt(void);

/**   ARGUMENTS   **/
int print_args(int ac, char **av);
char *read_line(void);
char **split_string(char *input, const char *delimiter, int *word_count);
char **split_string2(char *str);

/** GETLINE.C **/
ssize_t _getline(char **ptr, size_t n, FILE *stream);
char *read_file(FILE *stream);

/** EXECUTIION OF PROGRAM **/
int exec_program(void);
int create_process(void);
int child_father_pid(void);
int exec_5x(void);
int wait_father(void);
int execute(char *argv[]);
/**  env/PATH  **/
#define PATH_MAX 4096
char *find_executable(const char *filename);
int file_exists(int argc, char *argv[]);
int env_main(int ac, char **av);


#endif
