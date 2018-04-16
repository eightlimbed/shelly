#include "../lib/shelly.h"
/**
 * get_path - Retrieves the PATH environment variable of a process.
 * Return: Pointer to the beginning of the value of $PATH.
 */
char *get_path(char **environ)
{
	unsigned int i, j, k;
	char *value;

	i = 0;
	while (environ[i] != NULL)
	{
		if (environ[i][0] == 'P' && environ[i][1] == 'A' && \
				environ[i][2] == 'T' && environ[i][3] == 'H' && \
				(environ[i][4] == '='))
		{
			value = malloc(sizeof(char) * PATH_MAX);
			k = 0;
			j = 5;
			while (environ[i][j] != '\0')
			{
				value[k] = environ[i][j];
				k++;
				j++;
			}
			value[k] = '\0';
			return (value);
		}
		i++;
	}
	return (NULL);
}
/**
 * split_path - Splits the PATH value on the ':' and returns an array of each
 * dir as a string
 * @path: Pointer to the value of PATH (char *)
 * Return: Pointer to an array of strings (char **)
 */
char **split_path(char *path)
{
	char **dirs;
	char *dir;
	unsigned int i = 0;
	const char *delim = ":";

	dirs = malloc(sizeof(char *) * PATH_MAX);
	if (dirs == NULL)
	{
		pstring("malloc() failed in split_path().\n");
		return (NULL);
	}
	dir = strtok(path, delim);
	while (dir != NULL)
	{
		dirs[i] = dir;
		i++;
		dir = strtok(NULL, delim);
	}
	dirs[i] = NULL;
	return (dirs);
}
/**
 * printenv - Prints all environment variables of a process
 * Return: void
 */
void printenv(void)
{
	unsigned int i = 0;

	while (environ[i] != NULL)
	{
		pstring(environ[i]);
		i++;
	}
}
