#include "monty.h"

/**
 * pop -  prints the value at the top of the stack, followed by a new line
 * @stack: head of the linked list
 * @linenumber: line number of the monty file
 *
 * Return: void
 */
void pop(stack_t **stack, unsigned int linenumber)
{
	stack_t *ptrCpy;

	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", linenumber);
		free_global(*stack);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->next != NULL)
	{
		ptrCpy = (*stack)->next;
		ptrCpy->prev = NULL;
		free(*stack);
		*stack = ptrCpy;
		return;
	}
	free(*stack);
	*stack = NULL;
}

/**
 * swap -  swaps the first two nodes in stack
 * @stack: head of the linked list
 * @linenumber: line number of the monty file
 *
 * Return: void
 */
void swap(stack_t **stack, unsigned int linenumber)
{
	stack_t *tmp;
	int i = 1;

	for (tmp = *stack; i < 3; i++, tmp = tmp->next)
	{
		if (tmp == NULL)
		{
			fprintf(stderr, "L%u: can't swap, stack too short\n", linenumber);
			free_global(*stack);
			exit(EXIT_FAILURE);
		}
	}
	tmp = (*stack);
	(*stack) = (*stack)->next;
	(*stack)->prev = tmp->prev;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
	tmp->prev = (*stack);
	tmp = tmp->next;
	if (tmp != NULL)
	{
		tmp->prev = (*stack)->next;
	}
}

/**
 * add - adds the first two nodes in stack
 * @stack: head of the linked list
 * @linenumber: line number of the monty file
 *
 * Return: void
 */
void add(stack_t **stack, unsigned int linenumber)
{
	(void)stack;
	(void)linenumber;
}

/**
 * nop - does nothing at all.. . . wow
 * @stack: head of the linked list
 * @linenumber: line number of the monty file
 *
 * Return: void
 */
void nop(stack_t **stack, unsigned int linenumber)
{
	(void)stack;
	(void)linenumber;
}
