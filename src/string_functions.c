#include "../lib/shelly.h"
/**
 * slen - Counts the number of characters in a string
 * @str: pointer to an array of chars (char *)
 * Return: number of characters in str (unsigned int)
 */
unsigned int slen(char *str)
{
	unsigned int i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}
/**
 * catpath - Concatenates a command (tokens[0]) to each directory of a path in
 * order to find and execute the command in the user's PATH, if found.
 * @dir: pointer to a one of the dirs in PATH
 * @cmd: the command a user entered (char *)
 * Return: a pointer to a string consistening of dir + cmd, or NULL on failure
 */
char *catpath(char *dir, char *cmd)
{
	char *catpath;
	unsigned int dirlen, cmdlen, len;
	unsigned int i, j;

	dirlen = slen(dir);
	cmdlen = slen(cmd);
	len = dirlen + cmdlen;
	catpath = malloc(sizeof(char) * len + 1);
	if (catpath == NULL)
	{
		pstring("malloc() failed in catpath().\n");
		return (NULL);
	}
	i = 0;
	while (dir[i] != '\0')
	{
		catpath[i] = dir[i];
		i++;
	}
	catpath[i] = '/';
	i++;
	j = 0;
	while (cmd[j] != '\0')
	{
		catpath[i] = cmd[j];
		j++;
		i++;
	}
	catpath[i] = '\0';
	return (catpath);
}
/**
 * scompare - Compares two strings to check if they are the same
 * @s1: pointer to string 1 (char *)
 * @s2: pointer to string 2 (char *)
 * Return: 0 if "identical", 1 if not.
 */
unsigned int scompare(char *s1, char *s2)
{
	unsigned int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (1);
	}
	return (0);
}
