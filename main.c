#include "monty.h"

/**
 * main - monty function
 * @argc: number of arguments
 * @argv: opcode file
 * Return: 0, success
 */
int main(int argc, char **argv)
{
	stack_t *stack;

	stack = NULL;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	read_file(argv[1], &stack);
	free_listint(stack);
	return (0);
}
