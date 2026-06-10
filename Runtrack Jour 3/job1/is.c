#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>

int is_digit(char c)
{
    if (c >= '0' && c <= '9')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int is_lower(char c)
{
     if (c >= 'a' && c <= 'z')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int is_upper(char c)
{
     if (c >= 'A' && c <= 'Z')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int is_alpha(char c)
{
    if (is_lower(c) || is_upper(c))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int is_print(char c)
{
    if (c >= 32 && c <= 126)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


int main()
{
    char test = 'A';
    printf("test des fonctions : %d %d %d %d %d", is_digit(test), is_lower(test), is_upper(test), is_alpha(test), is_print(test));
}