#include "monty.h"

/**
*free_stack - frees the stack
*@stack: first node of stack
*/

void free_stack(stack_t *stack)
{
	stack_t *node, *temp;

	for (node = stack; node != NULL; node = temp)
	{
		temp = node->next;
		free(node);
	}
}

/**
*free_global - frees globala vars and calls free_stack
*@stack: first node of stack
*/

void free_global(stack_t *stack)
{
	free_stack(stack);
	free(global.buffer);
	fclose(global.fp);
}
