#include "Rotation.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *filePointer;
    filePointer = fopen("Input.txt", "r");
    char line[5];
    int index = 0;
    //Rotation rotations[110];
    Rotation *rotations = (Rotation *) malloc(4327 * sizeof(*rotations));
    if (rotations == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    //Rotation rotations[4317];
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

    printf("%c", rotations[0].Direction);
    printf("%d", rotations[0].Distance);
    //int resultPart1 = 0;
    //for (int i = 0; i < 1000; i++) {
    //    resultPart1 += GetRequiredWarppingPaper(&boxes[i]);
    //}
    //printf("Part1: %d\n", resultPart1);
    //int resultPart2 = 0;
    //for (int i = 0; i < 1000; i++) {
    //    resultPart2 += GetRibbon(&boxes[i]);
    //}
    //printf("Part2: %d\n", resultPart2);
    free(rotations);
    return 0;
}
