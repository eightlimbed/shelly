/**
 * strings_functions.c: contains functions related to strings
 */
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
