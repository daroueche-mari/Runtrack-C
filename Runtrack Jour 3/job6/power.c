#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>


// Calcule n^p (n puissance p)
int power(int n, int p)
{
    int result = 1;
    if (p < 0) // Pas de puissance négative autorisée
        return 0;
    while (p > 0)
    {
        result *= n;
        p--;
    }
    return result;
}


int main()
{
    int n = 2;
    int p = 3;
    printf("%d^%d = %d\n", n, p, power(n, p));
}