/**
 * parsing_functions.c: contains functions related to parsing shell input
 */
#include "../lib/shelly.h"
/**
 * strip_line - Parses `line` from `getline()` in main.c to get rid of the
 * trailing newline.
 * @line: pointer to buffer containing user input (char *)
 * Return: pointer to new line, or NULL if malloc() failed.
 */
void strip_line(char *str)
{
	unsigned int i = 0;

	while (str[i] != '\n')
		i++;
	str[i] = '\0';
}
/**
 * get_tokens - Parses `line` from `getline()` to create tokens for `execve`.
 * @line: pointer to buffer containing user input (char *)
 * Return: pointer to an array of strings (char **), or NULL if malloc() failed.
 */
char **get_tokens(char *line)
{
	char **tokens;
	char *token;
	unsigned int i = 0;
	const char *delim = " \t";

	tokens = malloc(sizeof(char *) * 10);
	if (tokens == NULL)
	{
		pstring("malloc() failed in get_tokens().\n");
		return (NULL);
	}
	token = strtok(line, delim);
	while (token != NULL)
	{
		tokens[i] = token;
		i++;
		token = strtok(NULL, delim);
	}
	tokens[i] = NULL;
	return (tokens);
}
