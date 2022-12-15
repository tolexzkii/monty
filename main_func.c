#include "monty.h"

/**
 * is_number - checks if string is a number
 * @str: string being passed
 * Return: 1 if string is a number, otherwise 0
 */
int is_number(char *str)
{
	unsigned int i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[0] == '-')
		{
			i++;
			continue;
		}
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

/**
 * parse_line - parse a line for an opcode and arguments
 * @line: line to be parsed
 * @stack: pointer to the head of the stack
 * @line_num: current line number
 * Return: opcode, or NULL if fail
 */
char *parse_line(char *line, stack_t **stack, unsigned int line_num)
{
	char *opc, *push, *arg;
	(void)stack;

	opc = strtok(line, "\n ");
	push = "push";
	if (opc == NULL)
		return (NULL);

	if (strcmp(opc, push) == 0)
	{
		arg = strtok(NULL, "\n ");
		if (is_number(arg) == 1 && arg != NULL)
		{
			var_global.push_arg = atoi(arg);
		}
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_num);
			exit(EXIT_FAILURE);
		}
	}
	return (opc);
}

/**
 * get_op_func - checks opcode and return correct function
 * @str: opcode
 * Return: function, or NULL if fail
 */
instruct_func get_op_func(char *str)
{
	int i;

	inst_t instruct[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"mul", _mul},
		{"div", _div},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{NULL, NULL},
	};

	i = 0;
	while (instruct[i].f != NULL && strcmp(instruct[i].opcode, str) != 0)
	{
		i++;
	}

	return (instruct[i].f);
}

/**
 * read_file - reads a bytecode file and run commands
 * @filename: name of file
 * @stack: pointer to the top of the stack
 */
void read_file(char *filename, stack_t **stack)
{
	char *line;
	size_t i = 0;
	int line_count = 1;
	instruct_func a;
	int check;
	int read;

	var_global.file = fopen(filename, "r");

	if (var_global.file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&var_global.buffer, &i, var_global.file)) != -1)
	{
		line = parse_line(var_global.buffer, stack, line_count);
		if (line == NULL || line[0] == '#')
		{
			line_count++;
			continue;
		}
		a = get_op_func(line);
		if (a == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_count, line);
			exit(EXIT_FAILURE);
		}
		a(stack, line_count);
		line_count++;
	}
	free(var_global.buffer);
	check = fclose(var_global.file);
	if (check == -1)
		exit(-1);
}
