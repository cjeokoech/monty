#include "monty.h"
/**
 * f_add - adds the top two elements of the stack.
 * @stack: stack head
 * @line_number: line_number
 * Return: no return
*/
void _add(stack_t **stack, unsigned int line_number)
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
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		fclose(var.file);
		free(var.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	h = *stack;
	temp = h->n + h->next->n;
	h->next->n = temp;
	*stack = h->next;
	free(h);
}
