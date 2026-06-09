#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>


#include <stdlib.h>

int *array_clone(int *arr, int n)
{
    // 1. Si n est invalide ou le tableau d'origine est vide, on renvoie NULL
    if (n <= 0 || arr == NULL)
    {
        return NULL;
    }

    // 2. On alloue la mémoire pour le nouveau tableau (n * 4 octets)
    int *clone = (int *)malloc(n * sizeof(int));

    // Sécurité : On vérifie si le malloc a réussi (si la mémoire n'est pas pleine)
    if (clone == NULL)
    {
        return NULL; 
    }

    // 3. On copie les éléments sans utiliser les crochets
    int i = 0;
    while (i < n)
    {
        *(clone + i) = *(arr + i);
        i++;
    }

    // 4. On renvoie l'adresse du nouveau tableau
    return clone;
}


#include <stdio.h>
#include <stdlib.h>

int *array_clone(int *arr, int n);

int main(void)
{
    int original[] = {10, 20, 30, 40, 50};
    int taille = 5;

    // On clone le tableau
    int *mon_clone = array_clone(original, taille);

    if (mon_clone != NULL)
    {
        // On affiche le clone pour vérifier la copie
        int i = 0;
        while (i < taille)
        {
            printf("Clone[%d] = %d\n", i, *(mon_clone + i));
            i++;
        }

        // RÈGLE D'OR : Tout malloc doit être libéré à la fin avec free() !
        free(mon_clone);
    }

    return 0;
}