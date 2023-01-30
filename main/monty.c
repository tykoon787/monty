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
	stacK_t *stack = NULL;
	stack = (stack_t*)malloc(sizeof(stack_t));
	if (!stack)
	{
		perror("Malloc Failed\n");
		exit(EXIT_FAILURE);
	}

	if (argc < 2)
		printf("Usage Msg\n");
	else
	/* To do: Pass stack as an argument to the interpreter*/
		interpreter(argv[1]);

	return (0);
}
