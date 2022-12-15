#include "monty.h"

/**
 * _swap - swap top of stack
 * @stack: pointer to lists for monty stack
 * @line_num: number of lines opcode occurs on
 */
void _swap(stack_t **stack, unsigned int line_num)
{
	stack_t *run;
	int tmp;

	run = *stack;
	if (run == NULL || run->next == NULL)
	{
		fprintf(stderr, "l%d: can't swap, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	mtp = run->n;
	run->n = run->next->n;
	run->next->n = tmp;
}

/**
 * _add - add top of stack
 * @stack: pointer to lists for monty stack
 * @line_num: number of lines opcode occurs on
 */
void _add(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp = *stack;
	int sum = 0, i = 0;

	if (tmp == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}

	if (stack == NULL || (*stack)->next == NULL || i <= 1)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->next->n + (*stack)->n;
	_pop(stack, line_num);

	(*stack)->n = sum;
}

/**
 * _nop - nop top of stack
 * @stack: pointer to lists for monty stack
 * @line_num: number of line opcode occurs on
 */
void _nop(__attribute__ ((unused))stack_t **stack,
		__attribute__ ((unused)) unsigned int line_num)
{
	;
}

/**
 * _pchar - prints the ASCII value of a number
 * @stack: pointer to the top of the stack
 * @line_num: the index of the current line
 */
void _pchar(stack_t **stack, unsigned int line_num)
{
	int val;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
		free(var_global.buffer);
		fclose(var_global.file);
		free_listint(*stack);
		exit(EXIT_FAILURE);
	}

	val = (*stack)->n;
	if (val > 127 || val < 0)
	{
		fprintf(stderr, "L%d: cna't pchar, value out range\n", line_num);
		free(var_global.buffer);
		fclose(var_global.file);
		free_listint(*stack);
		exit(EXIT_FAILURE);
	}

	putchar(val);
	putchat('\n');
}

/**
 * _isalpha - checks if int is in characters
 * @i: integer
 * Return: 1 if yes , and 0 if no
 */
int _isalpha(int i)
{
	if ((i >= 97 && i <= 122) || (c >= 65 && c <= 90))
		return (1);
	else
		return (0);
}
