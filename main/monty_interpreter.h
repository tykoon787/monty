#ifndef monty_interpreter_h
#define monty_interpreter_h

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* user files */
#include "monty.h"
#include "op_funcs.h"
#include "callFuncs.h"

/* sys call*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/* strstr */
#include <string.h>

/**
 * interpreter - Monty File Interpreter
 * @filename: File containing instructions
 * Return: Nothing
*/
void interpreter(char *filename)
{
	FILE *fp;
	int line_number = 1;
	ssize_t bytes_read;
	char *line_buffer = (char *)malloc(sizeof(char) * 1096);
	size_t len = sizeof(line_buffer);
	char *opcode;

	/* open file for reading */
	printf("opening file: [%s] \n", filename);
	fp = fopen(filename, "r");

	/* check if file was opened successfully */
	if (fp == NULL)
		printf("error opeining file");
	else
	{
		while ((bytes_read = getline(&line_buffer, &len, fp)) > 0)
		{
			for (int i = 0; i < bytes_read; i++)
			{
				if (line_buffer[i] == '\n')
				{
					line_buffer[i] = '\0';
					opcode = strtok(line_buffer, " ");
					if (strcmp(opcode, "push") == 0)
						pushCall(line_number);
					else if (strcmp(opcode, "pop") == 0)
						popCall(line_number);
					else if (strcmp(opcode, "pall") == 0)
						pallCall(line_number);
					errorCheck(line_number, opcode);
					line_number++;
				}
			}
		}
	}
	fclose(fp);
}
#endif /* monty_interpreter */
