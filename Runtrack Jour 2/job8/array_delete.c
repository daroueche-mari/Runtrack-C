#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>


void array_delete(int *arr)
{
    free(arr);
}


int main()
{
    printf("1. Allocation de la mémoire...\n");
    int *arr = malloc(sizeof(int) * 10);
    
    printf("2. Libération de la mémoire...\n");
    array_delete(arr);
    
    printf("3. Fin du programme sans crash !\n");
    return 0;
}