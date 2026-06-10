#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>

// Convertit un int positif en string (malloc)
char *my_itoa(int n)
{
    int tmp = n;
    int len = 1;
    // Compte le nombre de chiffres
    while (tmp >= 10)
    {
        tmp /= 10;
        len++;
    }
    // Allocation de la string
    char *str = malloc(len + 1);
    if (!str)
        return NULL;
    str[len] = '\0'; // Fin de string
    // Remplissage depuis la fin
    while (len--)
    {
        str[len] = (n % 10) + '0';
        n /= 10;
    }
    return str;
}

int main()
{
    int n = 1234;
    char *str = my_itoa(n);
    printf("%s\n", str);
    free(str);
}