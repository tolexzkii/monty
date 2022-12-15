#include "monty.h"

/**
 * _pstr - mod top of stack
 * @stack: pointer to lists for monty stack
 * @line_num: number of lines opcode occurs on
 */
void _pstr(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp = *stack;
	int i = 0;

	(void)line_num;

	while (tmp)
	{
		i = tmp->n;
		if (i == 0 || _isalpha(i) == 0)
			break;
		putchar(i);
		tmp = tmp->next;
	}
	putchar('\n');
}

/**
 * _rotl - mod top of stack
 * @stack: pointer to lists for monty stack
 * @line_num: number of lines opcode occurs on
 */
void _rotl(stack_t **stack, unsigned int line_num)
{
	stack_t *run = *stack;

	int a = 0;

	if (!line_num || !stack || !*stack || !(*stack)->next)
		return;

	a = run->n;

	while (run->next)
	{
		run = run->next;
		run->prev->n = run->n;
	}

	run->n = a;
}

/**
 * _rotr - mod top of stack
 * @stack: pointer to lists for monty stack
 * @line_num: number of lines opcode occurs on
 */
void _rotr(stack_t **stack, unsigned int line_num)
{
	stack_t *run = *stack;

	int a = 0;

	if (!line_num || !stack || !*stack || !(*stack)->next)
		return;

	while (run->next)
		run = run->next;

	a = run->n;

	while (run->prev)
	{
		run = run->prev;
		run->next->n = run->n;
	}

	run->n = a;
}
