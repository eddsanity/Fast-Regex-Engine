#include "regex.h"

/*
 * This is an implementation of Ken Thompson's Regular Expressions engine.
 * It was introduced in his 1968 CACM paper.
 * This implementation compiles Regular Expressions to Non-Deterministic Finite Automatas (NFA)
 * I do not intellectually own the technique.
 */

/*  Currently, this implementation only implements the repetition metacharacters ('+', '?', '*')
 *  And concatenation/alteration ("AND"/"OR")
 *  All of which can be represented with a partial NFA that has only two (or less) arrows going out of it
 *  i.e only two decisions to make
 *  This is the reasoning behind every state having only two pointers to other states.
 *  
 *   `fragment_type` determines the "structure" of the state.
 *   If `fragment_type` <= 2^8 - 1 (possible extended ASCII characters), then this state has only one outward transition
 *   If `fragment_type` == 2^8, then this state is a split state (has two outward transitions)
 *   If `fragment_type` == 2^8 + 1, then this state is an accepting state (a correct match)
 *   
 *                                      __
 *         (ASCII char)         |      /   <out_up>   |
 *    <S> ==============> <out> | <S> =               |      <AC>
 *                              |      \__ <out_down> |
 *        f_t <= 2^8 - 1                f_t = 2^8         f_t = 2^8 + 1   
 *   f_t = fragment_type
 */

typedef 
struct re_state
{
    int fragment_type;
    struct re_state* out_up;
    struct re_state* out_down;
    int lastList;
} re_state;


/*  In the paper, Ken converts the input infix regex into postfix as to make operating on them easier.
 *  This might be possible to do without such a conversion but the point is to implement Ken's paper.
 *  Therefore, a function, `re_infix2postfix` is needed to convert infix regex into postfix which will be used
 *  to construct the NFA.
 *  Conversion from infix to postfix regex works pretty much the same way as it does with arithmetic.
 */

/*  Also: Ken uses the `.` (Dot) character as an explicit concatenation operator, unlike modern regex engines
 *  that use it as the `match zero-or-more` operator.
 */

char*
re_infix2postfix(char* regex)
{
    stack* st = init_stack();
    
    // format the input regular expression
    // i.e add explicit concatenation operator
    char* formatted_regex = re_format(regex);

    size_t formatted_length = strlen(formatted_regex);
    size_t parenthesis_count = re_parenthesisCount(formatted_regex);
    
    // the postfix expression discards parenthesis so its length is the original expression's length - # of parenthesis
    size_t postfix_length = formatted_length - parenthesis_count;
    char* postfix_regex = (char*)malloc((postfix_length + 1) * sizeof(char));

    size_t postfixPtr = 0;

    for(size_t i = 0; i < formatted_length; ++i)
    {
	char curr_char = formatted_regex[i];
	/*  Standard infix to postfix conversion algorithm
	 *  1. Scan characters
	 *  2. If,
	 *  2.1 Character is '(', push it onto stack
	 *  2.2 Character is ')', pop the stack into output until ')' is matched with a '('
	 *  2.3 Else,
	 *  3.1 If character is an operator and stack is empty, push operator onto stack and continue scanning
	 *  3.1.1 Else if operator and stack isn't empty, peek the stack's top.
	 *        pop the stack into the output as long as the stack's top has greater or equal precedence as
	 *        scanned character.
	 *        push the scanned character after the popping is over.
	 *  3.1.2 If scanned isn't an operator, append to output
	 */
	switch(curr_char)
	{
	case '(':
	    stack_push(st, curr_char);
	    break;
	case ')':
	    while(stack_peek(st) != '(')
		postfix_regex[postfixPtr++] = stack_pop(st);
	    stack_pop(st);
	    break;
	default:
	    if(re_isOperator(curr_char))
	    {
		char top = stack_peek(st);

		int top_precedence = re_getPrecedence(top);
		int curr_precedence = re_getPrecedence(curr_char);
		    
		while(top_precedence >= curr_precedence && top != '(')
		{
		    postfix_regex[postfixPtr++] = stack_pop(st);
		    top = stack_peek(st);
		    top_precedence = re_getPrecedence(top);
		}
		stack_push(st, curr_char);
	    }
	    else
		postfix_regex[postfixPtr++] = curr_char;
	    break;
	}
    }

    // left-over stack content (scanning is over and stack still not empty)
    while(stack_size(st) >= 0)
	postfix_regex[postfixPtr++] = stack_pop(st);
    postfix_regex[postfix_length] = '\0';

    free(st);
    
    return postfix_regex;
}

