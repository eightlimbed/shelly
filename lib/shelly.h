#ifndef shelly_h
#define shelly_h
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>
#define PATH_MAX 512
#define TOKEN_MAX 64
extern char **environ;
int pchar(const char c);
int pstring(const char *str);
void strip_line(char *str);
unsigned int slen(char *str);
char **get_tokens(char *line);
int run_cmd(char **tokens, pid_t child);
char *get_path(char **environ);
char **split_path(char *path);
char *catpath(char *dir, char *cmd);
char *search_path(char **dirs, char *cmd);
unsigned int scompare(char *s1, char *s2);
void printenv(void);
#endif
