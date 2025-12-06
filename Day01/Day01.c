#include "Rotation.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void GetRotations(Rotation *rotations, int size);

int main() {
    int size = 4317;
    Rotation *rotations = (Rotation *) malloc(size * sizeof(Rotation));
    GetRotations(rotations, size);

    int dial = 50;
    int resultPart1 = 0;
    int resultPart2 = 0;
    for (int i = 0; i < size; i++)
    {
        int hundred = rotations[i].Distance / 100;
        resultPart2 += hundred;
        int distance = rotations[i].Distance - (hundred * 100);
        if (rotations[i].Direction == 'R')
        {
            dial += distance;
            if (dial > 99)
            {
                dial -= 100;
                resultPart2++;
            }
            if (dial == 0)
            {
                resultPart1++;
            }
        }
        else
        {
            if (dial == 0 && distance > 0)
            {
                dial += 100;
            }
            dial -= distance;
            if (dial < 0)
            {
                dial += 100;
                resultPart2++;
            }
            if (dial == 0)
            {
                resultPart1++;
                resultPart2++;
            }
        }
    }
    printf("Part1: %d\n", resultPart1);
    printf("Part2: %d\n", resultPart2);

    free(rotations);
    return 0;
}

void GetRotations(Rotation *rotations, int size)
{
    FILE *filePointer;
    filePointer = fopen("Input.txt", "r");
    char line[6];
    int index = 0;
    if (filePointer != NULL) {
        while (fgets(line, sizeof(line), filePointer)) {
            rotations[index].Direction = line[0];
            char distance[4];
            distance[3] = '\0';
            strncpy(distance, line + 1, 3);
            rotations[index].Distance = atoi(distance);
            index++;
        }
    }
    fclose(filePointer);
}
