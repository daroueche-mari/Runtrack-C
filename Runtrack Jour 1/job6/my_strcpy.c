#include <stdio.h>

char *my_strcpy(char *dst, char *src) {
    int i = 0;

    // Tant qu'on n'a pas atteint la fin de la chaîne source
    while (src[i] != '\0') {
        dst[i] = src[i]; // On copie le caractère dans la destination
        i++;             // On passe au caractère suivant
    }

    // TRÈS IMPORTANT : On ajoute le caractère de fin de chaîne dans la destination
    dst[i] = '\0';

    // La fonction strcpy standard renvoie toujours le pointeur vers la destination
    return dst;
}

int main(void) {
    char source[] = "Hello La Plateforme!";
    char destination[50]; // On crée une boîte assez grande pour accueillir la copie

    printf("Avant la copie :\n");
    printf("  Source : %s\n", source);
    
    // On appelle notre fonction
    my_strcpy(destination, source);

    printf("\nAprès la copie :\n");
    printf("  Destination : %s\n", destination);

    return 0;
}