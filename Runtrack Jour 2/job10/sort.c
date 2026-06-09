#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>


int *sort(int *array)
{
    // Si le tableau est vide ou n'existe pas, on ne fait rien
    if (array == 0)
    {
        return 0;
    }

    // 1. On commence par calculer la taille du tableau
    int taille = 0;
    while (*(array + taille) != 0) // On s'arrête au 0 (NULL) de fin
    {
        taille++;
    }

    // 2. Algorithme du tri à bulles
    int i = 0;
    while (i < taille - 1)
    {
        int j = 0;
        while (j < taille - i - 1)
        {
            // Si l'élément actuel est plus grand que le suivant, on les échange
            if (*(array + j) > *(array + j + 1))
            {
                int temporaire = *(array + j);
                *(array + j) = *(array + j + 1);
                *(array + j + 1) = temporaire;
            }
            j++;
        }
        i++;
    }

    // 3. On retourne le tableau trié
    return array;
}

int main(void)
{
    // Le 0 à la fin sert de balise d'arrêt (le fameux "NULL" de l'énoncé)
    int mes_nombres[] = {42, 12, 89, 3, 21, 0}; 
    
    printf("Avant le tri : ");
    int i = 0;
    while (mes_nombres[i] != 0)
    {
        printf("%d ", mes_nombres[i]);
        i++;
    }
    printf("\n");

    // Appel de ta fonction de tri
    sort(mes_nombres);

    printf("Après le tri : ");
    i = 0;
    while (mes_nombres[i] != 0)
    {
        printf("%d ", mes_nombres[i]);
        i++;
    }
    printf("\n");

    return 0;
}