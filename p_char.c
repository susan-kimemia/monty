#include "monty.h"

/**
 * p_char - prints the character at the top of the stack
 * @head: head of the linked list
 * @line_num: line number
 * Return: void
 */
void p_char(stack_t **head, unsigned int line_num)
{
	(head == NULL || *head == NULL) ? (
	fprintf(stderr, "L%u: can't pchar, stack empty\n", line_num),
	free_glovar(),
	exit(EXIT_FAILURE)
	) : (void)0;

	if ((*head)->n < 0 || (*head)->n >= 128)
	{
	fprintf(stderr, "L%u: can't pchar, value out of range\n", line_num);
	free_glovar();
	exit(EXIT_FAILURE);
	}
	printf("%c\n", (*head)->n);
}

