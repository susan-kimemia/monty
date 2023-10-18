#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @head: pointer to stack head
 * @lineNamba: command line number
 */

void swap(stack_t **head, unsigned int lineNamba)
{
	__swapNode(head, lineNamba);
}

/**
 * stack - switches data structure order mode
 * @lineNamba: command line number
 * @head: pointer to list head
*/

void stack(stack_t **head, unsigned int lineNamba)
{
	(void)head;
	(void)lineNamba;
}

/**
 * __swapNode - swaps the top two elements in the stack
 * @head: pointer to the top
 * @lineNamba: commmand line number
 */
void __swapNode(stack_t **head, unsigned int lineNamba)
{
	stack_t *first;
	stack_t *second;

	if (_stackLen(*head) < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", lineNamba);
		__freeGrid(opcode_read);
		__freeList(*head);
		exit(EXIT_FAILURE);
	}
	first = *head;
	second = (*head)->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;

	*head = second;
}
