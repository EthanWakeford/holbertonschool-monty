#include "monty.h"


char *make_opcode(char *buffer)
{
	char *opcode;

	opcode = strtok(buffer, " \t");
	if (opcode == NULL)
		return (NULL);
	global.oparg = strtok(NULL, " \t");
	return (opcode);
}

int main(int argc, char **argv)
{
	char *opcode;
	size_t bufsize;
	void (*operation)(stack_t **stack, unsigned int line_number);
	stack_t **stack = NULL;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit (EXIT_FAILURE);
	}
	global.fp = fopen(argv[1], "r");
	
	while (getline(&global.buffer, &bufsize, global.fp) != -1)
	{
		opcode = make_opcode(global.buffer);
		if (opcode == NULL)
			continue;
		printf("%s\n", opcode);
		operation = getop(opcode);
		if (operation == NULL)
			exit (EXIT_FAILURE);
		operation(stack, 0);
	}
	fclose(global.fp);
	free(global.buffer);
	return (1);
}
