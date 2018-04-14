#ifndef shelly_h
#define shelly_h
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
int pchar(const char c);
int pstring(const char *str);
void strip_line(char *str);
unsigned int slen(char *str);
char **get_tokens(char *line);
void run_cmd(char **tokens, pid_t child);
#endif
