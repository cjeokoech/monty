#include "monty.h"
/**
  *_sub- sustration
  *@struck: stack head
  *@line_number: line_number
  *Return: no return
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int s, nodes;

	temp = *stack;
	for (nodes = 0;temp != NULL; nodes++)
		temp = temp->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		fclose(var.file);
		free(var.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	s = temp->next->n - temp->n;
	temp->next->n = s;
	*stack = temp->next;
	free(temp);
}
