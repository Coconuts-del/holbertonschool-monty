#include "monty.h"

/**
 * check_digit - check if the string contains only digits
 * @arg: pointer on argument to check
 * Return: 0 if only digits are found, 1 otherwise
 */

int check_digit(char *arg)
{
	int i;

	for (i = 0; arg[i]; i++)
	{
		if (arg[i] == '-' && i == 0)
			continue;
		if (isdigit(arg[i]) == 0)
			return (1);
	}
	return (0);
}

/**
 * push - push an integer onto the stack
 * @stack: double pointer to head of stack
 * @ligne: line number of file we are processing
 *
 */

void push(stack_t **stack, unsigned int ligne)
{
	int data;
	char *arg;

	arg = strtok(NULL, "\n\t ");

	if (arg == NULL || check_digit(arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", ligne);
		exit(EXIT_FAILURE);
	}

	data = atoi(arg);

	if (add_node(stack, data) == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
}
/**
 * add_node - add a newnode at beginning of our
 * linked-listed behavior stack
 * @stack: double pointer to head of stack
 * @n: new data to fill in new node
 * Return: pointer to new node
 */
stack_t *add_node(stack_t **stack, int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (!new)
		return (NULL);
	new->n = n;
	new->next = *stack;
	new->prev = NULL;

	if (*stack)
		(*stack)->prev = new;

	*stack = new;
	return (new);
}

/**
 * pall - prints all value file.
 * @stack: To head of stack.
 * @ligne: ligne number.
 */
void pall(stack_t **stack, __attribute((unused)) unsigned int ligne)
{
	stack_t *tmp = *stack;

	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
		if (tmp == *stack)
			return;
	}
}
/**
 * free_all - function to free.
 * @stack: pointer to head of stack
 */

void free_all(stack_t *stack)
{
	stack_t *tmp;

	while (stack != NULL)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}
