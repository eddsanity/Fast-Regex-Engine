#ifndef REGEX_H
#define REGEX_H

#include <string.h>
#include <stdio.h>
#include "utility.h"
#include "stack.h"

typedef struct re_state re_state;
typedef union ptr_list ptr_list;
typedef struct nfa_fragment nfa_fragment;
typedef struct List list;

char*
re_infix2postfix(char*);

re_state*
re_postfix2nfa(char*);

bool
match(re_state*, char*);

void
re_init();

#endif
