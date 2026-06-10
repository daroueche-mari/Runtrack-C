#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

// ------------------------------------------------------------
// Convertit un int en string (ta fonction my_itoa)
// ------------------------------------------------------------
char *my_itoa(int n)
{
    char buffer[50];
    int i = 0;
    bool neg = false;
    if (n == 0)
    {
        char *s = malloc(2);
        s[0] = '0';
        s[1] = '\0';
        return s;
    }
    if (n < 0)
    {
        neg = true;
        n = -n;
    }
    while (n > 0)
    {
        buffer[i++] = (n % 10) + '0';
        n /= 10;
    }
    if (neg)
        buffer[i++] = '-';
    buffer[i] = '\0';
    // On inverse la chaîne
    int len = i;
    char *s = malloc(len + 1);
    for (int j = 0; j < len; j++)
        s[j] = buffer[len - 1 - j];
    s[len] = '\0';
    return s;
}

// ------------------------------------------------------------
// Affiche un int en utilisant my_itoa
// ------------------------------------------------------------
void putnbr_int(int n)
{
    char *s = my_itoa(n);
    for (int i = 0; s[i]; i++)
        write(1, &s[i], 1);
    free(s);
}

// ------------------------------------------------------------
// Affiche un float avec 1 décimale, arrondi correctement
// Compatible nombres négatifs
// ------------------------------------------------------------
void putnbr_float(float f)
{
    // On multiplie par 10 et on arrondit
    int scaled = (int)(f * 10 + (f >= 0 ? 0.5 : -0.5));
    int int_part = scaled / 10;      // partie entière arrondie
    int dec_part = abs(scaled % 10); // chiffre après la virgule
    putnbr_int(int_part);
    write(1, ".", 1);
    putnbr_int(dec_part);
}

// ------------------------------------------------------------
// Programme principal
// ------------------------------------------------------------
int main()
{
    float f = 3.14159;
    putnbr_float(f); // Affiche : 3.1
    write(1, "\n", 1);
    float g = -2.71828;
    putnbr_float(g); // Affiche : -2.7
    write(1, "\n", 1);
    float h = 9.99;
    putnbr_float(h); // Affiche : 10.0 (arrondi correct)
    return 0;
}
