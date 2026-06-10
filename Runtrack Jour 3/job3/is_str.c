#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>

int str_is_digit(char *s)
{
    int i = 0;
    while (s[i] != '\0')
    {
        if (!(s[i] >= '0' && s[i] <= '9'))
            return 1;
        i++;
    }
    return 0;
}

int str_is_alpha(char *s)
{
    int i = 0;
    while (s[i] != '\0')
    {
        if (!((s[i] >= 'a' && s[i] <= 'z') ||
              (s[i] >= 'A' && s[i] <= 'Z')))
            return 1;
        i++;
    }
    return 0;
}

int str_is_print(char *s)
{
    int i = 0;
    while (s[i] != '\0')
    {
        if (!(s[i] >= 32 && s[i] <= 126))
            return 1;
        i++;
    }
    return 0;
}

int main()
{
    char test[] = "A";
    printf("test des fonctions : %d %d %d\n",
           str_is_alpha(test),
           str_is_digit(test),
           str_is_print(test));
}
