#include <stdio.h>
#include <stdlib.h>

void saveGame(LEVEL *level, INVENTORY *inventory, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Cannot save the game.\n");
        return;
    }
    fclose(file);


