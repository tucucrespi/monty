#include "monty.h"
/**
 * _add - adds the top two elements of the stack.
 * If the stack contains less than two elements, handle error
 * with _error(9).
 * @stack: Double pointer to the top of the stack.
 * @line_number: line number of the opcode in the file.
 * Return: void.
 */
void _add(stack_t **stack, unsigned int line_number)
{
stack_t *new = *stack;

if (*stack == NULL || stack == NULL || (*stack)->next == NULL)
{
free_nodes(*stack);
_error2(10, line_number);
}
new->next->n += new->n;
*stack = (*new).next;
free(new);
(*stack)->prev = NULL;
}
