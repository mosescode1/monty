#include "monty.h"
/**
 * add- delete element from the stack
 * @stack: stack that contains all data
 * @code_line_number: the line where the instruction is read
 */
void add(stack_t **stack, unsigned int code_line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", code_line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
