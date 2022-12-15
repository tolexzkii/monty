#include "monty.h"

/**
 * _push - push integer to a stack
 * @stack: linked list for monty stack
 * @line_num: number of lines opcode occurs on
 */
void _push(stack_t **stack, __attribute__ ((unused))unsigned int line_num)
{
	stack_t *top;
	(void)line_num;

	top = malloc(sizeof(stack_t));
	if (top == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	top->n = var_global.push_arg;
	top->next = *stack;
	top->prev = NULL;
	if (*stack != NULL)
		(*stack)->prev = top;
	*stack = top;
}

/**
 * _pall - print all function
 * @stack: pointer to linked list stack
 * @line_num: number of lines opcode occurs on
 */
void _pall(stack_t **stack, __attribute__ ((unused))unsigned int line_num)
{
	stack_t *run;

	run = *stack;
	while (run != NULL)
	{
		printf("%d\n", run->n);
		run = run->next;
	}
}

/**
 * _pint - print integer to top of stack
 * @stack: pointer to linked list stack
 * @line_num: number of lines opcode occurs on
 */
void _pint(stack_t **stack, unsigned int line_num)
{
	stack_t *run;

	run = *stack;
	if (run == NULL)
	{
		fprintf(stderr, "L%d: cant pint, stack, empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	printf("%d\n" run->n);
}

/**
 * _pop - removes element from stack
 * @stack: pointer to first node
 * @line_num: integer
 */
void _pop(stack_t **stack, unsigned int line_num)
{
	stack_t *nod = *stack;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}
	*stack = nod->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(nod);
}

/**
 * free_listint - free list
 * @head: pointer to the first node
 */
void free_listint(stack_t *head)
{
	stack_t *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
