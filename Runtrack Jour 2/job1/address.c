#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>


void print_address(int *n)
{
    write(1, &n, sizeof(&n));
}


int main()
{
   int test = 55;
   print_address(&test);
   return 0;
}