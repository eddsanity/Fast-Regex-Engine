#include "../include/utility.h"
#include <stdio.h>
#include <string.h>

void
main()
{
    char* test_cases[4] = {"abc", "ab|c", "ab+c", "a(bb)+c"};
    char* accepted_output[4] = {"a.b.c", "a.b|c", "a.b+.c", "a.(b.b)+.c"};

    int N = 0;
    while(N < 4)
    {
	if(strcmp(test_cases[N], accepted_output[N]))
	    printf("TEST %d %-3PASSED\n", N+1);
	else
	    printf("TEST %-3d FAILED\nOUTPUT: %-10s\nEXPECTED: %-10s\n", N+1, re_format(test_cases[N]), accepted_output[N]);
	printf("%-10s: %s\n", "OUTPUT", re_format(test_cases[N]));
	printf("%-10s: %s\n", "EXPECTED", accepted_output[N]);
	N++;
    }

    getchar();
}
