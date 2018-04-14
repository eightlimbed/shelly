/**
 * print_functions.c: contains functions related to printing to stdout
 */
#include "../lib/shelly.h"
/**
 * pchar - prints a single character to stdout
 * @c: char to print (const char)
 * Return: 0 on success, -1 on failure or EOF
 */
int pchar(const char c)
{
	return (write(1, &c, 1));
}
/**
 * pstring - prints a string a characters to stdout
 * @str: pointer to an array of chars (const char *)
 * Return: number of characters printed (int)
 */
int pstring(const char *str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		pchar(str[i]);
		i++;
	}
	return (i);
}
