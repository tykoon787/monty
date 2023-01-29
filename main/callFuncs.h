#ifndef CALL_FUNCS
#define CALL_FUNCS

#include "op_funcs.h"
#include "monty_interpreter.h"
#include "monty.h"
#include <stdio.h>

extern instruction_t instructions[] = {
	{"push", &push},
	{"pop", &pop},
	{"pall", &pall},
	{NULL, NULL}
};

extern stack_t **stack;

/**
 * pushCall - Function that calls the push Function
 * @line_number: Line Number
 * Return: Nothing
*/
void pushCall(int line_number)
{
	instructions[0].f(stack, line_number);
}

/**
 * popCall - Function that calls the pop function
 * @line_number: Line Number
 * Return: Nothing
*/
void popCall(int line_number)
{
	instructions[1].f(stack, line_number);
}

/**
 * pallCall - Function that calls the pall()
 * @line_number: Line Number
 * Return: Nothing
*/
void pallCall(int line_number)
{
	instructions[2].f(stack, line_number);
}

#endif /* CALL_FUNCS */
