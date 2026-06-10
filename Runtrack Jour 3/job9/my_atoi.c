#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>


// Convertit une string en int (version simplifiée)
int my_atoi(char *str)
{
    int i = 0;
    int sign = 1;
    int result = 0;
    // Gestion du signe
    if (str[i] == '-')
    {
        sign = -1;
        i++;
    }
    // Conversion chiffre par chiffre
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return result * sign;
}


int main()
{
    char *str = "1234";
    printf("%d\n", my_atoi(str));
}