#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>

#include "album_del_one.h"

void album_del_one(AlbumItem **list, AlbumItem *elem) {
    // Si la liste est vide ou si l'élément à supprimer n'existe pas
    if (list == NULL || *list == NULL || elem == NULL) {
        return;
    }
    AlbumItem *current = *list;
    AlbumItem *prev = NULL;
    // 1. Recherche de l'élément dans la liste chaînée
    while (current != NULL && current != elem) {
        prev = current;
        current = current->next;
    }
    // Si l'élément ciblé ne fait pas partie de la liste, on s'arrête
    if (current == NULL) {
        return;
    }
    // 2. Décrochage du maillon (on ajuste les pointeurs pour contourner l'élément)
    if (prev == NULL) {
        // Cas où l'élément à supprimer est le tout premier (la tête)
        *list = current->next;
    } else {
        // Cas général où l'élément est au milieu ou à la fin
        prev->next = current->next;
    }
    // 3. Libération propre de toute la mémoire du maillon supprimé
    free(current->artist);
    free(current->title);
    free(current);
}