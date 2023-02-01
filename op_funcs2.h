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
	converted_value = strtol(rcvd_value, &endptr, 10);
	if (errno == ERANGE || *endptr != '\0')
	{
		fprintf(stderr, "L%d: Usage: push integer\n", line_number);
		return (0);
	}
	return (converted_value);
}