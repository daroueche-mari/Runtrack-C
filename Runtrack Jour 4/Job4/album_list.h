#ifndef ALBUM_LIST_H
#define ALBUM_LIST_H

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
 * Alloue un nouvel élément AlbumItem, copie ses informations 
 * et initialise le pointeur next à NULL.
 */
AlbumItem *create_album_item(char *artist, char *title, int year);

#endif /* ALBUM_LIST_H */