#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>

int sum_array(int *arr, int n)
{
    int somme = 0;
    int i = 0;

    while (i < n)
    {
        // *arr donne la valeur de la case actuelle.
        somme += *arr; 
        
        // On avance le pointeur à la case mémoire suivante.
        arr++; 
        
        i++;
    }

    return somme;
}


int main()
{
    // On crée un vrai tableau contenant nos deux nombres
    int mes_nombres[] = {1, 2};
    
    // On passe le tableau (qui est déjà une adresse) et sa taille (2)
    int total = sum_array(mes_nombres, 2);
    
    // afficher le résultat pour vérifier
    printf("Le total est : %d\n", total);
    
    return 0;
}