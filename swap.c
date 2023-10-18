#include "monty.h"

/**
 * _we_swap - swaps the top two elements of the stack
 *
 * @head: head of the linked list
 * @line_num: line number
 * Return: void
 */
void _we_swap(stack_t **head, unsigned int line_num)
{
	int i = 0;
	stack_t *temp = NULL;

	temp = *head;

	while (temp != NULL)
	{
	temp = temp->next;
	i++;
	}

	(i < 2) ? (
	fprintf(stderr, "L%u: can't swap, stack too short\n", line_num),
	free_glovar(),
	exit(EXIT_FAILURE)
	) : (void)0;

	temp = *head;
	*head = (*head)->next;
	temp->next = (*head)->next;
	temp->prev = *head;
	(*head)->next = temp;
	(*head)->prev = NULL;
}
