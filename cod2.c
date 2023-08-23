#include "monty.h"


/**
 * pop - Removes the element at the top of the stack
 * @stack: The head of the stack
 * @line_number: The line on which the error occurred
 * Return: Nothing
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	if (*stack)
		(*stack)->prev = NULL;
	free(temp);
}


/**
 * swap - swaps the top two elements of the stack.
 * @stack: The head of the stack
 * @line_number: The line on which the error occurred
 * Return: Nothing
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}



/**
 * add - adds the top two elements of the stack.
 * @stack: The head of the stack
 * @line_number: The line on which the error occurred
 * Return: Nothing
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
}


/**
 * nop - doesn’t do anything.
 * @stack: The head of the stack
 * @line_number: The line on which the error occurred
 * Return: Nothing
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
