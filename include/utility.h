#ifndef UTILITY_H
#define UTILITY_H

#include <stdlib.h>
#include <string.h>
#include <stddef.h>

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

size_t
re_parenthesisCount(char*);

#endif
