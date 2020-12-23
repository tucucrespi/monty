#ifndef MONTY_H
#define MONTY_H

#include <ctype.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * struct global_variables_s - structure for variables as global variables.
 * @number: string with the parameter given after push
 * @fd: file descriptor of opened file
 * @buffer: buffer getline
 */
typedef struct global_variables_s
{
char *number;
FILE *fd;
char *buffer;
} global_variables_t;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern global_variables_t var_global;

/*----------main--------------*/
void free_nodes(stack_t *stack);

/*----------read_line---------*/
void open_file(char *filename, stack_t **stack);
void read_file(char *filename, stack_t **stack);
int tokenizer(char *buffer, stack_t **stack,
	      int line_number, int data_format);
void get_function(char *opcode, stack_t **stack,
		  int line_number, int data_format);

/*-----stack_operations-------*/
void _push_stack(stack_t **stack, unsigned int line_number);

/*void _push_queue(stack_t **new_node, unsigned int line_number);*/
void _pall(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);
/*-----math_operations-------*/
void _add(stack_t **stack, unsigned int line_number);

/*-----string_operations-------*/
void _nop(stack_t **stack, unsigned int line_number);

/*-------error_handler--------*/
void _error1(int error_code, ...);
void _error2(int error_code, ...);

#endif /* MONTY_H */
