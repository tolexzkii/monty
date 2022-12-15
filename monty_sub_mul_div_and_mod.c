#include "monty.h"

/**
 * _sub - subtract top of stack
 * @stack: pointer to lists for monty stack
 * @line_num: number of lines of opcode occurs on
 */
void _sub(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp = *stack;
	int sub = 0, i = 0;

	if (tmp == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}

	if (stack == NULL || (*stack)->next == NULL || i <= 1)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	sub = (*stack)->next->n - (*stack)->n;
	_pop(stack, line_num);

	(*stack)->n = sub;
}

/**
 * _mul - multiply top stack
 * @stack: pointer to lists for monty stack
 * @line_num: number of lines opcode occurs on
 */
void _mul(stack_t **stack, unsigned int line_num)
{
	int ax;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_num);
		free(var_global.buffer);
		fclose(var_global.file);
		free_listint(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		ax = (*stack)->n;
		_pop(stack, line_num);
		(*stack)->n *= ax;
	}
}

/**
 * _div - divide top of stack
 * @stack: pointer to lists for monty stack
 * @line_num: number of lines opcode occurs on
 */
void _div(stack_t **stack, unsigned int line_num)
{
	int div = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, satck too short\n", line_num);
		free(var_global.buffer);
		fclose(var_global.file);
		free_listint(*stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		free(var_global.buffer);
		fclose(var_global.file);
		free_listint(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		div = (*stack)->n;
		_pop(stack, line_num);
		(*stack)->n /= div;
	}
}

/**
 * _mod - mod top of stack
 * @stack: pointer to lists for monty stack
 * @line_num: number of lines opcode occurs on
 */
void _mod(stack_t **stack, unsigned int line_num)
{
	int mod = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, satck too short\n", line_num);
		free(var_global.buffer);
		fclose(var_global.file);
		free_listint(*stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		free(var_global.buffer);
		fclose(var_global.file);
		free_listint(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		mod = (*stack)->n;
		_pop(stack, line_num);
		(*stack)->n %= mod;
	}
}
