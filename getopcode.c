#include "monty.h"

/**
 * getop - Takes opcode and returns matching function call
 * @opcode: opcode given from parsing line
 *
 * Return: function pointer
 */

void (*getop(char *opcode))(stack_t **stack, unsigned int linenumber)
{
	unsigned int i;

	instruction_t opcodeFunction[] = {
		{"push", push},
		{"pull", pull},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};

	for (i = 0; opcodeFunction[i].opcode; i++)
	{
		if (strcmp(opcodeFunction[i].opcode, opcode) == 0)
			break;
	}
	return (opcodeFunction[i].f)
}
