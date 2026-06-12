#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>
#include "album_list.h"

// ==========================================
// FONCTIONS UTILITAIRES INTERNES (STATIC)
// ==========================================

// Calcule la longueur d'une chaîne de caractères
static int my_strlen(char *str) 
{
    int i = 0;
    while (str && str[i] != '\0') {
        i++;
    }
    return i;
}

// Alloue et copie une chaîne de caractères
static char *my_strdup(char *src) 
{
    if (src == NULL) {
        return NULL;
    }
    int len = my_strlen(src);
    char *dest = malloc((len + 1) * sizeof(char));
    if (dest == NULL) {
        return NULL;
    }
    for (int i = 0; i <= len; i++) {
        dest[i] = src[i];
    }
    return dest;
}

// Compare deux chaînes de caractères (renvoie 0 si identiques)
static int my_strcmp(const char *s1, const char *s2) 
{
    if (!s1 || !s2) return -1;
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *(unsigned char *)s1 - *(unsigned char *)s2;
}

// ==========================================
// IMPLÉMENTATION DES JOBS
// ==========================================

// --- Job 04 : Création d'un élément ---
AlbumItem *create_album_item(char *artist, char *title, int year) 
{
    AlbumItem *new_item = malloc(sizeof(AlbumItem));
    if (new_item == NULL) {
        return NULL;
    }
    new_item->artist = my_strdup(artist);
    // Si l'artiste a échoué (et qu'il n'était pas NULL à la base)
    if (artist != NULL && new_item->artist == NULL) {
        free(new_item);
        return NULL;
    }
    new_item->title = my_strdup(title);
    // Si le titre a échoué (et qu'il n'était pas NULL à la base)
    if (title != NULL && new_item->title == NULL) {
        free(new_item->artist);
        free(new_item);
        return NULL;
    }
    new_item->year = year;
    new_item->next = NULL;
    return new_item;
}

// --- Job 05 : Compter les éléments ---
int count_album_item(AlbumItem *list) 
{
    int count = 0;
    AlbumItem *current = list;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// --- Job 06 : Trouver un album par son titre ---
AlbumItem *find_album(AlbumItem *list, const char *title) 
{
    AlbumItem *current = list;
    while (current != NULL) {
        if (my_strcmp(current->title, title) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// --- Job 07 : Inverser la liste ---
void reverse_list(AlbumItem **list) 
{
    if (list == NULL || *list == NULL) {
        return;
    }
    AlbumItem *prev = NULL;
    AlbumItem *current = *list;
    AlbumItem *next_node = NULL;
    while (current != NULL) {
        next_node = current->next;
        current->next = prev;
        prev = current;
        current = next_node;
    }
    *list = prev;
}

// --- Job 08 : Vider la liste (Libération de mémoire) ---
void clear_list(AlbumItem **list) 
{
    if (list == NULL || *list == NULL) {
        return;
    }
    AlbumItem *current = *list;
    while (current != NULL) {
        AlbumItem *next_node = current->next;
        free(current->artist);
        free(current->title);
        free(current);
        current = next_node;
    }
    *list = NULL;
}

// --- Job 09 : Ajouter à la fin de la liste ---
void push_back_album(AlbumItem **list, AlbumItem *album) 
{
    if (list == NULL || album == NULL) {
        return;
    }
    album->next = NULL;
    if (*list == NULL) {
        *list = album;
        return;
    }
    AlbumItem *current = *list;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = album;
}

// --- Job 10 : Ajouter au début de la liste ---
void push_front_album(AlbumItem **list, AlbumItem *album) 
{
    if (list == NULL || album == NULL) {
        return;
    }
    album->next = *list;
    *list = album;
}