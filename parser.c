#include "monty.h"

/**
 * get_opcodes - selects the correct opcode to perform
 * @opc: opcode passed
 * Return: pointer to the function that executes the opcode
 */
void (*get_opcodes(char *opc))(stack_t **stack, unsigned int line_number)
{
	instruction_t instruct[] = {
		{"push", __pushh},
		{"pall", _pall},
		{"pint", top_prnt},
		{"pop", _pop},
		{"swap", _we_swap},
		{"add", _add},
		{"nop", __nothing},
		{"sub", _subtract},
		{"div", _divide},
		{"mul", _mul},
		{"mod", _find_mod},
		{"pchar", p_char},
		{"pstr", prnt_str},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{NULL, NULL}
	};
	int i;

	for (i = 0; instruct[i].opcode; i++)
	{
		if (_strcmp(instruct[i].opcode, opc) == 0)
			break;
	}

	return (instruct[i].f);
}
