#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>

char to_lower(char c);
char to_upper(char c);
char switch_case(char c);

// Convertit toute la string en minuscules
void str_to_lower(char *s)
{
    int i = 0;
    while (s[i])
    {
        s[i] = to_lower(s[i]); // Réutilisation du Job 02
        i++;
    }
}

// Convertit toute la string en majuscules
void str_to_upper(char *s)
{
    int i = 0;
    while (s[i])
    {
        s[i] = to_upper(s[i]);
        i++;
    }
}

// Inverse la casse de toute la string
void str_switch_case(char *s)
{
    int i = 0;
    while (s[i])
    {
        s[i] = switch_case(s[i]);
        i++;
    }
}
