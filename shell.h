#ifndef SHELL_H
#define SHELL_H
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <fcntl.h>
#include <stdio.h>

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
int read_line(void);
char **split_string(const char *input, const char *delimiter, int *word_count);
char **split_string2(char *str);

/** EXECUTIION OF PROGRAM **/


#endif
