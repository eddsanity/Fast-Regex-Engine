#ifndef UTILITY_H
#define UTILITY_H

#include "string.h"     // needed for `char* strncat`
#include <stdio.h>

typedef enum { false, true } bool;

// Just adds the explicit concatenation operator in the 'unformated input'.
char*
re_format(char*);

/* Checks if `c` is an operator. Returns true if it is, false otherwise.
 * operators are: `|`, `?`, `+`, `*`, `^` and `.` */
bool
re_isOperator(char);

// returns the precedence of the input operator.
int
re_getPrecedence(char);

#endif
