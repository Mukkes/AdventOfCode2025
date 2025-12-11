#include "ProductIdRange.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void GetRanges(ProductIdRange *productIdRanges);
bool IsInvalidId1(long long id);
bool IsInvalidId2(long long id);

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
            if (IsInvalidId1(id))
            {
                resultPart1 += id;
                resultPart2 += id;
            }
            else if (IsInvalidId2(id))
            {
                resultPart2 += id;
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

bool IsInvalidId1(long long id)
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
    if (strcmp(first, last) == 0)
    {
        return true;
    }
    return false;
}

bool IsInvalidId2(long long id)
{
    char charId[11];
    sprintf(charId, "%lld", id);
    int length = strlen(charId);
    int mod = 2;
    bool result = true;
    while (mod <= length)
    {
        if (length % mod == 0)
        {
            result = true;
            int size = length / mod;
            char part1[size + 1];
            char part2[size + 1];
            part1[size] = '\0';
            part2[size] = '\0';
            int part = 0;
            while (part < (mod - 1))
            {
                strncpy(part1, charId + (size * part), size);
                strncpy(part2, charId + size + (size * part), size);
                if (strcmp(part1, part2) != 0)
                {
                    result = false;
                    break;
                }
                part++;
            }
            if (result)
            {
                return true;
            }
        }
        mod++;
    }
    return false;
}
