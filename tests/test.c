#include "../include/regex.h"
#include "../include/utility.h"
#include <stdio.h>
#include <string.h>
#include <stddef.h>

#define NUMBER_OF_TESTS 5

typedef enum {failed, passed} status;

char* test_cases[NUMBER_OF_TESTS] = {"abc", "ab|c", "ab+c", "a(bb)+c", "abc(aa*)"};

status
TEST_FORMATTING()
{
    char* accepted_output[NUMBER_OF_TESTS] = {"a.b.c", "a.b|c", "a.b+.c", "a.(b.b)+.c", "a.b.c.(a.a*)"};

    status test_status = passed;
    
    size_t idx = 0;
    printf("%-15sSTARTING %-25s=======\n","=======", "FORMATTING TESTS");
    while(idx < NUMBER_OF_TESTS)
    {
	if(strcmp(re_format(test_cases[idx]), accepted_output[idx]) == 0)
	   printf("TEST %d %-3s\n", idx+1, "PASSED");
	else
	{
	    printf("TEST %d %-3s\n", idx+1, "FAILED");
	    test_status = failed;
	}
	printf("%-10s: %s\n", "INPUT", test_cases[idx]);
	printf("%-10s: %s\n", "OUTPUT", re_format(test_cases[idx]));
	printf("%-10s: %s\n", "EXPECTED", accepted_output[idx]);
	idx++;
    }
    if(test_status == passed)
	printf("%-15s%s %-15s=======\n\n","=======", "FORMATTING TESTS", "PASSED");
    else
	printf("%-15s%s %-15s=======\n\n","=======", "FORMATTING TESTS", "FAILED");
    return test_status;
}

status
TEST_INFIX2POSTFIX()
{
    char* accepted_output[NUMBER_OF_TESTS] = {"ab.c.", "ab.c|", "ab+.c.", "abb.+.c.", "ab.c.aa*.."};

    status test_status = passed;

    size_t idx = 0;
    printf("%-15sSTARTING %-25s=======\n","=======", "INFIX2POSTFIX TESTS");
    while(idx < NUMBER_OF_TESTS)
    {
	if(strcmp(re_infix2postfix(test_cases[idx]), accepted_output[idx]) == 0)
	   printf("TEST %d %-3s\n", idx+1, "PASSED");
	else
	{
	    printf("TEST %d %-3s\n", idx+1, "FAILED");
	    test_status = failed;
	}
	printf("%-10s: %s\n", "INPUT", test_cases[idx]);
	printf("%-10s: %s\n", "OUTPUT", re_infix2postfix(test_cases[idx]));
	printf("%-10s: %s\n", "EXPECTED", accepted_output[idx]);
	idx++;
    }
    if(test_status == passed)
	printf("%-15s%s %-15s=======\n\n","=======", "INFIX2POSTFIX TESTS", "PASSED");
    else
	printf("%-15s%s %-15s=======\n\n","=======", "INFIX2POSTFIX TESTS", "FAILED");
    return test_status;    
}

void
main()
{
    status overall_status = passed;
    overall_status &= TEST_FORMATTING();
    overall_status &= TEST_INFIX2POSTFIX();
    
    if(overall_status == passed)
	printf("\n\nALL TESTS PASSED\n");
    else
	printf("\n\nTESTS FAILED\n");
    getchar();
}
