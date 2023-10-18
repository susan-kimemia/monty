#include "monty.h"

/**
 * _let_opcode - gets and executes opcode
 * @head: pointer to list head
 * @lineNamba: command line number
 * Return: void
 */
void _let_opcode(stack_t **head, unsigned int lineNamba)
{
	int lyn = 0;
	instruction_t opcodes[] = {
		{"nop", nop}, {"pall", pall},
		{"pint", pint}, {"swap", swap},
		{"pop", pop}, {"add", add}, {"__pstr", __pstr},
		{"sub", sub}, {"div", _div}, {"__pchar", __pchar},
		{"mul", mul}, {"mod", mod},
		{"rotl", rotl}, {"rotr", rotr}, {"stack", stack}};

	while (lyn < 15)
	{
		if (strcmp((const char *)opcode_read[0], "push") == 0)
		{
			if (!opcode_read[1])
			{
				fprintf(stderr, "L%d: usage: push integer\n", lineNamba);
				__freeGrid(opcode_read);
				__freeList(*head);
				exit(EXIT_FAILURE);
			}
			push(head, opcode_read[1], lineNamba);
			return;
		}
		if (strcmp((const char *)opcode_read[0],
					(const char *)opcodes[lyn].opcode) == 0)
		{
			opcodes[lyn].f(head, lineNamba);
			return;
		}
		lyn++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", lineNamba, opcode_read[0]);
	__freeList(*head);
	__freeGrid(opcode_read);
	exit(EXIT_FAILURE);
}
