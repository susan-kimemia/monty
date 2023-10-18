#include "monty.h"

/**
 * _subtract - subtracts the top element of the stack from
 * the second top element of the stack
 * @head: head of the linked list
 * @line_num: line number
 * Return: void
 */
void _subtract(stack_t **head, unsigned int line_num)
{
	int i = 0;
	stack_t *temp = NULL;

	temp = *head;

	while (temp != NULL)
	{
	temp = temp->next;
	i++;
	}

if (i < 2)
{
fprintf(stderr, "L%u: can't sub, stack too short\n", line_num);
free_glovar();
exit(EXIT_FAILURE);
}

	temp = (*head)->next;
	temp->n -= (*head)->n;
	_pop(head, line_num);
}
