#include "regex.h"

/*
 * This is an implementation of Ken Thompson's Regular Expressions engine.
 * It was introduced in his 1968 CACM paper.
 * This implementation compiles Regular Expressions to Non-Deterministic Finite Automatas (NFA)
 * I do not intellectually own the technique.
 */

/*  Currently, this implementation only implements the repetition metacharacters ('+', '?', '*')
 *  And concatenation/alteration (AND/OR)
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
    
}

