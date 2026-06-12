#ifndef SORT_ALBUM_H
#define SORT_ALBUM_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>

typedef struct album_item {
    char *artist;
    char *title;
    int year;
    struct album_item *next;
} AlbumItem;

// Job 13 : Tri générique avec pointeur de fonction
void sort_album_by(AlbumItem **list, int (*cmp)(AlbumItem*, AlbumItem*));
// Job 12 : Cas particulier (tri par défaut)
void sort_album(AlbumItem **list);

#endif  // SORT_ALBUM_H