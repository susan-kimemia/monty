#ifndef MONTY_H
#define MONTY_H

#define  PS_C_SOS 200809L
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <ctype.h>

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

/**
 * struct globals - global structure to use in the functions
 * @lifo: is stack or queue
 * @cont: current line
 * @arg: second parameter inside the current line
 * @head: doubly linked list
 * @fd: file descriptor
 * @buffer: input text
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO ALX project
 */
typedef struct globals
{
	int lifo;
	unsigned int cont;
	char  *arg;
	stack_t *head;
	FILE *fd;
	char *buffer;
} global_t;

extern global_t glovar;

void __pushh(stack_t **head, unsigned int line_num);
void _pall(stack_t **head, unsigned int line_num);
void top_prnt(stack_t **head, unsigned int line_num);
void _pop(stack_t **head, unsigned int line_num);
void _we_swap(stack_t **head, unsigned int line_num);
void _add(stack_t **head, unsigned int line_num);
void __nothing(stack_t **head, unsigned int line_num);
void _subtract(stack_t **head, unsigned int line_num);
void _divide(stack_t **head, unsigned int line_num);
void _mul(stack_t **head, unsigned int line_num);
void _find_mod(stack_t **head, unsigned int line_num);
void p_char(stack_t **head, unsigned int line_num);
void prnt_str(stack_t **head, unsigned int line_num);
void _rotl(stack_t **head, unsigned int line_num);
void _rotr(stack_t **head, unsigned int line_num);

void (*get_opcodes(char *opc))(stack_t **stack, unsigned int line_number);

int _saach(char *s, char c);
char *str_tok(char *s, char *d);
int _strcmp(char *s1, char *s2);

stack_t *add_dnodeint_end(stack_t **head, const int n);
stack_t *add_dnodeint(stack_t **head, const int n);
void free_dlistint(stack_t *head);

void free_glovar(void);

#endif /* MONTY_H*/

