#ifndef OP_FUNCS2_H
#define OP_FUNCS2_H

#include "op_funcs.h"
#include <errno.h>

/**
 * pushError - Checks for a push error
 * @rcvd_value: Value will be checked if its an int
 * @line_number: Line number where error occurs
 * Return: (converted value) on Success or (0) on error
*/
int pushError(char *rcvd_value, int line_number)
{
	int converted_value;
	char *endptr;

	errno = 0;
	if (rcvd_value == NULL)
	{
		fprintf(stderr, "L%d: Usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	converted_value = strtol(rcvd_value, &endptr, 10);
	if (errno == ERANGE || *endptr != '\0')
	{
		fprintf(stderr, "L%d: Usage: push integer\n", line_number);
		exit(EXIT_FAILURE);	
	}
	return (converted_value);
}
#endif /* OP_FUNCS2_H */
