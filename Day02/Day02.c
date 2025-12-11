#include "ProductIdRange.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void GetRanges(ProductIdRange *productIdRanges);
bool IsInvalidId(long long id);

int main()
{
    int ranges = 35;
    ProductIdRange *productIdRanges = (ProductIdRange *)malloc(ranges * sizeof(ProductIdRange));
    GetRanges(productIdRanges);

    long long resultPart1 = 0;
    long long resultPart2 = 0;
    for (int i = 0; i < ranges; i++)
    {
        for (long long id = productIdRanges[i].FirstId; id <= productIdRanges[i].LastId; id++)
        {
            if (IsInvalidId(id))
            {
                resultPart1 += id;
                // printf("id: %lld\n", id);
            }
        }
    }
    free(productIdRanges);

    printf("Part1: %lld\n", resultPart1);
    printf("Part2: %lld\n", resultPart2);
    return 0;
}

void GetRanges(ProductIdRange *productIdRanges)
{
    FILE *filePointer;
    filePointer = fopen("Input.txt", "r");
    char line[600];
    int index = 0;
    if (filePointer != NULL)
    {
        while (fgets(line, sizeof(line), filePointer))
        {
            char *number = strtok(line, "-");
            while (number)
            {
                productIdRanges[index].FirstId = atoll(number);
                number = strtok(NULL, ",");
                productIdRanges[index].LastId = atoll(number);
                number = strtok(NULL, "-");
                index++;
            }
        }
    }
    fclose(filePointer);
}

bool IsInvalidId(long long id)
{
    char charId[11];
    sprintf(charId, "%lld", id);
    int length = strlen(charId);
    if (length % 2 == 1)
    {
        return false;
    }
    int half = length / 2;
    char first[half + 1];
    char last[half + 1];
    first[half] = '\0';
    last[half] = '\0';
    strncpy(first, charId, half);
    strncpy(last, charId + half, half);
    // printf("first: %s\n", first);
    // printf("last: %s\n", last);
    if (strcmp(first, last) == 0)
    {
        return true;
    }
    return false;
}
