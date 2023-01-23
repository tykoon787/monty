#ifndef OP_FUNCS
#define OP_FUNCS

#include "monty.h"
#include "monty_interpreter.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

stack_t *top = NULL;
stack_t *head = NULL;

int getValue(int line_number)
{
	int value;
	return (value);
}

/**
 * createNode - Funcition to Create  a New Node
 * @x: Value to be inserted in New Node
 * return: Nothing
*/
void *createNode(int x)
{
	printf("Creating a Node with value [%d]\n", x);
	stack_t *newNode;
	newNode = (stack_t *)malloc(sizeof(stack_t));
	newNode->prev = NULL;
	newNode->next = NULL;
	newNode->n = x;
	return (newNode);
}
/**
* push - Function to push a node 
* @value: The value to be pushed
* @stack: A pointer to a Pointer of a stack 
* @line_number: Line number
*/

void push(stack_t **stack, unsigned int line_number)
{
	char *rcvd_value = strtok(NULL, " ");
	printf("received value: [%s]\n", rcvd_value);
	int converted_value = strtol(rcvd_value, NULL, 10);
	stack_t *newNode = createNode(converted_value);
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
	stack_t *temp;
	if (head == NULL || top == NULL)
		printf("Empty Stack\n");
	else
	{
		/**
		 *  The goal here it to break the link from temp
		*/
		temp = top;
		top->prev->next = NULL;
		printf("\nPopping value (%d)---- \n", (*temp).n);
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
	printf("\nDisplaying ===== \n");
	stack_t *temp;
	temp = head;
	if (head == NULL)
		printf("Empty Stack. Nothing to display\n");
	while (temp != NULL)
	{
		printf("Value: %d \n", temp->n);
		temp = temp -> next;
	}
	free (temp);
}

#endif /* OP_FUNCS */