#include "Grid.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *fileName = "Input.txt";
    FILE *filePointer;
    filePointer = fopen(fileName, "r");
    if (filePointer == NULL)
    {
        return 1;
    }

    char ch;
    size_t columns = 0;
    size_t rows = 0;
    while ((ch = fgetc(filePointer)) != EOF)
    {
        if (ch != '\n')
        {
            columns++;
        }
        else
        {
            rows++;
        }
    }

    columns = columns / rows;
    Grid *grid;
    if (CreateGrid(&grid, columns, rows) > 0)
    {
        return 1;
    }
    printf("rows: %zu\n", grid->Rows);
    printf("columns: %zu\n", grid->Columns);

    rewind(filePointer);
    size_t column = 0;
    size_t row = 0;
    while ((ch = fgetc(filePointer)) != EOF)
    {
        if (ch != '\n')
        {
            InsertIntoGrid(grid, column, row, ch);
            column++;
        }
        else
        {
            column = 0;
            row++;
        }
    }

    fclose(filePointer);

    size_t accessableRolls = 0;
    for (row = 0; row < grid->Rows; row++)
    {
        for (column = 0; column < grid->Columns; column++)
        {
            if (GetFromGrid(grid, column, row) != '@')
            {
                continue;
            }

            char adjacentPositions[8] = {0};
            size_t rollsOfPaper = 0;
            GetAdjacentPositions(grid, column, row, adjacentPositions);
            for (size_t i = 0; i < 8; i++)
            {
                if ((adjacentPositions[i] == '@') ||
                    (adjacentPositions[i] == 'X'))
                {
                    rollsOfPaper++;
                }
            }
            if (rollsOfPaper < 4)
            {
                InsertIntoGrid(grid, column, row, 'X');
                accessableRolls++;
            }
            for (size_t i = 0; i < 8; i++)
            {
                printf("%c", adjacentPositions[i]);
            }
            printf("\tRolls of paper[%zu,%zu]: %zu\n", column, row,
                   rollsOfPaper);
        }
    }

    for (row = 0; row < grid->Rows; row++)
    {
        for (column = 0; column < grid->Columns; column++)
        {
            printf("%c", GetFromGrid(grid, column, row));
        }
        printf("\n");
    }

    printf("\n");
    printf("Part1: %zu\n", accessableRolls);
    DeleteGrid(&grid);
    return 0;
}
