/**
 * exec_functions.c: contains functions related to fork and execution of
 * processes
 */
#include "../lib/shelly.h"
/**
 * run_cmd - Executes a command from the shell prompt
 * @tokens: pointer to buffer containing user input tokens (char **)
 * @child: process ID returned from fork() in main (pid_t)
 * Return: 0 if token[0] is "exit", 1 otherwise
 */
int run_cmd(char **tokens, pid_t child)
{
	int status;
	char *cmd;
	char *path;
	char **dirs;

	if (child == -1)
	{
		pstring("Error in fork() in main\n");
		exit(EXIT_FAILURE);
	}
	else if (child == 0)
	{
		/* try to find tokens[0] in PATH */
		path = get_path(environ);
		dirs = split_path(path);
		cmd = search_path(dirs, tokens[0]);
		if (cmd == NULL && scompare(tokens[0], "exit") != 0)
		{
			printf("command not found: %s\n", tokens[0]);
			return (1);
		}
		if (cmd)
			execve(cmd, tokens, NULL);
		/* check if tokens[0] is a builtin ("exit", or "env") */
		if (scompare(tokens[0], "exit") == 0)
		{
			return (0);
		}
		else if (scompare(tokens[0], "env") == 0)
		{
			printf("in hurr\n");
			printenv();
		}
		else
		/* execve will only return on failure */
		pstring("Error in execve() in run_cmd().\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&status);
		free(tokens);
	}
	return (1);
}
/**
 * search_path - searches the PATH environment variable for a valid command
 * @dirs: pointer to an array of directories in PATH (char **)
 * @cmd: pointer to cmd name (char *)
 * Return: pointer to full pathname of cmd, if found, or NULL if not found
 */
char *search_path(char **dirs, char *cmd)
{
	struct stat sb;
	char *fullcmd;
	unsigned int i = 0;

	while (dirs[i] != NULL)
	{
		fullcmd = catpath(dirs[i], cmd);
		if (stat(fullcmd, &sb) == 0)
			return (fullcmd);
		i++;
	}
	return (dirs[i]);
}
