#include "monty.h"

char **opcode_read = NULL;

/**
 * trim - removes leading / trailing white spaces
 * @len: Num of chars read
 * @trimmed_line: buffer to line trimmed
*/
void trim(char **trimmed_line, size_t *len)
{
	while (**trimmed_line == ' ' || **trimmed_line == '\t' ||
			**trimmed_line == '\n')
	{
		(*trimmed_line)++;
	}

	*len = strlen(*trimmed_line);
	while (*len > 0 && ((*trimmed_line)[*len - 1] == ' ' ||
	(*trimmed_line)[*len - 1] == '\t' || (*trimmed_line)[*len - 1] == '\n'))
	{
		(*trimmed_line)[*len - 1] = '\0';
		*len = *len - 1;
	}
}

/**
 * execute_op - reads and execute opcode
 * @file: file  stream
 * @head: pointer to list head
 */

void execute_op(FILE *file, stack_t **head)
{
	char line[1024];
	char ***argv = &opcode_read, *trimmed_line;
	unsigned int lineNamba = 0;
	size_t len = 0;

	while (fgets(line, sizeof(line), file) != NULL)
	{

		trimmed_line = line;
		trim(&trimmed_line, &len);

		/* Check if the line is empty or starts with a '#' character */
		if (len == 0 || trimmed_line[0] == '#')
			continue;

		*argv = __tokenize(trimmed_line, DELIM);
		if (*argv == NULL)
		{
			/* Cleanup before leaving */
			fprintf(stderr, "Error: malloc failed\n");
			__freeGrid(*argv);
			__freeList(*head);
			fclose(file);
			exit(EXIT_FAILURE);
		}
		lineNamba++;
		_let_opcode(head, lineNamba);
		__freeGrid(*argv);
	}
	if (!*head)
		return;
	__freeList(*head);
}

/**
 * main - entry point
 * @ac: number of command line argument
 * @argv: arguments passed
 * Return: Exit status
 */

int main(int ac, char **argv)
{
	stack_t *head = NULL;
	FILE *file;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r+");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	execute_op(file, &head);
	fclose(file);
	return (EXIT_SUCCESS);
}
