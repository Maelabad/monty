#include "monty.h"

/**
  * frees_stack - Remove all elements in the stack
  * Return: Nothing
  */
void frees_stack(stack_t **head)
{
	stack_t *temp = NULL;

	if (*head)
	{
		temp = *head;

		while (temp)
		{
			*head = (*head)->next;
			free(temp);
			temp = (*head);
		}
	}
}
