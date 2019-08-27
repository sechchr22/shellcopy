#ifndef HEADER_FILE
#define HEADER_FILE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <signal.h>
extern char **environ;
int _getchar(void);
ssize_t _getline(char **linep, ssize_t *line_size, FILE *stream);
void sig_handler(int signal);
void myshell_loop(void);
char *read_command(void);
char **split_into_arguments(char *line);
int myshell_execute(char **args);
int myshell_external(char **args);
int myshell_cd(char **args);
int myshell_exit(char **args);
char *_getenv(const char *name);
char **split_path(char *path);
int _execv(char *path, char **args);
char *_strcpy(char *dest, char *src);
#endif
