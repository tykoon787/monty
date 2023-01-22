#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * _push - pushes node to stack
 *
 * @x: data to be stored in new node
 *
 */

void _push(int x)
{
	stack_t *newnode;

	/* create new node and assign value/data */
	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
		printf("malloc failed\n");

	newnode->n = x;

	/* check if stack is empty or not */
	if (top == NULL)
	{
		newnode->next = NULL;
	}
	else
	{
		newnode->next = top;
		top->prev = newnode;
	}

	newnode->prev = NULL;
	top = newnode;

}

/**
 * _pall - prints contents of a stack
 *
 */

void _pall(void)
{
	stack_t *temp = top;

	if (top == NULL)
	{
		printf("Stack is empty\n");
		exit(1);
	}

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * _pop - removes an item from a stack
 *
 * Return: value of item removed
 */

int _pop(void)
{
	stack_t *temp = top;
	int val;

	if (top == NULL)
	{
		printf("stack is empty\n");
		return (1);
	}

	val = top->n;
	top = top->next;
	top->prev = NULL;
	free(temp);

	return (val);
}

/**
 * main - entry point
 *
 * Return: 0 for success
 */

int main(void)
{
	int a, b;

	_push(10);
	_push(20);
	_push(30);
	_push(40);
	_pall();

	a = _pop();
	printf("%d was revomed from the stack\n", a);

	b = _pop();
	printf("%d was revomed from the stack\n", b);

	_pall();

	return (0);
}
