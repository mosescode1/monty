#include "monty.h"
/**
 *pop- delete element from the stack
 * @stack: stack that contains all data
 * @code_line_number: the line where the instruction is read
 */
void pop(stack_t **stack, unsigned int code_line_number)
{
	stack_t *del;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", code_line_number);
		exit(EXIT_FAILURE);
	}
	del = *stack;
	*stack = (*stack)->next;

	free(del);
}