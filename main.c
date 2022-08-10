#include "monty.h"

/**
*make_opcode - gets the opcode from line
*@buffer: buffer to read from
*Return: opcode, NULL on faiulure
*/

char *make_opcode(char *buffer)
{
	char *opcode;

	opcode = strtok(buffer, " \t\n");
	if (opcode == NULL)
		return (NULL);
	global.oparg = strtok(NULL, " \t\n");
	return (opcode);
}

/**
*main - interperates a monty file
*@argc: argument count
*@argv: argument vector
*Return: exit success
*/

int main(int argc, char **argv)
{
	char *opcode;
	unsigned int line_number = 0;
	size_t bufsize;
	void (*operation)(stack_t **stack, unsigned int line_number);
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	global.fp = fopen(argv[1], "r");
	if (global.fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&global.buffer, &bufsize, global.fp) != -1)
	{
		line_number++;
		opcode = make_opcode(global.buffer);
		if (opcode == NULL)
			continue;
		operation = getop(opcode);
		if (operation == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			free_global(stack);
			exit(EXIT_FAILURE);
		}
		operation(&stack, line_number);
	}
	free_global(stack);
	return (EXIT_SUCCESS);
}
