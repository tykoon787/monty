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
	if (argc < 2)
		printf("Usage Msg\n");
	else
		interpreter(argv[1]);

	return (0);
}