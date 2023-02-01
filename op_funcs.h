#ifndef OP_FUNCS
#define OP_FUNCS

#include "monty.h"
#include "monty_interpreter.h"
#include "callFuncs.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

const char *VALID_INSTRUCTIONS[] = {"push", "pint", "pop"};

/**
 * createNode - Funcition to Create  a New Node
 * @x: Value to be inserted in New Node
 * Return: A void pointer to newNode
*/
void *createNode(int x)
{
	stack_t *newNode;

	newNode = (stack_t *)malloc(sizeof(stack_t));
	if (newNode == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	newNode->prev = NULL;
	newNode->next = NULL;
	newNode->n = x;
	return (newNode);
}

/**
* push - Function to push a node
* @stack: A pointer to a Pointer of a stack
* @line_number: Line number
*/

void push(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *top, *newNode;
	char *rcvd_value = strtok(NULL, " ");
	int converted_value = pushError(rcvd_value, line_number);	
	if (converted_value == 0)
		exit(EXIT_FAILURE);
	printf("Value received in push %d\n", converted_value);

	newNode = (stack_t *)createNode(converted_value);
	if (*stack == NULL)
		*stack = top = newNode;
	else
	{
		top = *stack;
		while (top && top->next)
			top = top->next;
		newNode->prev = top;
		top->next = newNode;
		top = newNode;
	}
}

/**
 * pop - Function to pop from stack;
 * @stack: A pointer to a Pointer of a stack
 * @line_number: Line number
 * return: nothing
*/
void pop(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	/* Popping Function */
	stack_t *temp, *top;

	if (*stack == NULL)
		printf("Empty Stack\n");
	else
	{
		top = *stack;
		while (top && top->next)
			top = top->next;
		temp = top;
		top->prev->next = NULL;
		top = temp->prev;
	}
	free(temp);
}

/**
 * pint - Function to print the values
 * @stack: A pointer to a Pointer of a stack
 * @line_number: Line number
*/
void pint(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *temp = *stack;

	if (*stack == NULL)
		printf("Empty Stack. Nothing to display\n");

	else
	{
		while (temp && temp->next)
			temp = temp->next;
		while (temp)
		{
			printf("Value: %d \n", temp->n);
			temp = temp->prev;
		}
	}
	free(temp);
}

/**
 * errorCheck - Check for an invalid instruction
 * @line_number: Line number where the invlaid instruciton appears
 * @instruction: Instruction to be checked
*/
void errorCheck(int line_number, char *instruction)
{
	int i, is_valid = 0, INSTRUCTION_COUNT = 3;

	for (i = 0; i < INSTRUCTION_COUNT; i++)
	{
		if (strcmp(instruction, VALID_INSTRUCTIONS[i]) == 0)
		{
			is_valid = 1;
			break;
		}
	}
	if (!is_valid)
	{
		fprintf(stderr, "L%d: Usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
}

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

#endif /* OP_FUNCS */
