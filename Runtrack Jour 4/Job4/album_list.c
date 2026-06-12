#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>
#include "album_list.h"

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
        return NULL;
    }
    for (int i = 0; i <= len; i++) {
        dest[i] = src[i];
    }
    return dest;
}

AlbumItem *create_album_item(char *artist, char *title, int year) {
    // 1. Allocation du maillon de la liste (AlbumItem)
    AlbumItem *new_item = malloc(sizeof(AlbumItem));
    if (new_item == NULL) {
        return NULL;
    }
    // 2. Allocation et copie des chaînes de caractères
    new_item->artist = my_strdup(artist);
    new_item->title = my_strdup(title);
    // 3. Assignation de l'année
    new_item->year = year;
    // 4. INITIALISATION CRUCIALE POUR LES LISTES CHAÎNÉES
    new_item->next = NULL;
  // 5. Gestion des erreurs d'allocation (anti-fuite de mémoire)
    if (artist != NULL && new_item->artist == NULL) {
        free(new_item->title);
        free(new_item);
        return NULL;
    }
    // CORRECTION ICI : "new_item" au lieu de "new_album_item"
    if (title != NULL && new_item->title == NULL) { 
        free(new_item->artist);
        free(new_item);
        return NULL;
    }
    return new_item;
}


// Fonction utilitaire pour libérer toute la liste chaînée proprement
void free_album_list(AlbumItem *list) {
    AlbumItem *current = list;
    while (current != NULL) {
        AlbumItem *next_node = current->next; // On sauvegarde le suivant avant de détruire l'actuel
        free(current->artist);
        free(current->title);
        free(current);
        current = next_node; // On passe au suivant
    }
}

int main(void) {
    // 1. Création du premier album (la tête de la liste)
    AlbumItem *head = create_album_item("Pink Floyd", "The Dark Side of the Moon", 1973);
    if (head == NULL) {
        printf("Erreur d'allocation pour le premier album.\n");
        return 1;
    }
    // 2. Création du deuxième album
    AlbumItem *second = create_album_item("Led Zeppelin", "Led Zeppelin IV", 1971);
    if (second == NULL) {
        printf("Erreur d'allocation pour le deuxième album.\n");
        free_album_list(head);
        return 1;
    }
    // 3. Chaînage : Le premier album pointe maintenant vers le deuxième
    head->next = second;
    // 4. Parcours et affichage de la liste chaînée
    printf("--- Ma Collection d'Albums (Liste Chaînée) ---\n");
    AlbumItem *current = head;
    int index = 1;
    while (current != NULL) {
        printf("Album %d :\n", index);
        printf("  Artiste : %s\n", current->artist);
        printf("  Titre   : %s\n", current->title);
        printf("  Année   : %d\n", current->year);
        printf("  Pointe vers l'adresse : %p\n\n", (void *)current->next);
        current = current->next; // On avance au maillon suivant
        index++;
    }
    printf("----------------------------------------------\n");
    // 5. Libération de toute la mémoire
    free_album_list(head);
    return 0;
}