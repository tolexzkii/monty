#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

extern int push_arg;

/**
 * struct stack_s - doubly linked list of a stack
 * @n: integer
 * @prev: points to the previous element of the stack
 * @next: points to the next element of the stack
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct inst_s - opcodes and its functions
 * @opcode: opcode
 * @f: function for opcode
 */
typedef struct inst_s
{
	char *opcode;
	void (*f)(stack_t ** stack, unsigned int line_num);
} inst_t;

/**
 * struct global_variable - opcode and function
 * @file: opcode
 * @push_arg: opcode function
 * @buffer: pointer
 */
typedef struct global_variable
{
	FILE *file;
	int push_arg;
	char *buffer;
} global_var;

extern global_var var_global;

void read_file(char *filename, stack_t **stack);
char *parse_line(char *line, stack_t **stack, unsigned int line_num);
typedef void (*instruct_func)(stack_t **stack, unsigned int line_num);
instruct_func get_op_func(char *str);
int is_number(char *str);

void _push(stack_t **stack, unsigned int line_num);
void _pall(stack_t **stack, unsigned int line_num);
void _pint(stack_t **stack, unsigned int line_num);
void _pop(stack_t **stack, unsigned int line_num);
void _swap(stack_t **stack, unsigned int line_num);
void _nop(stack_t **stack, unsigned int line_num);
void _rotl(stack_t **stack, unsigned int line_num);
void _rotr(stack_t **stack, unsigned int line_num);


void _sub(stack_t **stack, unsigned int line_num);
void _add(stack_t **stack, unsigned int line_num);
void _div(stack_t **stack, unsigned int line_num);
void _mul(stack_t **stack, unsigned int line_num);
void _mod(stack_t **stack, unsigned int line_num);

void _pchar(stack_t **stack, unsigned int line_num);
void _pstr(stack_t **stack, unsigned int line_num);

void dobfree(stack_t **stack);
void free_listint(stack_t *head);
void dobf(stack_t **stack);
int _isalpha(int i);

#endif
