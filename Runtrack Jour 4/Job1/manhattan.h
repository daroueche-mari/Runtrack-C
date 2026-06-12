#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>

#ifndef MANHATTAN_H
#define MANHATTAN_H

// Définition de la structure Point
typedef struct {
    int x;
    int y;
} Point;

// Macro préprocesseur pour la valeur absolue
// Note : Les parenthèses protègent les expressions passées en paramètre
#define ABS(x) (((x) < 0) ? -(x) : (x))

// Prototype de la fonction
int manhattan(Point a, Point b);

#endif // MANHATTAN_H