#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>
#include "manhattan.h"

int manhattan(Point a, Point b) {
    // Calcul de la distance de Manhattan en utilisant la macro ABS
    return ABS(a.x - b.x) + ABS(a.y - b.y);
}


int main()
{
    // Exemple d'utilisation
    Point pointA = {1, 2};
    Point pointB = {4, 6};
    int distance = manhattan(pointA, pointB);
    printf("La distance de Manhattan entre les points (%d, %d) et (%d, %d) est : %d\n", pointA.x, pointA.y, pointB.x, pointB.y, distance);
    return 0;
}