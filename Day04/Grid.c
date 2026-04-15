#include "Grid.h"
#include <stdlib.h>

int CreateGrid(Grid **grid, size_t columns, size_t rows)
{
    void *pointer = malloc(sizeof(Grid));
    if (pointer == NULL)
    {
        return 1;
    }
    *grid = pointer;
    (*grid)->Columns = columns;
    (*grid)->Rows = rows;
    (*grid)->GridSize = columns * rows;
    void *gridPointer = malloc((*grid)->GridSize * sizeof(char));
    if (gridPointer == NULL)
    {
        return 1;
    }
    (*grid)->Grid = gridPointer;
    return 0;
}

void DeleteGrid(Grid **grid)
{
    free((*grid)->Grid);
    (*grid)->Grid = NULL;
    free(*grid);
    *grid = NULL;
}

void InsertIntoGrid(Grid *grid, size_t column, size_t row, char ch)
{
    if ((column < 0) || (column >= grid->Columns))
    {
        exit(1);
    }
    if ((row < 0) || (row >= grid->Rows))
    {
        exit(1);
    }
    size_t index = (row * grid->Columns) + column;
    grid->Grid[index] = ch;
}

char GetFromGrid(Grid *grid, size_t column, size_t row)
{
    if ((column < 0) || (column >= grid->Columns))
    {
        exit(1);
    }
    if ((row < 0) || (row >= grid->Rows))
    {
        exit(1);
    }
    size_t index = (row * grid->Columns) + column;
    return grid->Grid[index];
}

void GetAdjacentPositions(Grid *grid, size_t column, size_t row,
                          char adjacentPositions[8])
{
    if ((column < 0) || (column >= grid->Columns))
    {
        exit(1);
    }
    if ((row < 0) || (row >= grid->Rows))
    {
        exit(1);
    }

    int c = column - 1;
    int r = row - 1;
    if ((c >= 0) && (r >= 0))
    {
        adjacentPositions[0] = grid->Grid[(r * grid->Columns) + c];
    }
    c = column;
    r = row - 1;
    if (r >= 0)
    {
        adjacentPositions[1] = grid->Grid[(r * grid->Columns) + c];
    }
    c = column + 1;
    r = row - 1;
    if ((c < grid->Columns) && (r >= 0))
    {
        adjacentPositions[2] = grid->Grid[(r * grid->Columns) + c];
    }
    c = column - 1;
    r = row;
    if (c >= 0)
    {
        adjacentPositions[3] = grid->Grid[(r * grid->Columns) + c];
    }
    c = column + 1;
    r = row;
    if (c < grid->Columns)
    {
        adjacentPositions[4] = grid->Grid[(r * grid->Columns) + c];
    }
    c = column - 1;
    r = row + 1;
    if ((c >= 0) && (r < grid->Rows))
    {
        adjacentPositions[5] = grid->Grid[(r * grid->Columns) + c];
    }
    c = column;
    r = row + 1;
    if (r < grid->Rows)
    {
        adjacentPositions[6] = grid->Grid[(r * grid->Columns) + c];
    }
    c = column + 1;
    r = row + 1;
    if ((c < grid->Columns) && (r < grid->Rows))
    {
        adjacentPositions[7] = grid->Grid[(r * grid->Columns) + c];
    }
}
