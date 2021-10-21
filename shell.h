#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>

#define END_OF_FILE -2
#define EXIT -3

extern char **environ;
char *name;
int hist;

/**
 * struct params - object with all variables
 * @argv: arguments
 * @found: used to find files with stat
 * @cmd: cmd = path + argument
 * @loop: number of times prompt will be shown
 * @buff: used with getline()
 * @name: name of the params
 * @exit_value: return int
 */

typedef struct params
{
	char **argv;
	struct stat found;
	char *cmd;
	int *loop;
	char *buff;
	char *name;
	int exit_value;
} params;

/* Main functions */
int check_builtin(params *p);
void not_found_error(params *p);
void simple_exec(params *p);

/* Auxiliar Functions */
void signal_exit(int a);
void *_calloc(uint nmemb, uint size);

/* Path Functions */
char *_getenv(char *name);
char *cmd_path(char **argv);

/* String Functions 1 */
char *_strcat(char *dest, char *src);
int _strlen(char *s);
void rev_string(char *s);
char *_itoa(uint num);
int _strcmp(char *s1, char *s2);

/* String Functions 2 */
char *_strchr(char *s, char c);
char *_strcpy(char *dest, char *src);
char *str_concat(char *s1, char *s2);
int _atoi(char *s);

/* Built-in Functions */
int check_word(char **argv);
int exit_built_in(params *p);
void env_built_in(params *p);

#endif
