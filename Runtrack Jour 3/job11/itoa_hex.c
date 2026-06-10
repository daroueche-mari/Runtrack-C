#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>


// Convertit un int en hexadécimal (A-F)
char *itoa_hex(int n)
{
    char hex[] = "0123456789ABCDEF";
    int tmp = n;
    int len = 1;
    // Compte le nombre de digits hex
    while (tmp >= 16)
    {
        tmp /= 16;
        len++;
    }
    char *str = malloc(len + 1);
    if (!str)
        return NULL;
    str[len] = '\0';
    // Conversion en hex depuis la fin
    while (len--)
    {
        str[len] = hex[n % 16];
        n /= 16;
    }
    return str;
}

int main()
{
    int n = 1234;
    char *str = itoa_hex(n);
    printf("%s\n", str);
    free(str);
}