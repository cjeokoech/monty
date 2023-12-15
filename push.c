#include "monty.h"
/**
 * _push - add node to the stack
 * @stack: stack head
 * @line_number: line_number
 * Return: no return
*/
void _push(stack_t **stack, unsigned int line_number)
{
	int n, j = 0, flag = 0;

	if (var.arg)
	{
		if (var.arg[0] == '-')
			j++;
		for (; var.arg[j] != '\0'; j++)
		{
			if (var.arg[j] > 57 || var.arg[j] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(var.file);
			free(var.content);
			free_stack(*stack);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(var.file);
		free(var.content);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	n = atoi(var.arg);
	if (var.lifo == 0)
		_addnode(stack, n);
	else
		_addqueue(stack, n);
}
