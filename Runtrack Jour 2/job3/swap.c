#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>

void swap(int *a, int *b) 
{
    int ex = *a;
    *a = *b;
    *b = ex;
}


int main()
{
    int nb1 = 0, nb2 = 1;
    swap(&nb1, &nb2);
    printf("%i\n", nb1);
    printf("%i\n", nb2);
    return 0;
}