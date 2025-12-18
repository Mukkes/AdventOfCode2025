#include "Grid.h"
#include <stdlib.h>

void CreateGrid(Grid *grid, int rows, int columns)
{
    grid->Rows = rows;
    grid->Columns = columns;
    grid->Grid = malloc(rows * sizeof(char *));
    for (int i = 0; i < rows; i++)
    {
        grid->Grid[i] = malloc(columns * sizeof(char));
    }
}

void DeleteGrid(Grid *grid)
{
    for (int i = 0; i < grid->Rows; i++)
    {
        free(grid->Grid[i]);
    }
    free(grid->Grid);
}
