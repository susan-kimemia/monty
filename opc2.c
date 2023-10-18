#include "monty.h"

/**
 * __pstr - prints string starting at the top of the stack
 * @head: head of a list
 * @lineNamba: command line number
 */
void __pstr(stack_t **head, unsigned int lineNamba)
{
	stack_t *node = *head;

	(void)lineNamba;
while (node)
{
if (node->n >= 0 && node->n <= 127)
{
if (node->n == 0)
{
break;
}
putchar(node->n);
}
else
{
break;
}
node = node->next;
}
putchar('\n');
}
