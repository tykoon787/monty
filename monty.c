#include "monty_interpreter.h"
#include "op_funcs.h"
#include "monty.h"
#include "callFuncs.h"

/**
 * main - Entry Point
 * @argc: Argument Count
 * @argv: Arguments
 * Return: (0) on Success
*/
int main(int argc, char *argv[])
{
	stack_t **stack;

	stack = (stack_t **)malloc(sizeof(stack_t));
	if (!stack)
	{
		fprintf("Malloc Failed\n");
		exit(EXIT_FAILURE);
	}

	if (argc < 2)
	{
		fprintf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	else
		interpreter(stack, argv[1]);

	return (0);
}
