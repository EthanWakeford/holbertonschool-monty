#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>


/**
*struct global_s - group of global variables to use across functions
*@buffer: buffer of line read from file
*@oparg: operator argument for push
*@fp: file pointer holding the open file to read from
*
*Descripton: group of global variables
*/

typedef struct global_s
{
		char *buffer;
		char *oparg;
		FILE *fp;
} global_t;

global_t global;

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
void push(stack_t **stack, unsigned int linenumber);
void pall(stack_t **stack, unsigned int linenumber);
void pint(stack_t **stack, unsigned int linenumber);
void pop(stack_t **stack, unsigned int linenumber);
void swap(stack_t **stack, unsigned int linenumber);
void add(stack_t **stack, unsigned int linenumber);
void nop(stack_t **stack, unsigned int linenumber);

#endif
