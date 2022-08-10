#include "monty.h"


char *make_opcode(char *buffer)
{
	char *opcode;

	opcode = strtok(buffer, " \t\n");
	if (opcode == NULL)
		return (NULL);
	global.oparg = strtok(NULL, " \t\n");
	return (opcode);
}

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

	while (getline(&global.buffer, &bufsize, global.fp) != -1)
	{
		line_number++;
		opcode = make_opcode(global.buffer);
		if (opcode == NULL)
			continue;
		operation = getop(opcode);
		if (operation == NULL)
		{
			free_global(stack);
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
		operation(&stack, line_number);
	}
	free_global(stack);
	return (EXIT_SUCCESS);
}
