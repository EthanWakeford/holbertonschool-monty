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
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};

	for (i = 0; opcodeFunction[i].opcode; i++)
	{
		printf("%d\n", i);
		if (strcmp(opcodeFunction[i].opcode, opcode) == 0)
		{
			opcodeFunction[i].f(stack, linenumber);
			return;
		}
		printf("%d\n", i);
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", linenumber, opcode);
	exit(EXIT_FAILURE);
}
