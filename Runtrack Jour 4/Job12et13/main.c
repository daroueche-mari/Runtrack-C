#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>

#include "sort_album.h"

// Fonction locale rapide pour créer un élément de test
static AlbumItem *create_item(char *artist, char *title, int year) {
    AlbumItem *item = malloc(sizeof(AlbumItem));
    if (!item) return NULL;
    item->artist = artist;
    item->title = title;
    item->year = year;
    item->next = NULL;
    return item;
}

// Affichage de la liste
void print_list(AlbumItem *list) {
    while (list) {
        printf("  - %s | %s (%d)\n", list->artist, list->title, list->year);
        list = list->next;
    }
    printf("\n");
}

// Une autre fonction de comparaison pour le Job 13 (Tri par année croissante)
int compare_by_year(AlbumItem *a, AlbumItem *b) {
    return a->year - b->year;
}

int main(void) {
    // 1. Création d'une liste désordonnée
    AlbumItem *a1 = create_item("Pink Floyd", "The Wall", 1979);
    AlbumItem *a2 = create_item("Daft Punk", "Discovery", 2001);
    AlbumItem *a3 = create_item("Justice", "Cross", 2007);
    AlbumItem *a4 = create_item("Daft Punk", "Homework", 1997);
    AlbumItem *ma_liste = a1;
    a1->next = a2;
    a2->next = a3;
    a3->next = a4;
    printf("--- Liste Initiale ---\n");
    print_list(ma_liste);
    // 2. Test Job 12 : Tri par défaut (Artiste par ordre alphabétique)
    printf("--- Tri par défaut (Job 12 : par Artiste) ---\n");
    sort_album(&ma_liste);
    print_list(ma_liste);
    // 3. Test Job 13 : Tri par Année grâce au pointeur de fonction
    printf("--- Tri personnalisé (Job 13 : par Année) ---\n");
    sort_album_by(&ma_liste, compare_by_year);
    print_list(ma_liste);
    // Libération rapide pour éviter les fuites de mémoire
    AlbumItem *curr = ma_liste;
    while (curr) {
        AlbumItem *next = curr->next;
        free(curr);
        curr = next;
    }
    return 0;
}