#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>

#include "music.h"

int main(int argc, char **argv) {
    // Lancement unique du programme via la fonction maîtresse
    return run_music_program(argc, argv);
}