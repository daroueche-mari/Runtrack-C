#include <stdio.h>
int my_strlen(char *c) 
{
    int i = 0;

    // Tant que le caractère actuel n'est pas le caractère de fin '\0'
    while (c[i] != '\0') {
        i++; // On passe au caractère suivant et on augmente le compteur
    }

    return i; // On renvoie la taille totale trouvée
}

int main(void) 
{
    // On peut stocker le résultat pour vérifier (optionnel)
    int taille = my_strlen("Hello, World!");
    printf("Taille: %d\n", taille);
    return 0;
}
