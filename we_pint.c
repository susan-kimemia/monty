#include "monty.h"

/**
 * __addingNode - add a node to a doubly linked list
 * @head: head of list
 * @n: new data to add
 * Return: pointer to newly added node
 */

stack_t *__addingNode(stack_t **head, int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		__freeGrid(opcode_read);
		__freeList(*head);
		exit(EXIT_FAILURE);
	}
	new_node->prev = NULL;
	new_node->n = (int)n;

	new_node->next = *head;
	if (*head != NULL)
		(*head)->prev = new_node;
	*head = new_node;
	return (*head);
}

/**
 * _stackLen - counts the number of nodes in a double linked list
 * @head: list head
 * Return: number nodes
 */

size_t _stackLen(stack_t *head)
{
	stack_t *current = head;
	size_t i = 0;

while (current != NULL)
{
if (i > 2)
{
break;
}
i++;
current = current->next;
}

return (i);
}
