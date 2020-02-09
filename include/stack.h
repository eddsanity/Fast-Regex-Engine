#ifndef STACK_H
#define STACK_H

/*  A simple implementation of a stack needed to facilitate the conversion from infix to postfix.
 *  Push and Pop functions do not handle overflow/underflow yet.
 */
#include <stddef.h>
#include <stdlib.h>

#define const_stack_size 1024

typedef
struct Stack
{
    char s[const_stack_size];
    int  stack_top;
} stack;

stack*
init_stack();

void
stack_push(stack*, char);

char
stack_pop(stack*);

char
stack_peek(stack*);

size_t
stack_size(stack*);

#endif
