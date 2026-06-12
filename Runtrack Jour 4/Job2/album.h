#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>

#ifndef ALBUM_H
#define ALBUM_H

typedef struct {
    char title[100];
    char artist[100];
    char year[100];
} Album;


void print_album(Album *album);



#endif // ALBUM_H