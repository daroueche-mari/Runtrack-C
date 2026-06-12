#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>

#include "music.h"

static int my_strlen(char *str) 
{
    int i = 0;
    while (str && str[i] != '\0') i++;
    return i;
}

static char *my_strdup(char *src) 
{
    if (!src) return NULL;
    int len = my_strlen(src);
    char *dest = malloc((len + 1) * sizeof(char));
    if (!dest) return NULL;
    for (int i = 0; i <= len; i++) dest[i] = src[i];
    return dest;
}

AlbumItem *create_album_item(char *artist, char *title, int year) 
{
    AlbumItem *new_item = malloc(sizeof(AlbumItem));
    if (!new_item) return NULL;
    new_item->artist = my_strdup(artist);
    new_item->title = my_strdup(title);
    new_item->year = year;
    new_item->next = NULL;
    return new_item;
}

void push_back_album(AlbumItem **list, AlbumItem *album) 
{
    if (!list || !album) return;
    if (*list == NULL) {
        *list = album;
        return;
    }
    AlbumItem *curr = *list;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = album;
}

void clear_list(AlbumItem **list) 
{
    if (!list || !*list) return;
    AlbumItem *curr = *list;
    while (curr) {
        AlbumItem *next = curr->next;
        free(curr->artist);
        free(curr->title);
        free(curr);
        curr = next;
    }
    *list = NULL;
}

void sort_album_by(AlbumItem **list, int (*cmp)(AlbumItem*, AlbumItem*)) 
{
    if (!list || !*list || !cmp) return;
    int swapped;
    AlbumItem *curr;
    AlbumItem *last = NULL;
    do {
        swapped = 0;
        curr = *list;
        while (curr->next != last) {
            if (cmp(curr, curr->next) > 0) {
                // Swap data
                char *t_art = curr->artist;
                char *t_tit = curr->title;
                int t_yr = curr->year;
                curr->artist = curr->next->artist;
                curr->title = curr->next->title;
                curr->year = curr->next->year;
                curr->next->artist = t_art;
                curr->next->title = t_tit;
                curr->next->year = t_yr;
                swapped = 1;
            }
            curr = curr->next;
        }
        last = curr;
    } while (swapped);
}