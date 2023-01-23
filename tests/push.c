#include "monty.h"

stack_t *top = NULL;
stack_t *head = NULL;

void push(int x)
{

	if (head == NULL)
		printf("Empty List\n");
	stack_t *newNode; 
	newNode = (stack_t *)malloc(sizeof(stack_t));
	newNode->n = x;
	newNode->prev = NULL;
	newNode->next = NULL;
}
