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

    size_t totalRemovedRolls = 0;
    bool printPartOne = true;
    while (true)
    {
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
            }
        }
        if (printPartOne)
        {
            printf("Part1: %zu\n", accessableRolls);
            printPartOne = false;
        }
        if (accessableRolls > 0)
        {
            totalRemovedRolls += accessableRolls;
        }
        else
        {
            break;
        }

        for (size_t i = 0; i < grid->GridSize; i++)
        {
            if (grid->Grid[i] == 'X')
            {
                grid->Grid[i] = '.';
            }
        }
    }

    printf("Part2: %zu\n", totalRemovedRolls);
    DeleteGrid(&grid);
    return 0;
}
