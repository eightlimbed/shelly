/**
 * exec_functions.c: contains functions related to fork and execution of
 * processes
 */
#include "../lib/shelly.h"
/**
 * run_cmd - Executes a command from the shell prompt
 * @tokens: pointer to buffer containing user input tokens (char **)
 * @child: process ID returned from fork() in main (pid_t)
 * Return: void
 */
void run_cmd(char **tokens, pid_t child)
{
	int status;

	if (child == -1)
	{
		pstring("Error in fork() in main\n");
		exit(EXIT_FAILURE);
	}
	else if (child == 0)
	{
		execve(tokens[0], tokens, NULL);
		/* execve will only return on failure */
		{
			pstring("Error in execve() in run_cmd().\n");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}

}
