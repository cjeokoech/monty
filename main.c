#include "monty.h"
#include <stdio.h>
var_t var = {NULL, NULL, NULL, 0};
/**
* main - monty code interpreter
* @argc: number of arguments
* @argv: monty file location
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	char *content;
	FILE *file;
	size_t len = 0;
	ssize_t readline = 1;
	stack_t *stack = NULL;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	var.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (readline > 0)
	{
		content = NULL;
		readline = getline(&content, &len, file);
		var.content = content;
		line_number++;
		if (readline > 0)
		{
			execute(content, &stack, line_number, file);
		}
		free(content);
	}
	free_stack(stack);
	fclose(file);
return (0);
}
