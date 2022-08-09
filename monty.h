#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

extern char *oparg;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
		int n;
		struct stack_s *prev;
		struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
		char *opcode;
		void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

char *make_opcode(char *buffer);
void push(struct_t **stack, unsigned int linenumber);
void pall(struct_t **stack, unsigned int linenumber);
void pint(struct_t **stack, unsigned int linenumber);
void pop(struct_t **stack, unsigned int linenumber);
void swap(struct_t **stack, unsigned int linenumber);
void add(struct_t **stack, unsigned int linenumber);
void nop(struct_t **stack, unsigned int linenumber);

#endif
