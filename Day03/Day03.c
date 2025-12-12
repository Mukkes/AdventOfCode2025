#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long GetMaxJoltage(char *batteries, int size);

int main()
{
    FILE *filePointer;
    filePointer = fopen("Input.txt", "r");
    int length = 100;
    char line[length + 2];
    long long resultPart1 = 0;
    long long resultPart2 = 0;
    if (filePointer != NULL)
    {
        while (fgets(line, sizeof(line), filePointer))
        {
            line[strcspn(line, "\n")] = 0;
            long long maxJoltage = GetMaxJoltage(line, 2);
            resultPart1 += maxJoltage;
            maxJoltage = GetMaxJoltage(line, 12);
            resultPart2 += maxJoltage;
        }
    }
    fclose(filePointer);

    printf("Part1: %lld\n", resultPart1);
    printf("Part2: %lld\n", resultPart2);

    return 0;
}

long long GetMaxJoltage(char *batteries, int size)
{
    char maxJoltage[size + 1];
    maxJoltage[size] = 0;
    // Fill maxJoltage with 1s.
    for (int i = 0; i < size; i++)
    {
        maxJoltage[i] = '1';
    }

    // Loop through batteries.
    int length = strlen(batteries);
    for (int i = 0; i < length; i++)
    {
        // Set start next loop for when highest value is at end of array.
        int start = 0;
        if (i + size > length)
        {
            start = i + size - length;
        }
        // Loop through maxJoltage.
        for (int j = start; j < size; j++)
        {
            char newMaxJoltage[size + 1];
            newMaxJoltage[size] = 0;
            strcpy(newMaxJoltage, maxJoltage);
            newMaxJoltage[j] = batteries[i];
            // Determine if maxJoltage with batterie[i] on maxJoltage[j] is larger.
            if (atoll(newMaxJoltage) > atoll(maxJoltage))
            {
                // Update maxJoltage.
                strcpy(maxJoltage, newMaxJoltage);
                // Fill rest maxJoltage with 1s.
                for (int k = j + 1; k < size; k++)
                {
                    maxJoltage[k] = '1';
                }
                break;
            }
        }
    }
    return atoll(maxJoltage);
}
