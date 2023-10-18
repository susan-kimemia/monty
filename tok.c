#include "monty.h"

/**
 * __tokenize - __tokenizes a stream of characters
 * @str: string to __tokenize
 * @delim: delimiter
 * Return: array to tokens
 */
char **__tokenize(char *str, const char *delim)
{
	char **words;
	char *dup, *tok;
	int i = 0, nambaTok = 0;

	if (str == NULL || *str == '\0')
		return (NULL);
	dup = malloc(sizeof(char) * strlen(str) + 1);
	if (dup == NULL)
		return (NULL);
	strcpy(dup, str);
	tok = strtok(str, delim);

	do {
		if (tok[0] == '#')
			break;
		nambaTok++;
		tok = strtok(NULL, delim);
	} while (tok != NULL);
	nambaTok++;
	words = malloc(sizeof(char *) * nambaTok);
	if (words == NULL)
		return (NULL);
	tok = strtok(dup, delim);
	do {
		if (tok[0] == '#')
			break;
		words[i] = malloc(sizeof(char) * strlen(tok) + 1);
		strcpy(words[i], tok);
		tok = strtok(NULL, delim);
		i++;
	} while (tok != NULL);

	words[i] = NULL;
	free(dup);
	return (words);
}
