#include "monty.h"

/**
 * push - creates a node in the linked list
 * @stack: head of the linked list
 * @linenumber: line number of the monty file
 *
 * Return: void
 */

void push(stack_t **stack, unsigned int linenumber)
{
	stack_t *new;
	int i = 0;

	if (!global.oparg)
	{
		fprintf(stderr, "L%u: usage: push integer\n", linenumber);
		free_global(*stack);
		exit(EXIT_FAILURE);
	}
	while (global.oparg[i])
	{
		if ((isdigit(global.oparg[i]) == 0) && (global.oparg[i] != '-'))
		{
			fprintf(stderr, "L%u: usage: push integer\n", linenumber);
			free_global(*stack);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_global(*stack);
		exit(EXIT_FAILURE);
	}

	if ((*stack) != NULL)
		(*stack)->prev = new;


	new->n = atoi(global.oparg);
	new->next = *stack;
	new->prev = NULL;
	*stack = new;
}

/**
 * pall - prints all the values on the starting from the top of the stack
 * @stack: head of the linked list
 * @linenumber: line number of the monty file
 *
 * Return: void
 */

void pall(stack_t **stack, unsigned int linenumber)
{
	stack_t *printPtr = *stack;
	(void)linenumber;

	while (printPtr)
	{
		printf("%d\n", printPtr->n);
		printPtr = printPtr->next;
	}
}

/**
 * pint -  prints the value at the top of the stack, followed by a new line
 * @stack: head of the linked list
 * @linenumber: line number of the monty file
 *
 * Return: void
 */

void pint(stack_t **stack, unsigned int linenumber)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", linenumber);
		free_global(*stack);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
