#include "monty.h"

/**
 * pall - function to print all values from a stack
 * @stack: stack that contains all data
 * @line_number: the line where the instruction is read
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *top;
	(void)line_number;

	if (*stack == NULL)
		return;

	top = *stack;
	while (top)
	{
		printf("%d\n", top->n);
		top = top->next;
	}
}
