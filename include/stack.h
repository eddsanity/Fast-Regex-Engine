#ifndef STACK_H
#define STACK_H

/*  A simple implementation of a stack needed to facilitate the conversion from infix to postfix.
 *  Push and Pop functions do not handle overflow/underflow yet.
 */
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

typedef struct Stack stack;

stack*
init_stack();

void
stack_push(stack*, char);

char
stack_pop(stack*);

char
stack_peek(stack*);

int
stack_size(stack*);

#endif
