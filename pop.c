#include "monty.h"

/**
 * _pop - Removes the element at the top of the stack
 * @stack: The head of the stack
 * @line_number: The line on which the error occurred
 * Return: Nothing
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *actual = *stack, *temp = NULL;

	if (*stack == NULL)
		handle_error(ERR_POP_USG, NULL, line_number, NULL);

	temp = actual;
	if (actual->next)
	{
		actual = actual->next;
		actual->prev = temp->prev;
		*stack = actual;
	}
	else
	{
		*stack = NULL;
	}

	free(temp);
}
