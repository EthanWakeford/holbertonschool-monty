#include "monty.h"

/**
 * push - creates a node in the linked list
 * @stack: head of the linked list
 * @linenumber: line number of the monty file
 *
 * Return: void
 */

void push(struct_t **stack, unsigned int linenumber)
{
	struct_t *new;
	int i = 0;

	while (oparg[i])
	{
		if (isdigit(oparg[i] == 0 && oparg[i] != '-'))
		{
			printf("L%u: usage: push integer\n", linenumber);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	new = malloc(sizeof(struct_t));
	if (!new)
		return (NULL);

	if ((*stack) != NULL)
		(*stack)->prev = new;


	new->n = atoi(oparg);
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

void pall(struct_t **stack, unsigned int linenumber)
{
	struct_t *printPtr = *stack;

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

void pint(struct_t **stack, unsigned int linenumber)
{

}
