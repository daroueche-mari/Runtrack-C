#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>

// putstr
void putstr(char *s)
{
    while (*s)
        write(1, s++, 1);
}
// my_atoi
int my_atoi(char *s)
{
    int i = 0, sign = 1, n = 0;
    if (s[i] == '-')
    {
        sign = -1;
        i++;
    }
    while (s[i] >= '0' && s[i] <= '9')
        n = n * 10 + (s[i++] - '0');
    return n * sign;
}

// my_itoa (version courte)
char *my_itoa(int n)
{
    char buf[20];
    int i = 0, sign = n < 0;
    if (n == 0)
        return strdup("0");
    if (sign)
        n = -n;
    while (n)
    {
        buf[i++] = (n % 10) + '0';
        n /= 10;
    }
    if (sign)
        buf[i++] = '-';
    char *res = malloc(i + 1);
    for (int j = 0; j < i; j++)
        res[j] = buf[i - j - 1];
    res[i] = '\0';
    return res;
}

// itoa_hex
char *itoa_hex(int n)
{
    char hex[] = "0123456789ABCDEF", buf[20];
    int i = 0;
    if (n == 0)
        return strdup("0");
    while (n)
    {
        buf[i++] = hex[n % 16];
        n /= 16;
    }
    char *res = malloc(i + 1);
    for (int j = 0; j < i; j++)
        res[j] = buf[i - j - 1];
    res[i] = '\0';
    return res;
}

// factorial
int factorial(int n) { return (n <= 1) ? 1 : n * factorial(n - 1); }
// fibonacci_it
int fibonacci_it(int n)
{
    if (n <= 1)
        return n;
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

// MAIN
int main()
{
    char *str = "1234";
    printf("%d\n", my_atoi(str));
    printf("%s\n", my_itoa(1234));
    printf("%s\n", itoa_hex(1234));
    printf("%d\n", factorial(5));
    printf("%d\n", fibonacci_it(10));
}