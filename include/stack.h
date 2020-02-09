#ifndef STACK_H
#define STACK_H

/*  A simple implementation of a stack needed to facilitate the conversion from infix to postfix.
 *  Push and Pop functions do not handle overflow/underflow yet.
 */
#include <stddef.h>

#define const_stack_size 1024

char stack[const_stack_size];
int  stack_top = -1;

void
stack_push(char);

char
stack_pop();

char
stack_peek();

size_t
stack_size();

#endif
