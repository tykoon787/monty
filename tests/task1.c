#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

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
						line_number++;
						line_buffer_index = 0;
						// Insert code for error checking
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
