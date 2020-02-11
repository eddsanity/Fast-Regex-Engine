#include "../include/regex.h"
#include <stdio.h>
#include <string.h>

#define NUMBER_OF_TESTS 5

void
main()
{
    char* test_cases[NUMBER_OF_TESTS] = {"abc", "ab|c", "ab+c", "a(bb)+c", "abc(aa*)"};
    char* accepted_output[NUMBER_OF_TESTS] = {"ab.c.", "ab.c|", "ab+.c.", "abb.+.c.", "ab.c.aa*.."};

    int N = 0;
    while(N < NUMBER_OF_TESTS)
    {
	if(strcmp(re_infix2postfix(test_cases[N]), accepted_output[N]) == 0)
	    printf("TEST %d %-3s\n", N+1, "PASSED");
	else
	    printf("TEST %d %-3s\n", N+1, "FAILED");
	printf("%-10s: %s\n", "INPUT", test_cases[N]);
	printf("%-10s: %s\n", "OUTPUT", re_infix2postfix(test_cases[N]));
	printf("%-10s: %s\n", "EXPECTED", accepted_output[N]);
	N++;
    }

    getchar();
}
