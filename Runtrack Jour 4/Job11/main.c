#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>

#include "album_del_one.h"


// --- FONCTIONS DE TEST INDÉPENDANTES ---

// Fonction locale rapide pour créer un élément de test
// (Pensez à utiliser vos propres fonctions si vous compilez tout ensemble)
static AlbumItem *create_item_test(char *artist, char *title, int year) {
    AlbumItem *item = malloc(sizeof(AlbumItem));
    if (!item) return NULL;
    item->artist = artist; // Assignation directe pour le test rapide
    item->title = title;
    item->year = year;
    item->next = NULL;
    return item;
}

// Fonction pour afficher la liste
void print_list(AlbumItem *list) {
    AlbumItem *curr = list;
    if (curr == NULL) {
        printf("(Liste vide)\n");
        return;
    }
    while (curr != NULL) {
        printf("[%s - %s (%d)] -> ", curr->artist, curr->title, curr->year);
        curr = curr->next;
    }
    printf("NULL\n");
}

// --- PROGRAMME PRINCIPAL ---
int main(void) {
    // 1. Création de quelques maillons
    AlbumItem *album1 = create_item_test("Daft Punk", "Discovery", 2001);
    AlbumItem *album2 = create_item_test("Pink Floyd", "The Wall", 1979);
    AlbumItem *album3 = create_item_test("Justice", "Cross", 2007);
    // 2. Chaînage manuel pour former une liste : album1 -> album2 -> album3
    AlbumItem *ma_liste = album1;
    album1->next = album2;
    album2->next = album3;
    printf("--- Liste initiale ---\n");
    print_list(ma_liste);
    printf("\n");
    // 3. Test Cas 1 : Suppression d'un élément au milieu (album2 / Pink Floyd)
    printf("Suppression de 'The Wall' (au milieu)...\n");
    album_del_one(&ma_liste, album2);
    print_list(ma_liste);
    printf("\n");
    // 4. Test Cas 2 : Suppression de l'élément de tête (album1 / Daft Punk)
    printf("Suppression de 'Discovery' (en tête)...\n");
    album_del_one(&ma_liste, album1);
    print_list(ma_liste);
    printf("\n");
    // 5. Test Cas 3 : Suppression du dernier élément restant (album3 / Justice)
    printf("Suppression de 'Cross' (le dernier)...\n");
    album_del_one(&ma_liste, album3);
    print_list(ma_liste);
    return 0;
}