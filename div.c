#include "monty.h"
/**
 * _div - divides the top two elements of the stack.
 * @stack: stack head
 * @line_number: line_number
 * Return: no return
*/
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *h;
	int len = 0, temp;

	h = *stack;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		fclose(var.file);
		free(var.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	h = *stack;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		fclose(var.file);
		free(var.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	temp = h->next->n / h->n;
	h->next->n = temp;
	*stack = h->next;
	free(h);
}
