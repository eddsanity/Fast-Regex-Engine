#include "utility.h"

char*
re_format(char* ufInput)
{
    const char dot = '.';
    char* output;
    int in_length = strlen(ufInput);

    for(int i = 0; i < in_length; ++i)
    {
	char current_char = ufInput[i];

	// if current_char isn't the last character in ufInput
	if(i + 1 < in_length)
	{
	    char next_char = ufInput[i+1];
	    strncat(output, &current_char, 1);

	    if(current_char != '(' && next_char != ')' && !re_isOperator(next_char))
		strncat(output, &dot, 1);
	}
    }
    strncat(output, ufInput[in_length - 1], 1);

    return output;
}


bool
re_isOperator(char c)
{
    if(c == '+' || c == '^' || c == '*' || c == '|' || c == '?' || c == '.' || c == '(')
	return true;
    else return false;
}


// lower numbers are higher precedence
int
re_getPrecedence(char op)
{
    if(op == '(')
	return 0;
    if(op == '|')
	return 1;
    if(op == '.')
	return 2;
    if(op == '?' || op == '*' || op == '+')
	return 3;
    if(op == '^')
	return 4;
}
