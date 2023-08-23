#include "monty.h"

/**
 * _pall - Prints all the values on the stack,
 * starting from the top of the stack.
 * @stack: The head of the stack
 * @line_number: The line on which the error occurred
 *
 * Return: Nothing
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *actual = NULL;
	(void) line_number;

	if (*stack)
	{
		actual = *stack;
		while (actual != NULL)
		{
			printf("%d\n", actual->n);
			actual = actual->next;
		}
	}
}
