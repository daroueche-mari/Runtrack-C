#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>


void increment(int *n)
{
    printf("%i\n", *n);
}


int main()
{
    int test = 55;
    increment(&test);
    return 0;
}