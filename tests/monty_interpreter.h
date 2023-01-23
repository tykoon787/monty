#ifndef  MONTY_INTERPRETER_H 
#define  MONTY_INTERPRETER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* User Files */
#include "monty.h"
#include "op_funcs.h"

/* sys call*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/* strstr */
#include <string.h>

void interpreter(char *filename)
{
	int fd, line_number = 1, line_buffer_index = 0;
	ssize_t bytes_read;
	char buffer[4096], line_buffer[1096]; 
	char *opcode;
	stack_t **stack;

	instruction_t instructions[] = 
	{
		{"push", &push},
		{"pop", &pop},
		{"pall", &pall},
		{NULL, NULL}
	};

	/* open file for reading */
	printf("opening file: [%s] \n", filename);
	fd = open(filename, O_RDONLY);

	/* check if file was opened successfully */
	if (fd == -1)
		printf("error opeining file");
	else
	{
		while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0)
		{
			for (int i = 0; i < bytes_read; i++)
			{
				if (buffer[i] == '\n')
				{
					line_buffer[line_buffer_index] = '\0';
					printf("line %d: %s\n", line_number, line_buffer);
					/* Check for push, pop and pall*/
					char *opcode = strtok(line_buffer, " ");
					printf("Received opcode: [%s]\n", opcode);
					if (strcmp(opcode, "push") == 0)
					{
						printf("opcode received: [%s]\n", opcode);
						/* call to push*/
						instructions[0].f(stack, line_number);
					}

					/* tokenize buffer to check for pop */
					else if (strcmp(opcode, "pop") == 0)
					{
						printf("function pop called \n");
						instructions[1].f(stack, line_number);
					}

					/* tokenize buffer to check for pall */
					else if (strcmp(opcode, "pall") == 0)
					{
						printf("function pall called \n");
						instructions[2].f(stack, line_number);
					}
					// insert error checking code
					/*
					{
						error check
					}
					*/
					line_number++;
					line_buffer_index = 0;
				}
				else
				{
					line_buffer[line_buffer_index++] = buffer[i];
				}
			}
		}
	}
	close(fd);
}
#endif /* MONTY_INTERPRETER */
