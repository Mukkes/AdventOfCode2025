#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Range
{
    size_t Start;
    size_t End;
} Range;

bool InsideRange(Range *ranges, size_t ingredientId, size_t rangesCount)
{
    for (size_t i = 0; i < rangesCount; i++)
    {
        if ((ingredientId >= ranges[i].Start) &&
            (ingredientId <= ranges[i].End))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    char *fileName = "Input.txt";
    FILE *filePointer;
    filePointer = fopen(fileName, "r");
    if (filePointer == NULL)
    {
        return 1;
    }

    Range *ranges = malloc(200 * sizeof(Range));
    if (ranges == NULL)
    {
        return 1;
    }

    char line[64];
    char *part;
    size_t index = 0;
    size_t rangesCount = 0;
    while (fgets(line, sizeof(line), filePointer))
    {
        if (strlen(line) == 1)
        {
            break;
        }

        part = strtok(line, "-");
        ranges[index].Start = strtol(part, NULL, 10);
        part = strtok(NULL, "-");
        ranges[index].End = strtol(part, NULL, 10);

        printf("%zu, %zu\n", ranges[index].Start, ranges[index].End);
        index++;
    }
    rangesCount = index;

    size_t *ingredientIds = malloc(1100 * sizeof(size_t));
    if (ingredientIds == NULL)
    {
        return 1;
    }

    index = 0;
    size_t ingredientIdsCount = 0;
    while (fgets(line, sizeof(line), filePointer))
    {
        ingredientIds[index] = strtol(line, NULL, 10);

        printf("Id: %zu\n", ingredientIds[index]);
        index++;
    }
    ingredientIdsCount = index;

    printf("rangesCount: %zu\n", rangesCount);
    printf("ingredientIdsCount: %zu\n", ingredientIdsCount);

    size_t freshCount = 0;
    for (size_t i = 0; i < ingredientIdsCount; i++)
    {
        if (InsideRange(ranges, ingredientIds[i], rangesCount))
        {
            freshCount++;
        }
    }

    printf("part 1: %zu\n", freshCount);

    return 0;
}
