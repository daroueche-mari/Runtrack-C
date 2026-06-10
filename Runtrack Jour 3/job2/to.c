#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>

char to_lower(char c)
{
    if (c >= 'A' && c <= 'Z')
        return c + 32;
}

char to_upper(char c)
{
    if (c >= 'a' && c <= 'z')
        return c - 32;
    return c;
}

char switch_case(char c)
{
    if (c >= 'a' && c <= 'z')
        return to_upper(c);
    if (c >= 'A' && c <= 'Z')
        return to_lower(c);
    return c;
}


int main()
{
    char test = 'A';
    printf("test des fonctions : %c %c %c", to_lower(test), to_upper(test), switch_case(test));
}
