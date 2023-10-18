#include "monty.h"
/**
 * __deleteNode - deletes a node at specified index
 * @head: pointer to first node
 * @index: node position
 * Return: 1 on success otherwise -1
 */
int __deleteNode(stack_t **head, unsigned int index)
{
	stack_t *current, *temp;
	unsigned int i = 0;

	current = *head;
	if (*head == NULL)
		return (-1);
	if (index == 0)
	{
		if ((*head)->next != NULL)
		{
			temp = (*head)->next;
			free(*head);
			*head = temp;
			(*head)->prev = NULL;
			return (1);
		}
		if ((*head)->next == NULL)
		{
			free(*head);
			*head = NULL;
			return (1);
		}
	}

while (current)
{
if (i == index && current->next != NULL)
{
current->prev->next = current->next;
free(current);
current = NULL;
return (1);
}
current = current->next;
i++;
}
	return (-1);
}
