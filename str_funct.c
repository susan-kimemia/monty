#include "monty.h"

/**
 * _strcmp - compares two strings.
 * @s1: first string
 * @s2: second string
 * Return: 0 if s1 and s2 are equals, another value if they
 * are different
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i] && s1[i]; i++)
		;
	if (s1[i] > s2[i])
		return (1);
	if (s1[i] < s2[i])
		return (-1);
	return (0);
}

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

/**
 * str_tok - function that cut a string into tokens depending of the delim
 * @s: string to be tokenized
 * @d: delimiters
 * Return: first partition
 */
char *str_tok(char *s, char *d)
{
	static char *last_token;
	int i = 0, j = 0;

	if (!s)
		s = last_token;

	do {
		if (_saach(d, s[i]) == 0 && s[i + 1] == '\0')
		{
			last_token = s + i + 1;
			*last_token = '\0';
			s = s + j;
			return (s);
		}
		else if (_saach(d, s[i]) == 0 && _saach(d, s[i + 1]) == 0)
			i++;
		else if (_saach(d, s[i]) == 0 && _saach(d, s[i + 1]) == 1)
		{
			last_token = s + i + 1;
			*last_token = '\0';
			last_token++;
			s = s + j;
			return (s);
		}
		else if (_saach(d, s[i]) == 1)
		{
			j++;
			i++;
		}
	} while (s[i] != '\0');
	return (NULL);
}
