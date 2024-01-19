#include "monty.h"

/**
 *push - adding to the stack
 *@stack: stacked to be filled
 *@line_number: number-line
 */

void push(stack_t **stack, unsigned int line_number)
{
	char *str_value;
	int code_value;
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	str_value = strtok(NULL, " \t\n");

	if (!str_value || !is_valid_integer(str_value))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	code_value = atoi(str_value);
	new_node->n = code_value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
	{
		(*stack)->prev = new_node;
	}

	*stack = new_node;
}
/**
 *is_valid_integer- check if its a valid integer
 *@str: string to check
 * Return: 0 id sucessful and 1 if fail
 */
int is_valid_integer(const char *str)
{
	if (*str == '\0')
		return (0);
	if (*str == '-' || *str == '+')
		str++;

	while (*str != '\0')
	{
		if (!isdigit((unsigned char)*str))
			return (0);
		str++;
	}

	return (1);
}

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
