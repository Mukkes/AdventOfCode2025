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

bool DoesRangeOverlap(Range *rangeA, Range *rangeB)
{
    if ((rangeB->Start >= rangeA->Start) && (rangeB->Start <= rangeA->End))
    {
        return true;
    }
    if ((rangeB->End >= rangeA->Start) && (rangeB->End <= rangeA->End))
    {
        return true;
    }
    return false;
}

bool DoRangesOverlap(Range *rangeA, Range *rangeB)
{
    if (DoesRangeOverlap(rangeA, rangeB))
    {
        return true;
    }
    if (DoesRangeOverlap(rangeB, rangeA))
    {
        return true;
    }
    return false;
}

Range MergeRanges(Range *rangeA, Range *rangeB)
{
    Range result;
    if (rangeA->Start < rangeB->Start)
    {
        result.Start = rangeA->Start;
    }
    else
    {
        result.Start = rangeB->Start;
    }
    if (rangeA->End > rangeB->End)
    {
        result.End = rangeA->End;
    }
    else
    {
        result.End = rangeB->End;
    }
    return result;
}

void SortRanges(Range *ranges, size_t count)
{
    for (size_t i = 0; i < count; i++)
    {
        for (size_t j = 1; j < count; j++)
        {
            if (ranges[j - 1].Start > ranges[j].Start)
            {
                Range tmp;
                tmp.Start = ranges[j - 1].Start;
                tmp.End = ranges[j - 1].End;
                ranges[j - 1].Start = ranges[j].Start;
                ranges[j - 1].End = ranges[j].End;
                ranges[j].Start = tmp.Start;
                ranges[j].End = tmp.End;
            }
        }
    }
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

    SortRanges(ranges, rangesCount);

    Range *mergedRanges = malloc(200 * sizeof(Range));
    if (mergedRanges == NULL)
    {
        return 1;
    }

    size_t mergedRangesCount = 0;
    for (size_t i = 0; i < rangesCount; i++)
    {
        bool overlap = false;
        for (size_t j = 0; j < mergedRangesCount; j++)
        {
            if (DoRangesOverlap(&ranges[i], &mergedRanges[j]))
            {
                Range mergedRange = MergeRanges(&ranges[i], &mergedRanges[j]);
                mergedRanges[j].Start = mergedRange.Start;
                mergedRanges[j].End = mergedRange.End;
                printf("m mergedrange[%zu]: start: %zu end: %zu\n", j,
                       mergedRanges[j].Start, mergedRanges[j].End);
                overlap = true;
            }
        }
        if (!overlap)
        {
            mergedRanges[mergedRangesCount].Start = ranges[i].Start;
            mergedRanges[mergedRangesCount].End = ranges[i].End;
            printf("a mergedrange[%zu]: start: %zu end: %zu\n",
                   mergedRangesCount, mergedRanges[mergedRangesCount].Start,
                   mergedRanges[mergedRangesCount].End);
            mergedRangesCount++;
        }
    }

    size_t totalFresh = 0;
    for (size_t i = 0; i < mergedRangesCount; i++)
    {
        totalFresh += mergedRanges[i].End - mergedRanges[i].Start + 1;
        printf("mergedrange[%zu]: start: %zu end: %zu\n", i,
               mergedRanges[i].Start, mergedRanges[i].End);
    }

    printf("mergedRangesCount: %zu\n", mergedRangesCount);

    printf("part 2: %zu\n", totalFresh);

    return 0;
}
