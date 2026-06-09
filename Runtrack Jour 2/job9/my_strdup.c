#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>


char *my_strdup(char *str)
{
    // Sécurité : si la chaîne reçue est NULL
    if (str == NULL)
    {
        return NULL;
    }

    // 1. On calcule la taille de la chaîne (comme un strlen)
    int taille = 0;
    while (*(str + taille) != '\0')
    {
        taille++;
    }

    // 2. On alloue la mémoire : taille + 1 octet pour le '\0'
    char *copie = (char *)malloc((taille + 1) * sizeof(char));

    // Sécurité : On vérifie si le malloc a réussi
    if (copie == NULL)
    {
        return NULL;
    }

    // 3. On copie les caractères (comme un strcpy)
    int i = 0;
    while (i < taille)
    {
        *(copie + i) = *(str + i);
        i++;
    }
    
    // On n'oublie surtout pas d'ajouter le caractère de fin de chaîne
    *(copie + i) = '\0';

    // 4. On retourne l'adresse de la nouvelle chaîne
    return copie;
}


#include <stdio.h>
#include <stdlib.h>

char *my_strdup(char *str);

int main(void)
{
    char *original = "La Plateforme";
    
    // On duplique la chaîne
    char *ma_copie = my_strdup(original);
    
    if (ma_copie != NULL)
    {
        printf("Chaîne d'origine : %s\n", original);
        printf("Chaîne dupliquée : %s\n", ma_copie);
        
        // On libère la mémoire allouée par my_strdup
        free(ma_copie);
    }
    
    return 0;
}