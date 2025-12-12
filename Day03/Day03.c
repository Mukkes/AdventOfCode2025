#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long GetMaxJoltage(char *batteries, int size);

int main()
{
    FILE *filePointer;
    filePointer = fopen("Input.txt", "r");
    int length = 100;
    char line[length + 5];
    int resultPart1 = 0;
    int resultPart2 = 0;
    if (filePointer != NULL)
    {
        while (fgets(line, sizeof(line), filePointer))
        {
            int maxJoltage = 11;
            for (int i = 0; i < length - 1; i++)
            {
                int number = line[i] - '0';
                printf("i: %d\n", i);
                printf("line[i]: %d\n", line[i]);
                printf("number: %d\n", number);
                int joltage = (number * 10) + 1;
                if (joltage > maxJoltage)
                {
                    maxJoltage = joltage;
                }
                number = line[i + 1] - '0';
                joltage = ((maxJoltage / 10) * 10) + number;
                if (joltage > maxJoltage)
                {
                    maxJoltage = joltage;
                }
            }
            printf("maxJoltage: %d\n", maxJoltage);
            resultPart1 += maxJoltage;
        }
    }
    fclose(filePointer);

    printf("Part1: %d\n", resultPart1);
    printf("Part2: %d\n", resultPart2);

    return 0;
}

long long GetMaxJoltage(char *batteries, int size)
{
    char maxJoltage[size + 1];
    maxJoltage[size] = '\0';
    for (int i = 0; i < size; i++)
    {
        maxJoltage[i] = 1;
    }

    int length = strlen(batteries);
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < size; j++)
        {
            char newMaxJoltage[size + 1];
            newMaxJoltage[size] = '\0';
            strcpy(newMaxJoltage, maxJoltage);
            newMaxJoltage[j] = batteries[i];
            if (atoll(newMaxJoltage) > atoll(maxJoltage))
            {
                strcpy(maxJoltage, newMaxJoltage);
            }
        }
    }
    return atoll(maxJoltage);
}
