#include "monty.h"

/**
 * main - Entry point for the Monty program
 * @argc: Argument count
 * @argv: Argument vector
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char *argv[])
{
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", div_op},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};


	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s file\n", argv[0]);
		return (EXIT_FAILURE);
	}

	process_file(argv[1], instructions);

	return (EXIT_SUCCESS);
}

/**
 * process_file - ...
 * @filename: Name of the file
 * @instructions: ...
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
void process_file(const char *filename, instruction_t *instructions)
{
	FILE *file = NULL;
	stack_t *stack = NULL;

	file = fopen(filename, "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	execute_instructions(file, &stack, instructions);

	fclose(file);

}


/**
 * execute_instructions - Execute the instructions
 * @file: The stream
 * @stack: The stack
 * @ins: ...
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
void execute_instructions(FILE *file, stack_t **stack, instruction_t *ins)
{
	char *line = NULL, *opcode;
	size_t len = 0;
	unsigned int num = 0;
	int i;

	while (getline(&line, &len, file) != -1)
	{
		num++;
		opcode = strtok(line, " \t\n");
		if (!opcode)
			continue;

		for (i = 0; ins[i].opcode != NULL; i++)
		{
			if (strcmp(opcode, ins[i].opcode) == 0)
			{
				ins[i].f(stack, num);
				break;
			}
		}

		if (!ins[i].opcode)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", num, opcode);
			fclose(file);
			free(line);
			exit(EXIT_FAILURE);
		}
	}

	free(line);
}
