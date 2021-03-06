#include "utility.h"

char*
re_format(char* ufInput)
{
    //preprocessing to count the size of output
 
    int in_length = strlen(ufInput);
    int out_length = in_length;
 
    for(int i = 0; i < in_length; ++i)
    {
        char curr_char = ufInput[i];
        if(i + 1 < in_length)
        {
            char next_char = ufInput[i+1];
 
            if(curr_char != '(' && next_char != ')' && !re_isOperator(next_char) && curr_char != '|')
                out_length++;
        }
    }
 
    int outPtr = 0;
    char* output = (char*)malloc(out_length * sizeof(char));
 
    for(int i = 0; i < in_length; ++i)
    {
        char curr_char = ufInput[i];
        if(i + 1 < in_length)
        {
            char next_char = ufInput[i+1];
            output[outPtr] = curr_char,outPtr++;
 
            if(curr_char != '(' && next_char != ')' && !re_isOperator(next_char) && curr_char != '|')
                output[outPtr] = '.',outPtr++;
        }
    }
    output[outPtr] = ufInput[strlen(ufInput)-1];
    output[out_length] = '\0';
 
    return output;
}


bool
re_isOperator(char c)
{
    if(c == '+' || c == '^' || c == '*' || c == '|' || c == '?' || c == '.')
	return true;
    else return false;
}


// lower number = lower precedence
int
re_getPrecedence(char op)
{
    if(op == '|')
	return 1;
    if(op == '.')
	return 2;
    if(op == '?' || op == '*' || op == '+')
	return 3;
    if(op == '^')
	return 4;
    return 0;
}


size_t
re_parenthesisCount(char* infixRegex)
{
    size_t pCount = 0;
    for(size_t i = 0; infixRegex[i] != 0; ++i)
	if(infixRegex[i] == '(' || infixRegex[i] == ')')
	    ++pCount;

    return pCount;
}
