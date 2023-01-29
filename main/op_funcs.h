#ifndef OP_FUNCS
#define OP_FUNCS

#include "monty.h"
#include "monty_interpreter.h"
#include "callFuncs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern stack_t **stack;

const char *VALID_INSTRUCTIONS[] = {"push", "pall", "pop"};

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

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *head = NULL, *top = NULL;
	char *rcvd_value = strtok(NULL, " ");
	int converted_value = strtol(rcvd_value, NULL, 10);
	stack_t *newNode = (stack_t *)createNode(converted_value);

	if (head == NULL)
		head = top = newNode;
	else
	{
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
void pop(stack_t **stack, unsigned int line_number)
{
	/* Popping Function */
	stack_t *temp, *head = NULL, *top = NULL;

	if (head == NULL || top == NULL)
		printf("Empty Stack\n");
	else
	{
		/**
		 *  The goal here it to break the link from temp
		*/
		temp = top;
		top->prev->next = NULL;
		top = temp->prev;
	}
	free(temp);
}

/**
 * pall - Function to print the values
 * @stack: A pointer to a Pointer of a stack
 * @line_number: Line number
*/
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *head = NULL, *top = NULL;

	temp = head;
	if (head == NULL)
		printf("Empty Stack. Nothing to display\n");
	while (temp != NULL)
	{
		printf("Value: %d \n", temp->n);
		temp = temp->next;
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
		printf("L%d: Unknown Instruction '%s'\n", line_number, instruction);
		exit(EXIT_FAILURE);
	}
}

#endif /* OP_FUNCS */
