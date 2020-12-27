#include "monty.h"

/**
 * pchar_f - prints the ascii value of the character
 * @stack: double pointer from struct
 * @line_number: the number of every line
 * Return: always
 */

void pchar_f(stack_t **stack, unsigned int line_number)
{
stack_t *aux = *stack;

if (aux == NULL)
{
fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
free_list(aux);
exit(EXIT_FAILURE);
}
if (aux->n < 0 || aux->n > 127)
{
fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
free_list(aux);
exit(EXIT_FAILURE);
}
putchar(aux->n);
putchar(10);
}
