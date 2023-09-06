#include "monty.h"
/**
 * main - main program
 * @argc: number argument.
 * @argv: array of argument.
 * Return: (EXIT_SUCCESS) or (EXIT_FAILURE)
 */

int main(int argc, char **argv)
{
	FILE *fd;
	stack_t *stack = NULL;
	unsigned int ligne = 0;
	char *str = NULL;
	char *tok = NULL;
	size_t size = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&str, &size, fd) != EOF)
	{
		ligne++;
		tok = strtok(str, "\n\t ");
		if (tok != NULL)
		{
			check(tok, &stack, ligne);
		}
	}
	free(str);
	fclose(fd);
	free_all(stack);
	return (EXIT_SUCCESS);
}
/**
 * check - check The function.
 * @cmd: commande a saisir.
 * @stack: double pointer to head of stack.
 * @ligne: ligne number.
 */
void check(char *cmd, stack_t **stack, unsigned int ligne)
{
	int i;
	instruction_t op[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{NULL, NULL},
	};

	for (i = 0; op[i].opcode != NULL; i++)
	{
		if (strcmp(cmd, op[i].opcode) == 0)
		{
			op[i].f(stack, ligne);
			return;
		}
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", ligne, cmd);
	exit(EXIT_FAILURE);
}
