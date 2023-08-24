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
 * @instructions: ...
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
void execute_instructions(FILE *file, stack_t **stack, instruction_t *instructions)
{
	char *line = NULL, *opcode;
	size_t len = 0;
	unsigned int line_number = 0;
	int i;

	while (getline(&line, &len, file) != -1)
	{
		line_number++;
		opcode = strtok(line, " \t\n");
		if (!opcode)
			continue;

		for (i = 0; instructions[i].opcode != NULL; i++)
		{
			if (strcmp(opcode, instructions[i].opcode) == 0)
			{
				instructions[i].f(stack, line_number);
				break;
			}
		}

		if (!instructions[i].opcode)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			fclose(file);
			free(line);
			exit(EXIT_FAILURE);
		}
	}

	free(line);
}
