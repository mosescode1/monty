#include "monty.h"

/**
 *push - adding to the stack*/

void push(stack_t **stack, unsigned int my_line_number)
{
	char *str_value;
	int code_value;
	stack_t *new_node = malloc(sizeof(stack_t));

	str_value = strtok(NULL, " \t\n");

	if (!str_value || !is_valid_integer(str_value))
	{
		fprintf(stderr, "L%u: usage: push integer\n", my_line_number);
		exit(EXIT_FAILURE);
	}
	code_value = atoi(str_value);

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = code_value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
	{
		(*stack)->prev = new_node;
	}

	*stack = new_node;
}

int is_valid_integer(const char *str)
{
	if (*str == '\0')
		return 0;

	while (*str != '\0')
	{
		if (!isdigit((unsigned char)*str))
			return 0;
		str++;
	}

	return 1;
}
