#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>


void divide(int *val)
{
    *val /= 2;
}



int main()
{
    int test = 55;
    divide(&test);
    printf("%i\n", test);
    return 0;
}