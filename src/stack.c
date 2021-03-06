#include "stack.h"

#define const_stack_size 1024

typedef
struct Stack
{
    char s[const_stack_size];
    int  stack_top;
} stack;


stack*
init_stack()
{
    stack* out_stack = (stack*)malloc(sizeof(stack));
    memset(out_stack, 0, const_stack_size);
    out_stack->stack_top = -1;
    return out_stack;
}

// ordinary stack push/pop/peek/size, pretty self-explanatory

void
stack_push(stack* st, char c)
{
    if(st->stack_top >= const_stack_size - 1)
    {    /* handle stack overflow, do nothing for now. */ }
    else
	st->s[++st->stack_top] = c;
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
    // does not handle peeking when stack is empty properly. Just returns the character 'a' for now as a work-around.
    if(st->stack_top < 0)
	return 'a';
    else
	return st->s[st->stack_top];
}

int
stack_size(stack* st)
{
    return st->stack_top;
}
