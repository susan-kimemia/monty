#ifndef MONTY_H
#define MONTY_H
/** Headers **/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdarg.h>

#define DELIM " \t\n"

/* data Strutures */

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

extern char **opcode_read;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int lineNamba);
} instruction_t;

/** Funct prototypes **/
stack_t *__addingNode(stack_t **head, int n);
int __deleteNode(stack_t **head, unsigned int index);
void _printTop(stack_t *head);
void __swapNode(stack_t **head, unsigned int);
size_t _stackLen(stack_t *head);

void _let_opcode(stack_t **head, unsigned int);

void pop(stack_t **head, unsigned int lineNamba);
void pint(stack_t **head, unsigned int lineNamba);
void swap(stack_t **head, unsigned int lineNamba);
void pall(stack_t **head, unsigned int lineNamba);
void push(stack_t **head, char *operand, unsigned int lineNamba);
void nop(stack_t **head, unsigned int lineNamba);
void add(stack_t **head, unsigned int lineNamba);
void sub(stack_t **head, unsigned int lineNamba);
void mul(stack_t **head, unsigned int lineNamba);
void _div(stack_t **head, unsigned int lineNamba);
void mod(stack_t **head, unsigned int lineNamba);
void rotl(stack_t **head, unsigned int lineNamba);
void rotr(stack_t **head, unsigned int lineNamba);
void stack(stack_t **, unsigned int);
void __pchar(stack_t **head, unsigned int lineNamba);
void __pstr(stack_t **head, unsigned int lineNamba);
void __freeList(stack_t *head);
char **__tokenize(char *str, const char *delim);
void __freeGrid(char **grid);
int __isNamba(char *c);

#endif /* MONTY_H */
