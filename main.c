#include "monty.h"

instruction_t instructions[] = {
    {"push", push},
    {"pall", pall},
    {"pint", pint},
    {"pop", pop},    /* Ajoute l'instruction "pop" */
    {"swap", swap},  /* Ajoute l'instruction "swap" */
    {"add", add},    /* Ajoute l'instruction "add" */
    {"nop", nop},    /* Ajoute l'instruction "nop" */
    {NULL, NULL}
};

/**
 * main - Entry point for the Monty program
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char *argv[])
{
    stack_t *stack = NULL;
    char *line = NULL;
    size_t len = 0;
    unsigned int line_number = 0;
    FILE *file = NULL;
    char *opcode;
    int i;


    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s file\n", argv[0]);
        return EXIT_FAILURE;
    }

    file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

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
                instructions[i].f(&stack, line_number);
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

    fclose(file);
    free(line);
    /* Free the stack here */
    return EXIT_SUCCESS;
}
