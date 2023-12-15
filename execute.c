#include "monty.h"
/**
* execute - executes the opcode
* @stack: head linked list - stack
* @line_numberr: line_counter
* @file: poiner to monty file
* @content: line content
* Return: no return
*/
int execute(char *content, stack_t **stack, unsigned int line_number, FILE *file)
{
	instruction_t op[] = {
				{"push", _push}, {"pall", _pall}, {"pint", _pint},
				{"pop", _pop},
				{"swap", _swap},
				{"add", _add},
				{"nop", _nop},
				{"sub", _sub},
				{"div", _div},
				{"mul", _mul},
				{"mod", _mod},
				{"pchar", _pchar},
				{"pstr", _pstr},
				{"rotl", _rotl},
				{"rotr", _rotr},
				{"queue", _queue},
				{"stack", _stack},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *o;

	o = strtok(content, " \n\t");
	if (o && o[0] == '#')
		return (0);
	var.arg = strtok(NULL, " \n\t");
	while (op[i].opcode && o)
	{
		if (strcmp(o, op[i].opcode) == 0)
		{	op[i].f(stack, line_number);
			return (0);
		}
		i++;
	}
	if (o && op[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", line_number, o);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
