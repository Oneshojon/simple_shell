#ifndef SHELL_H
#define SHELL_H
#define _GNU_SOURCE

#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <ctype.h>
#include <errno.h>


/**** Printer ****/
void _puts(char *ptr);
void printError(char *ptr);
void _putchar(char c);


/*** UTILITIES! **/
unsigned int _strlen(char *str);
char *_strdup(char *str);
int _strcmp(const char *str1, const char *str2);
void *_realloc(void *ptr, size_t size);

/***PID****/
void get_ppid(void);

/** PROMPT **/
void display_prompt(void);
/** FREE  **/
void free_words(char **words, int count);
void free_environment_array(char **envp);

/**   ARGUMENTS   **/
int print_args(int ac, char **av);
char *read_line(void);
char **split_string(char *input, const char *delimiter);
char **split_string2(char *str);
char *trim_spaces(char *str);


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
char *check_executable(char **argv);
/**  env/PATH  **/
#define PATH_MAX 4096
extern char **environ;
char *find_executable(const char *filename);
int file_exists(int argc, char *argv[]);
int env_main(int ac, char **av);
char *_getenv(const char *name);
int extern_vs_main(int ac, char **av, char **env);
int extern_env(void);
void dir_in_path(void);
char **get_environment_array(void);
/**   STRUCT FOR LINKED LIST   **/
typedef struct linkeddict
{
	char *dir;
	struct linkeddict *next;
} linkedd1;
linkedd1 *createNode(const char *dir);
void insertNode(linkedd1 **head, const char *dir);
void printList(linkedd1 *head);
int main2(void);


#endif
