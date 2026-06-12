#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>
#include "album.h"

void print_album(Album *album) {
    printf("Titre : %s\n", album->title);
    printf("Artiste : %s\n", album->artist);
    printf("Annee : %s\n", album->year);
}



int main()
{
    // Exemple d'utilisation
    Album album = {"Masters of Puppets", "Metallica", "1986"};
    print_album(&album);
    return 0;
}