#include "monty.h"

/**
 * pint - prints the value at top.
 * @stack: double pointer at head of stack
 * @ligne: line number of the file we process on
 */
void pint(stack_t **stack, unsigned int ligne)
{
	stack_t *head = *stack;

	if (*stack == 0)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", ligne);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", head->n);
}

/**
 * pop - Removes the top element of stack
 * @stack: To head of stack
 * @ligne: line number
 */
void pop(stack_t **stack, unsigned int ligne)
{
	stack_t *tmp = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", ligne);
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;
	if (*stack)
		(*stack)->prev = NULL;
	free(tmp);
}

/**
 * swap - swaps the top two.
 * @stack: To head of stack
 * @ligne : line number.
 */
void swap(stack_t **stack, unsigned int ligne)
{
	int swapper;

	if (*stack && (*stack)->next)
	{
		swapper = (*stack)->n;
		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = swapper;
	}
	else
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", ligne);
		exit(EXIT_FAILURE);
		return;
	}
}
/**
 * add - Add the two last node.
 * @stack: Double pointer to the head of stack.
 * @ligne: The line numbee.
 */
void add(stack_t **stack, unsigned int ligne)
{
	int res = 0;

	if (*stack && (*stack)->next)
	{
		res += (*stack)->n;
		pop(stack, ligne);
		(*stack)->n += res;
	}
	else
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", ligne);
		exit(EXIT_FAILURE);
	}
}
