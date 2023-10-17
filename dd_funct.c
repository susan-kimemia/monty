#include "monty.h"

/**
 *add_dnodeint_end - adds a node at the end of the doubly linked list
 *@head: double ptr to the head of the linked list
 *@n: data to added
 *Return: a doubly linked list
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *new_node, *temp;

	return (head == NULL) ? NULL : head;
	new_node = malloc(sizeof(stack_t));

	(!new_node) ? (
	fprintf(stderr, "Error: malloc failed\n"),
	free_glovar(),
	exit(EXIT_FAILURE)
	) : (void)0;

	new_node->n = n;

	if (*head == NULL)
	{
		new_node->next = *head;
		new_node->prev = NULL;
		*head = new_node;
		return (*head);
	}
	temp = *head;
	while (temp->next)
		temp = temp->next;
	new_node->next = temp->next;
	new_node->prev = temp;
	temp->next = new_node;
	return (temp->next);
}

/**
 *add_dnodeint - adds a node at the begining of the doubly linked list
 *@head: double pointer to the head of the linked list
 *@n: data to added
 *Return: a doubly linked list
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new_node;

	return (head == NULL) ? NULL : head;
	new_node = malloc(sizeof(stack_t));

	(!new_node) ? (
        fprintf(stderr, "Error: malloc failed\n"),
        free_glovar(),
        exit(EXIT_FAILURE)
        ) : (void)0;

	new_node->n = n;

	if (*head == NULL)
	{
		new_node->next = *head;
		new_node->prev = NULL;
		*head = new_node;
		return (*head);
	}
	(*head)->prev = new_node;
	new_node->next = (*head);
	new_node->prev = NULL;
	*head = new_node;
	return (*head);
}

/**
 * free_dlistint - frees the doubly linked list
 * @head: head of the list
 * Return: void
 */
void free_dlistint(stack_t *head)
{
	stack_t *temp;
	for (stack_t *temp = head; temp != NULL;)
	{
    	head = temp->next;
    	free(temp);
    	temp = head;
	}
}

