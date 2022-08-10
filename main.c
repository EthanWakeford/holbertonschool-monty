#include "monty.h"


char *make_opcode(char *buffer)
{
	char *opcode;

	opcode = strtok(buffer, " \t");
	printf("%s\n", opcode);
	if (opcode == NULL)
		return (NULL);
	global.oparg = strtok(NULL, " \t");
	return (opcode);
}

int main(int argc, char **argv)
{
	char *opcode;
	size_t bufsize;
	global_t global;

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
		if (global.oparg != NULL)
			printf("%s\n", global.oparg);
	}
	fclose(global.fp);
	free(global.buffer);
	return (1);
}

