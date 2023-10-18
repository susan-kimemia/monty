#include "monty.h"

/**
 * push - push integer to the top of the stack
 * @head: pointer to stack head
 * @operand: integer to push
 * @lineNamba: command line number
 */

void push(stack_t **head, char *operand, unsigned int lineNamba)
{
	if (!__isNamba(operand))
	{
		fprintf(stderr, "L%d: usage: push integer\n", lineNamba);
		__freeGrid(opcode_read);
		__freeList(*head);
		exit(EXIT_FAILURE);
	}
	__addingNode(head, atoi(operand));
}

/**
 * pint - print integer top element of the stack
 * @head: pointer to stack head
 * @lineNamba: command line number
 */

void pint(stack_t **head, unsigned int lineNamba)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", lineNamba);
		__freeGrid(opcode_read);
		__freeList(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

/**
 * pop - removes element from the top of the stack
 * @head: pointer to stack head
 * @lineNamba: command line number
 */

void pop(stack_t **head, unsigned int lineNamba)
{
	if (__deleteNode(head, 0) == -1)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n",
				lineNamba);
		__freeGrid(opcode_read);
		__freeList(*head);
		exit(EXIT_FAILURE);
	}
}
