#include "stack.h"

// ordinary stack push and pop, pretty self-explanatory

void
stack_push(char c)
{
    if(stack_top >= stack_size - 1)
    {    /* handle stack overflow, do nothing for now. */ }
    else
    {
	stack_top++;
	stack[stack_top] = c;
    }
}

char
stack_pop()
{
    if(stack_top < 0)
    {
	/* handle stack underflow, do nothing for now. */
	// underflow could occur because of unmatched parenthesis.
    }
    else
	// return the character at the top of the stack then decrement the stack pointer, effectively popping.
	return stack[stack_top--];
}

