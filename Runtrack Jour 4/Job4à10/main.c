#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>

#include "album_list.h"

void print_list(AlbumItem *list) {
    AlbumItem *curr = list;
    printf("--- Liste actuelle (%d albums) ---\n", count_album_item(list));
    while (curr) {
        printf("[%s - %s (%d)] -> ", curr->artist, curr->title, curr->year);
        curr = curr->next;
    }
    printf("NULL\n\n");
}

int main(void) {
    AlbumItem *ma_liste = NULL;

    // Test Push Back & Push Front
    push_back_album(&ma_liste, create_album_item("Daft Punk", "Discovery", 2001));
    push_back_album(&ma_liste, create_album_item("Pink Floyd", "The Wall", 1979));
    push_front_album(&ma_liste, create_album_item("Justice", "Cross", 2007));
    print_list(ma_liste);

    // Test Recherche
    printf("Recherche de 'The Wall'...\n");
    AlbumItem *trouve = find_album(ma_liste, "The Wall");
    if (trouve) printf("Trouvé ! Artiste : %s\n\n", trouve->artist);

    // Test Inversement de liste
    printf("Inversion de la liste...\n");
    reverse_list(&ma_liste);
    print_list(ma_liste);

    // Nettoyage final
    clear_list(&ma_liste);
    printf("Après clear_list :\n");
    print_list(ma_liste);

    return 0;
}