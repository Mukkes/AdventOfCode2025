#include "Rotation.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *filePointer;
    filePointer = fopen("Input.txt", "r");
    char line[6];
    int index = 0;
    int size = 4317;
    Rotation *rotations = (Rotation *) malloc(size * sizeof(*rotations));
    if (filePointer != NULL) {
        while (fgets(line, sizeof(line), filePointer)) {
            rotations[index].Direction = line[0];
            char direction[4];
            direction[3] = '\0';
            strncpy(direction, line + 1, 3);
            rotations[index].Distance = atoi(direction);
            index++;
        }
    }
    fclose(filePointer);

    int dial = 50;
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (rotations[i].Direction == 'R')
        {
            dial = dial + rotations[i].Distance;
        }
        else
        {
            dial = dial - rotations[i].Distance;
        }
        if (dial % 100 == 0)
        {
            count++;
        }
    }
    printf("Part1: %d\n", count);

    free(rotations);
    return 0;
}
