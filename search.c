#include "monty.h"
/**
 * _saach - search if a char is inside a string
 * @s: string to check
 * @c: char to find
 * Return: 1 if success 0 if not
 */
int _saach(char *s, char c)
{
	int len = 0;

	do {
		if (s[len] == c)
		{
			break;
		}
		len++;
	} while (s[len] != '\0');

	if (s[len] == c)
		return (1);
	else
		return (0);
}
