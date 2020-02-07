#ifndef UTILITY_H
#define UTILITY_H

typedef enum { false, true } bool;

// Just adds the explicit concatenation operator in the 'unformated input'.
char*
re_format(char* ufInput);

/* Checks if `c` is an operator. Returns true if it is, false otherwise.
 * operators are: `|`, `?`, `+`, `*`, `^` and `.` */
bool
re_isOperator(char c);

// returns the precedence of the input operator.
int
re_getPrecedence(char op);

#endif
