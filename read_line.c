#include "monty.h"

/**
 * open_file -  function that opens a file
 * @filename: is a pointer to the name of the file to be opened.
 * @stack: double pointer to the node of the stack
 * Return: void.
 */
void open_file(char *filename, stack_t **stack)
{
if (!filename)
{
free_nodes(*stack);
_error1(2, filename);
}
var_global.fd = fopen(filename, "r");
if (var_global.fd == NULL)
{
_error1(2, filename);
}
read_file(filename, stack);
fclose(var_global.fd);
}

/**
 * read_file -  function that reads a text file
 * and prints it to the POSIX standard output.
 * @filename: is a pointer to the name of the file to be opened.
 * @stack: double pointer to the node of the stack
 * Return: void.
 */
void read_file(char *filename, stack_t **stack)
{
int line_number = 1;
size_t len;
int data_format;
(void)filename;

while (getline(&var_global.buffer, &len, var_global.fd) != EOF)
{
data_format = tokenizer(var_global.buffer, stack, line_number, data_format);
line_number++;
}
free(var_global.buffer);
}

/**
 * tokenizer - function that parses a buffer (line read)
 * and returns the flag data_format.
 * @buffer: line read by getline, if buffer == NULL handle error with _error(2)
 * @stack: double pointer to the node of the stack
 * @line_number: conter of lines read, that help us to handle the errors.
 * @data_format: format specifier that tells if the nodes will be enter
 * as a data_format (0) = stack or data_format (1) = queue.
 * Return: 0 if stack, 1 if queue.
 */
int tokenizer(char *buffer, stack_t **stack, int line_number, int data_format)
{
char *opcode;
const char *delimiters = " \n\t\r";

/*If *buffer is NULL,is because getline() failed allocating mamory*/
if (buffer == NULL)
{
free_nodes(*stack);
_error1(4);
}
/*Parsing the first element of the buffer delimiters: space and newline*/
opcode = strtok(buffer, delimiters);
if (!opcode)
return (data_format);
/*Tokenize whatever is leftover to be parsed*/
var_global.number = strtok(NULL, delimiters);
if (!var_global.number && (strcmp(opcode, "push") == 0))
{
free_nodes(*stack);
_error1(6, line_number);
}
/*Ask if the opcode sent is 'stack' or 'queue'*/
if (strcmp(opcode, "stack") == 0)
return (0);
else if (strcmp(opcode, "queue") == 0)
return (1);

/*here we get the function according to the opcode sent*/
get_function(opcode, stack, line_number, data_format);
return (data_format);
}

/**
 * get_function - checks character to an array of structs.
 * If a successful match is found, the matching function is passed.
 * @opcode: opcode passed by the user in the program
 * @stack: double pointer to the node of the stack
 * @line_number: conter of lines read, that help us to handle the errors.
 * @data_format: format specifier that tells if the nodes will be enter
 * Return: pointer to a function to format specifier
 */
void get_function(char *opcode, stack_t **stack,
int line_number, __attribute__((unused)) int data_format)
{
int i = 0, trigger = 0;

instruction_t op_functions[] = {
{"push", _push_stack},
{"pall", _pall},
{"pint", _pint},
{"pop", _pop},
{"swap", _swap},
{"add", _add},
{"nop", _nop},
{NULL, NULL}};
if (opcode[0] == '#')
return;
for (i = 0; op_functions[i].opcode != NULL; i++)
{
if (strcmp(opcode, op_functions[i].opcode) == 0)
{
op_functions[i].f(stack, line_number);
trigger = 1;
}
}
if (trigger == 0)
{
free_nodes(*stack);
_error1(3, opcode, line_number);
}
}
