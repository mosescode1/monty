#include "monty.h"
/**
 * swap- delete element from the stack
 * @stack: stack that contains all data
 * @code_line_number: the line where the instruction is read
 */
void swap(stack_t **stack, unsigned int code_line_number)
{
	stack_t *s1, *s2;
	int temp, temp2;

	s1 = *stack;
	s2 = (*stack)->next;
	if (s1 != NULL && s2 != NULL)
	{
		temp = s1->n;
		temp2 = s2->n;
		s2->n = temp;
		s1->n = temp2;
	}
	else
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", code_line_number);
		exit(EXIT_FAILURE);
	}
}