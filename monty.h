#ifndef MONTY_H
#define MONTY_H

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
		int n;
		struct stack_s *prev;
		struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
		char *opcode;
		void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Global Variables */
extern instruction_t instructions[];
extern stack_t **stack, *head, *top;

/* ==== FUNCTIONS =====*/

void interpreter(stack_t **stack, char *filename);
void *createNode(int x);
void push(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void errorCheck(int line_number, char *instruction);
void pushCall(stack_t **stack, int line_number);
void popCall(stack_t **stack_t, int line_number);
void pintCall(stack_t **stack, int line_number);
int pushError(char *rcvd_value, int line_number);

#endif /* MONTY_H */
