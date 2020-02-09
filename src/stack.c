#include "stack.h"

stack*
init_stack()
{
    stack* out_stack = (stack*)malloc(sizeof(stack));
    out_stack->stack_top = -1;
    return out_stack;
}

// ordinary stack push and pop, pretty self-explanatory

void
stack_push(stack* st, char c)
{
    if(st->stack_top >= const_stack_size - 1)
    {    /* handle stack overflow, do nothing for now. */ }
    else
	st->s[st->stack_top++] = c;
}

char
stack_pop(stack* st)
{
    if(st->stack_top < 0)
    {
	/* handle stack underflow, do nothing for now. */
	// underflow could occur because of unmatched parenthesis.
    }
    else
	// return the character at the top of the stack then decrement the stack pointer, effectively popping.
	return st->s[st->stack_top--];
}

char
stack_peek(stack* st)
{
    return st->s[st->stack_top];
}

size_t
stack_size(stack* st)
{
    return st->stack_top;
}
