#include "monty.h"
/**
  *_rotl- rotates the stack to the top
  *@stack: stack head
  *@line_number: line_number
  *Return: no return
 */
void _rotl(stack_t **stack,  __attribute__((unused)) unsigned int line_number)
{
	stack_t *tmp = *stack, *current;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}
	current = (*stack)->next;
	current->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *stack;
	(*stack)->next = NULL;
	(*stack)->prev = tmp;
	(*stack) = current;
}
