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
/** Data Strutures **/

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
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/** Function prototypes **/
stack_t *add_node(stack_t **head, int n);
int delete_node(stack_t **head, unsigned int index);
void print_top(stack_t *head);
void _swap_node(stack_t **head, unsigned int);
size_t stack_len(stack_t *head);

void get_opcode(stack_t **head, unsigned int);

void pop(stack_t **head, unsigned int line_number);
void pint(stack_t **head, unsigned int line_number);
void swap(stack_t **head, unsigned int line_number);
void pall(stack_t **head, unsigned int line_number);
void push(stack_t **head, char *operand, unsigned int line_number);
void nop(stack_t **head, unsigned int line_number);
void add(stack_t **head, unsigned int line_number);
void sub(stack_t **head, unsigned int line_number);
void mul(stack_t **head, unsigned int line_number);
void _div(stack_t **head, unsigned int line_number);
void mod(stack_t **head, unsigned int line_number);
void rotl(stack_t **head, unsigned int line_number);
void rotr(stack_t **head, unsigned int line_number);
void stack(stack_t **, unsigned int);
void pchar(stack_t **head, unsigned int line_number);
void pstr(stack_t **head, unsigned int line_number);
void free_list(stack_t *head);
char **tokenize(char *str, const char *delim);
void free_grid(char **grid);
int _isnumber(char *s);
#endif
