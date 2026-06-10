#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>

// Calcule la factorielle de n récursivement
int factorial(int n)
{
    if (n < 0) // Factorielle négative impossible
        return 0;

    if (n == 0) // 0! = 1
        return 1;

    return n * factorial(n - 1); // Appel récursif
}

int main()
{
    int n = 5;
    printf("%d! = %d\n", n, factorial(n));
}