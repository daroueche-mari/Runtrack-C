#ifndef ALBUM_DEL_ONE_H
#define ALBUM_DEL_ONE_H

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

/*
 * Supprime un élément spécifique de la liste sans rompre le chaînage
 * et libère toute la mémoire qui lui est associée.
 */
void album_del_one(AlbumItem **list, AlbumItem *elem);

#endif /* ALBUM_DEL_ONE_H */