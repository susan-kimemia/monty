#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @head: head of the list
 * @lineNamba: command line number
 */

void add(stack_t **head, unsigned int lineNamba)
{
	int outcome;

if ((*head == NULL) || ((*head)->next == NULL))
{
fprintf(stderr, "L%d: can't add, stack too short\n", lineNamba);
exit(EXIT_FAILURE);
}
	outcome  = (*head)->n + (*head)->next->n;
	pop(head, lineNamba);
	pop(head, lineNamba);
	__addingNode(head, outcome);
}

/**
 * sub - subtracts the top element from the second element on the stack
 * @head: head of the list
 * @lineNamba: command line
 */
void sub(stack_t **head, unsigned int lineNamba)
{
	int outcome;

	if ((*head == NULL) || ((*head)->next == NULL))
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", lineNamba);
		exit(EXIT_FAILURE);
	}
	outcome  = (*head)->next->n - (*head)->n;
	pop(head, lineNamba);
	pop(head, lineNamba);
	__addingNode(head, outcome);
}

/**
 * _div - divides the second top element by the second element of the stack
 * @head: head of the list
 * @lineNamba: command line
 */
void _div(stack_t **head, unsigned int lineNamba)
{
	int outcome;

	if ((*head == NULL) || ((*head)->next == NULL))
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", lineNamba);
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", lineNamba);
		__freeList(*head);
		__freeGrid(opcode_read);
		exit(EXIT_FAILURE);
	}
	outcome  = (*head)->next->n / (*head)->n;
	pop(head, lineNamba);
	pop(head, lineNamba);
	__addingNode(head, outcome);
}

/**
 * mul - mul the top element by the second element of the stack
 * @head: head of the list
 * @lineNamba: command line
 */
void mul(stack_t **head, unsigned int lineNamba)
{
	int outcome;

	if ((*head == NULL) || ((*head)->next == NULL))
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", lineNamba);
		__freeList(*head);
		__freeGrid(opcode_read);
		exit(EXIT_FAILURE);
	}
	outcome  = (*head)->next->n * (*head)->n;
	pop(head, lineNamba);
	pop(head, lineNamba);
	__addingNode(head, outcome);
}

/**
 * mod - computes the rest of the division of the second top element
 * of the stack by the top element of the stack.
 * @head: head of the list
 * @lineNamba: command line
 */
void mod(stack_t **head, unsigned int lineNamba)
{
	int outcome;

	if ((*head == NULL) || ((*head)->next == NULL))
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", lineNamba);
		__freeList(*head);
		__freeGrid(opcode_read);
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", lineNamba);
		__freeList(*head);
		__freeGrid(opcode_read);
		exit(EXIT_FAILURE);
	}
	outcome  = (*head)->next->n % (*head)->n;
	pop(head, lineNamba);
	pop(head, lineNamba);
	__addingNode(head, outcome);
}
