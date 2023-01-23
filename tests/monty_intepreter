#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* SYS CALL*/
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
	if (argc < 2) 
		printf("Usage Msg\n");
	else
	{
		/* Open file for reading */
		printf("Opening file: [%s] \n", argv[1]);
		fd = open(argv[1], O_RDONLY);

		/* Check if file was opened successfully */
		if (fd == -1)
			printf("Error opeining file");
		else
		{
			while((bytes_read = read(fd, buffer, sizeof(buffer))) > 0)
			{
				for (int i = 0; i < bytes_read; i++)	
				{
					if (buffer[i] == '\n')
					{
						line_buffer[line_buffer_index] = '\0';
						printf("Line %d: %s\n", line_number, line_buffer);
						
						/* Tokenize Buffer to check for push */
						/* This check is used to determine if the strin "push" is present at the beginning of the 
						buffer. 
						
						This is done by Compare the return value of strstr() to the original buffer */
						char *p = strstr(line_buffer, "push");
						if ((p))
						{
							/*move pointer to the location of the value in the buffer*/
							p = p + strlen("push"); // p += strlen("push")

							/*convert the value in the buffer to an interger using strtol()*/
							int value = strtol(p, NULL, 10);

							/* Push Value to the stack )*/
							printf("Function to push with value %d \n", value);
						}

						/* Tokenize Buffer to check for pop */
						else if (strstr(line_buffer, "pop") == line_buffer)
						{
							printf("Function Pop Called \n");
						}

						/* Tokenize Buffer to check for pall */
						else if (strstr(line_buffer, "pall") == line_buffer)
						{
							printf("Function Pall Called \n");
						}
						// Insert Error Checking Code 
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
	close (fd);
	return 0;
}
