#ifndef MUSIC_H
#define MUSIC_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>


// Structure principale (commune)
typedef struct album_item {
    char *artist;
    char *title;
    int year;
    struct album_item *next;
} AlbumItem;

// Fonctions de base de la liste chaînée (music_list.c)
AlbumItem *create_album_item(char *artist, char *title, int year);
void push_back_album(AlbumItem **list, AlbumItem *album);
void clear_list(AlbumItem **list);
void sort_album_by(AlbumItem **list, int (*cmp)(AlbumItem*, AlbumItem*));
// Fonctions utilitaires globales (music_engine.c)
void print_string(const char *str);
int my_strcmp(const char *s1, const char *s2);
// LA FONCTION MAÎTRESSE : Lance tout le processus (music_engine.c)
int run_music_program(int argc, char **argv);

#endif /* MUSIC_H */