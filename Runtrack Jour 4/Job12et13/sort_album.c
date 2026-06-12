#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>

#include "sort_album.h"

// ==========================================
// FONCTION UTILITAIRE INTERNE (STATIC)
// ==========================================

// Compare deux chaînes de caractères (renvoie > 0 si s1 > s2)
static int my_strcmp(const char *s1, const char *s2) {
    if (!s1 || !s2) return 0;
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *(unsigned char *)s1 - *(unsigned char *)s2;
}

// Fonction de comparaison par défaut : Trie par artiste, puis par titre si même artiste
static int default_compare(AlbumItem *a, AlbumItem *b) {
    int res = my_strcmp(a->artist, b->artist);
    if (res == 0) {
        return my_strcmp(a->title, b->title);
    }
    return res;
}

// Fonction interne pour échanger le contenu de deux nœuds
static void swap_album_data(AlbumItem *a, AlbumItem *b) {
    char *temp_artist = a->artist;
    char *temp_title = a->title;
    int temp_year = a->year;
    a->artist = b->artist;
    a->title = b->title;
    a->year = b->year;
    b->artist = temp_artist;
    b->title = temp_title;
    b->year = temp_year;
}

// ==========================================
// IMPLÉMENTATION DES JOBS
// ==========================================

// --- Job 13 : Tri générique (Bubble Sort) ---
void sort_album_by(AlbumItem **list, int (*cmp)(AlbumItem*, AlbumItem*)) {
    if (list == NULL || *list == NULL || cmp == NULL) {
        return;
    }
    int swapped;
    AlbumItem *current;
    AlbumItem *last_checked = NULL;
    do {
        swapped = 0;
        current = *list;
        while (current->next != last_checked) {
            // Si la fonction de comparaison renvoie un résultat positif, on inverse
            if (cmp(current, current->next) > 0) {
                swap_album_data(current, current->next);
                swapped = 1;
            }
            current = current->next;
        }
        last_checked = current;
    } while (swapped);
}

// --- Job 12 : Cas particulier utilisant sort_album_by ---
void sort_album(AlbumItem **list) {
    sort_album_by(list, default_compare);
}