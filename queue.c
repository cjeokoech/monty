#include "monty.h"
/**
 * _queue - prints the top
 * @stack: stack head
 * @line_number: line_number
 * Return: no return
*/
void _queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	var.lifo = 1;
}

/**
 * _addqueue - add node to the tail stack
 * @n: new_value
 * @stack: head of the stack
 * Return: no return
*/
void _addqueue(stack_t **stack, int n)
{
	stack_t *newnode, *temp;

	temp = *stack;
	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
	{
		printf("Error\n");
	}
	newnode->n = n;
	newnode->next = NULL;
	if (temp)
	{
		while (temp->next)
			temp = temp->next;
	}
	if (!temp)
	{
		*stack = newnode;
		newnode->prev = NULL;
	}
	else
	{
		temp->next = newnode;
		newnode->prev = temp;
	}
}
