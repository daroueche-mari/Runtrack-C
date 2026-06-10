#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>


// Version itérative du Fibonacci
int fibonacci_it(int n)
{
    int a = 0;
    int b = 1;
    int tmp;
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    while (n > 1)
    {
        tmp = a + b;
        a = b;
        b = tmp;
        n--;
    }
    return b;
}

// Version récursive du Fibonacci
int fibonacci_rec(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fibonacci_rec(n - 1) + fibonacci_rec(n - 2);
}

int main()
{
    int n = 10;
    printf("%d\n", fibonacci_it(n));
    printf("%d\n", fibonacci_rec(n));
}
