#include "../Util/Grid.h"
#include "../Util/GridUtil.h"
#include "../Util/InputInfo.h"
#include "../Util/InputUtil.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    InputInfo *inputInfo = malloc(sizeof(InputInfo));
    char *fileName = "ExampleInput.txt";
    GetInputInfo(inputInfo, fileName);
    printf("rows: %d\n", inputInfo->rows);
    printf("columns: %d\n", inputInfo->columns);
    Grid *grid = malloc(sizeof(Grid));
    CreateGrid(grid, inputInfo->rows, inputInfo->columns);
    FILE *filePointer;
    filePointer = fopen(fileName, "r");
    if (filePointer == NULL)
    {
        return 0;
    }

    char line[inputInfo->columns + 2];
    int row = 0;
    while (fgets(line, sizeof(line), filePointer))
    {
        for (int i = 0; i < inputInfo->rows; i++)
        {
            grid->Grid[row][i] = line[i];
        }
        row++;
    }

    for (int i = 0; i < inputInfo->rows; i++)
    {
        for (int j = 0; j < inputInfo->columns; j++)
        {
            printf("%c", grid->Grid[i][j]);
        }
        printf("\n");
    }
    fclose(filePointer);
    free(grid);
    free(inputInfo);
    return 0;
}
