#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>


int *int_dup(int value)
{
    int *ret = malloc(sizeof(int));
    *ret = value;
    return ret;
}


int main()
{
    int *test = int_dup(55);
    printf("%i\n", *test);
    return 0;
}