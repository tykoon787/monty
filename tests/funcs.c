#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

stack_t *top = NULL;
stack_t *head = NULL;

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
* @x: value to be pushed 
*/

void push(int x)
{
	stack_t *newNode = createNode(x);
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
 * @x: Number of times to pop
 * return: nothing
*/
void pop(int x)
{
	int count = 0;
	while (count < x)
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
		count++;
	}
}

/**
 * pall - Function to print the values
 * return: nothing
*/
void pall()
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

int main()
{

	/* Pushing Values 10 - 100*/
	int i;
	while (i <= 100)
	{
		push(i);
		i += 10;
	}

	/* Displaying the stack */
	pall();
	pop(3);
	pall();
	pop(1);
	push(110);
	pall();
}