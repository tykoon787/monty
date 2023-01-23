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

int main(int argc, char *argv[])
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

	if (argc < 2)
		printf("usage msg\n");
	else
	{
		/* open file for reading */
		printf("opening file: [%s] \n", argv[1]);
		fd = open(argv[1], O_RDONLY);

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
						if (strcmp(opcode, "push") == 0)
						{
							/* get the value to push*/
							char *value = strtok(NULL, " ");

							/* convert the value to an int*/
							int converted_value = strtol(value, NULL, 10);
							printf("opcode received: [%s]\n", opcode);
							printf("value: [%d]\n", converted_value);

							/* call to push*/
							printf("call to push with value: [%d]\n", converted_value);
							instructions[0].f(stack, converted_value);
						}

						/* tokenize buffer to check for pop */
						else if (strcmp(opcode, "pop") == 0)
						{
							printf("function pop called \n");
						}

						/* tokenize buffer to check for pall */
						else if (strcmp(opcode, "pall"))
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
	}
	close(fd);
	return 0;
}
