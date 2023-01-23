#include "monty.h"

stack_t *top = NULL;
stack_t *head = NULL;

/**
* createNode - Function to Create a Node 
* @x: value to be pushed 
*/

void push(int x)
{
	stack_t *newNode;
	newNode = (stack_t *)malloc(sizeof(stack_t));
	newNode->prev = NULL;
	newNode->next = NULL;
	newNode->n = x;
	if (head == NULL)
	{
		head = top = newNode;
	}
	else
	{
		newNode->prev = top;
		top->next = newNode;
		top = newNode;
	}
}

/**
 * pop - Function to pop from stack;
 * return: nothing
*/
void pop()
{
	stack_t *temp;
	if (top=NULL)
		printf("Empty Stack\n");
	else
	{
		temp = top;
		top->prev->next = NULL;
		top = temp->prev;
		free(temp);
	}
}

/**
 * pall - Function to print the values
 * return: nothing
*/
void pall()
{
	stack_t *temp;
	temp = head;
	while (temp != NULL)
	{
		printf("Value: %d \n", temp->data);
		temp = temp -> next;
	}
	free (temp);
}