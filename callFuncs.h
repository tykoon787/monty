#ifndef CALL_FUNCS
#define CALL_FUNCS

#include "op_funcs.h"
#include "monty_interpreter.h"
#include "monty.h"
#include <stdio.h>
#include <string.h>

/**
 * pushCall - Function that calls the push Function
 * @stack: Stack to be manipulated
 * @line_number: Line Number
 * Return: Nothing
*/
void pushCall(stack_t **stack, int line_number)
{
	void (*func)(stack_t **, unsigned int) = NULL;

	func = getFunction("push");
	if (func)
		func(stack, line_number);
}

/**
 * popCall - Function that calls the pop function
 * @stack: Stack to be manipulated
 * @line_number: Line Number
 * Return: Nothing
*/
void popCall(stack_t **stack, int line_number)
{
	void (*func)(stack_t **, unsigned int) = NULL;

	func = getFunction("pop");
	if (func)
		func(stack, line_number);
}

/**
 * pallCall - Function that calls the pall()
 * @stack: Stack to be manipulated
 * @line_number: Line Number
 * Return: Nothing
*/
void pallCall(stack_t **stack, int line_number)
{
	void (*func)(stack_t **)(unsigned int) = NULL;

	func = getFunction("pall");
	if (func)
		func(stack, line_number);
}

/**
 * getFunction - Gets a function and returns it to the function pointer
 * @opcode: opcode received
 * Return: Nothing
*/
void *getFunction(const char *opcode)
{
	if (strcmp(opcode, "push") == 0)
		return (&push);
	if (strcmp(opcode, "pop") == 0)
		return (&pop);
	if (strcmp(opcode, "pall") == 0)
		return (&pall);
	return (NULL);
}

#endif /* CALL_FUNCS */
