#include "monty.h"

/**
 * _divide - divides the 2nd top element of the stack
 * by the top element of the stack
 * @head: head of the linked list
 * @line_num: line number
 * Return: void
 */
void _divide(stack_t **head, unsigned int line_num)
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
fprintf(stderr, "L%u: can't div, stack too short\n", line_num);
free_glovar();
exit(EXIT_FAILURE);
}

if ((*head)->n == 0)
{
fprintf(stderr, "L%u: division by zero\n", line_num);
free_glovar();
exit(EXIT_FAILURE);
}
	temp = (*head)->next;
	temp->n /= (*head)->n;
	_pop(head, line_num);
}
