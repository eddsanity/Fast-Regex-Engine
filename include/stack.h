#ifndef STACK_H
#define STACK_H

/*  A simple implementation of a stack needed to facilitate the conversion from infix to postfix.
 *  Push and Pop functions do not handle overflow/underflow yet.
 */

#define stack_size 1024

char stack[stack_size];
int  stack_top = -1;

void
stack_push(char);

char
stack_pop();

#endif
