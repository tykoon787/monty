#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _GNU_SOURCE

int main(void)
{
    FILE *fp;
    size_t len = 0;
    ssize_t nread;
    char *buffer = NULL;

    fp = fopen("00.m", "r");
    if (fp == NULL)
        perror("Error Opeining File \n");
    
    while ((nread = getline(&buffer, &len, fp)) != -1)
    {
        printf("Received %s", buffer);
        for (int i = 0; i < nread; i++)
        {
            if (buffer[i] == '\n')
                buffer[i] = '\0';
        }
        char *tokenized = strtok(buffer, " ");
        printf("Token Received [%s]\n", tokenized);
    }

    free(buffer);
    fclose(fp);
    exit(EXIT_SUCCESS);
    return 0;
}