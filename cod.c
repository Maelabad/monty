#include "monty.h"

/**
 * push - Pushes an element onto the stack
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number being executed
 */
void push(stack_t **stack, unsigned int line_number)
{
	int num = 0, sign = 1, i = 0;
	char *arg = NULL;
	stack_t *new_node = NULL;

	arg = strtok(NULL, " \t\n");
	if (!arg)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (arg[0] == '-')
	{
		sign = -1;
		i = 1;
	}
	while (arg[i] != '\0')
	{
		if (!isdigit(arg[i]))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		num = num * 10 + (arg[i] - '0');
		i++;
	}
	num *= sign;
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = num;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack)
		(*stack)->prev = new_node;
	*stack = new_node;
}


/**
 * pall - Prints all elements of the stack
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number being executed
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = NULL;

	(void)line_number; /* Unused parameter */

	current = *stack;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}


/**
 * pint - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void pint(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
