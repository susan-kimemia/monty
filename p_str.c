#include "monty.h"

/**
 * prnt_str - prints the string starting at the top of the stack,
 * followed by a new line
 * @head: head of the linked list
 * @line_num: line number
 * Return: void
 */
void prnt_str(stack_t **head, unsigned int line_num)
{
	stack_t *temp;
	(void)line_num;

	temp = *head;

	do {
		printf("%c", temp->n);
		temp = temp->next;
	} while (temp && temp->n > 0 && temp->n < 128);

	printf("\n");
}

