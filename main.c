#include "monty.h"

char *make_opcode(char *buffer)
{
	char *opcode;

	opcode = strtok(buffer, " \t");
	printf("%s\n", opcode);
	if (opcode == NULL)
		return (NULL);
	return (opcode);
}

int main(int argc, char **argv)
{
	char *buffer, *opcode;
	size_t bufsize;
	FILE *fp;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit (EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	
	while (getline(&buffer, &bufsize, fp) != -1)
	{
		opcode = make_opcode(buffer);
		if (opcode == NULL)
			continue;
	}
	free(buffer);
	return (1);
}
