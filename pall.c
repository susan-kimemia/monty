#include "monty.h"

/**
 * pall - print all integer on top of the stack
 * @head: pointer to stack head
 * @lineNamba: command line number
 */
void pall(stack_t **head, unsigned int lineNamba)
{
	stack_t *current;

	current = *head;

	(void)lineNamba;
	if (current == NULL)
		return;
while (current != NULL)
{
printf("%d\n", current->n);
current = current->next;
}
}
