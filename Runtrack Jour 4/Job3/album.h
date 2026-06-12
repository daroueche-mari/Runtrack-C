#ifndef ALBUM_H
#define ALBUM_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>


typedef struct {
    char *artist;
    char *title;
    int year;
} Album;

/*
 * Alloue la mémoire pour un nouvel album et y copie les informations.
 * Retourne un pointeur vers l'album créé, ou NULL en cas d'échec.
 */
Album *create_album(char *artist, char *title, int year);

#endif  // ALBUM_H