#include "monty.h"
/**
 * rotl - makes the second first and first last
 * @head: head to the list
 * @lineNamba: command line number
 */

void rotl(stack_t **head, unsigned int lineNamba)
{
stack_t *second, *tail, *first;

/* Checks if stack is empty or has one element */
if ((!*head) || (*head && !(*head)->next))
return;

if (_stackLen(*head) == 2)
{
swap(head, lineNamba);
return;
}
else
{
first = tail = *head;
second = (*head)->next;
while (tail->next)
	tail = tail->next;
tail->next = first;
first->next = NULL;
first->prev = tail;
second->prev = NULL;
*head = second;
return;
}
}

/**
 * rotr - rotates the stack
 * @head: head to the list
 * @lineNamba: command line number
 */

void rotr(stack_t **head, unsigned int lineNamba)
{
	stack_t *top, *temp, *bottom;

	(void)lineNamba;
	if (!*head)
		return;
	if (!*head || !(*head)->next)
		return;

	bottom = *head;
	do {
		top = bottom;
		temp = bottom->next;
		bottom->next = bottom->prev;
		bottom->prev = temp;
		bottom = temp;
	} while (bottom);

	*head = top;
}

/**
 * pchar - prints the string starting at the top of the stack
 * @head: head of the list
 * @lineNamba: command line number
 */

void pchar(stack_t **head, unsigned int lineNamba)
{
if (*head == NULL)
{
fprintf(stderr, "L%d: can't pchar, stack empty\n", lineNamba);
exit(EXIT_FAILURE);
}
if ((*head)->n >= 0 && (*head)->n <= 127)
{
putchar((*head)->n);
putchar('\n');
}
else
{
fprintf(stderr, "L%d: can't pchar, value out of range\n", lineNamba);
__freeList(*head);
__freeGrid(opcode_read);
exit(EXIT_FAILURE);
}
}
