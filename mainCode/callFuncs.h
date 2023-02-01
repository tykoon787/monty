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
	instruction_t pushInstruction = {"push", &push};
	(*pushInstruction.f)(stack, line_number);
}

/**
 * popCall - Function that calls the pop function
 * @stack: Stack to be manipulated
 * @line_number: Line Number
 * Return: Nothing
*/
void popCall(stack_t **stack, int line_number)
{
	instruction_t popInstruction = {"pop", &pop};
	(*popInstruction.f)(stack, line_number);
}

/**
 * pintCall - Function that calls the pint()
 * @stack: Stack to be manipulated
 * @line_number: Line Number
 * Return: Nothing
*/
void pintCall(stack_t **stack, int line_number)
{
	instruction_t popInstruction = {"pop", &pint};
	(*popInstruction.f)(stack, line_number);
}

#endif /* CALL_FUNCS */
