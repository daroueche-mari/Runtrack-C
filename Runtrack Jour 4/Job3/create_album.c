#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>

#include "album.h"

// Calcule la longueur d'une chaîne de caractères
static int my_strlen(char *str) {
    int i = 0;
    while (str && str[i] != '\0') {
        i++;
    }
    return i;
}

// Alloue et copie une chaîne de caractères
static char *my_strdup(char *src) {
    if (src == NULL) {
        return NULL;
    }
    
    int len = my_strlen(src);
    char *dest = malloc((len + 1) * sizeof(char));
    
    if (dest == NULL) {
        return NULL; // Échec d'allocation
    }
    
    for (int i = 0; i <= len; i++) {
        dest[i] = src[i];
    }
    return dest;
}

Album *create_album(char *artist, char *title, int year) {
    // 1. Allocation de la structure Album principale
    Album *new_album = malloc(sizeof(Album));
    if (new_album == NULL) {
        return NULL;
    }

    // 2. Allocation et copie indépendante des chaînes
    new_album->artist = my_strdup(artist);
    new_album->title = my_strdup(title);
    new_album->year = year;

    // 3. Gestion sécurisée des erreurs d'allocation (anti-fuite de mémoire)
    if (artist != NULL && new_album->artist == NULL) {
        free(new_album->title);
        free(new_album);
        return NULL;
    }
    
    if (title != NULL && new_album->title == NULL) {
        free(new_album->artist);
        free(new_album);
        return NULL;
    }

    return new_album;
}

// Fonction utilitaire pour libérer proprement toute la mémoire de l'album
void free_album(Album *album) {
    if (album != NULL) {
        free(album->artist); // Libère la chaîne de l'artiste
        free(album->title);  // Libère la chaîne du titre
        free(album);         // Libère la structure elle-même
    }
}

int main(void) {
    // 1. Création de l'album en utilisant notre fonction
    Album *my_album = create_album("Daft Punk", "Discovery", 2001);

    // 2. Vérification que l'allocation s'est bien passée
    if (my_album == NULL) {
        printf("Erreur : Impossible de créer l'album (manque de mémoire).\n");
        return 1;
    }

    // 3. Affichage des informations pour vérifier que tout est correct
    printf("--- Nouvel Album Créé ---\n");
    printf("Artiste : %s\n", my_album->artist);
    printf("Titre   : %s\n", my_album->title);
    printf("Année   : %d\n", my_album->year);
    printf("-------------------------\n");

    // 4. Libération de la mémoire avant de quitter le programme
    free_album(my_album);

    return 0;
}