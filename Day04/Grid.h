#ifndef GRID_H
#define GRID_H

#include <stdio.h>

typedef struct Grid
{
    size_t Rows;
    size_t Columns;
    size_t GridSize;
    char *Grid;
} Grid;

int CreateGrid(Grid **grid, size_t columns, size_t rows);
void DeleteGrid(Grid **grid);
void InsertIntoGrid(Grid *grid, size_t column, size_t row, char ch);
char GetFromGrid(Grid *grid, size_t column, size_t row);
void GetAdjacentPositions(Grid *grid, size_t column, size_t row,
                          char adjacentPositions[8]);

#endif
