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

// Job 04
AlbumItem *create_album_item(char *artist, char *title, int year);

// Job 05
int count_album_item(AlbumItem *list);

// Job 06
AlbumItem *find_album(AlbumItem *list, const char *title);

// Job 07
void reverse_list(AlbumItem **list);

// Job 08
void clear_list(AlbumItem **list);

// Job 09
void push_back_album(AlbumItem **list, AlbumItem *album);

// Job 10
void push_front_album(AlbumItem **list, AlbumItem *album);

#endif /* ALBUM_LIST_H */