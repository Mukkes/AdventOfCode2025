#include "InputUtil.h"
#include "InputInfo.h"
#include <stdio.h>

void GetInputInfo(InputInfo *inputInfo, char *inputFileName)
{
    FILE *filePointer;
    filePointer = fopen(inputFileName, "r");
    if (filePointer == NULL)
    {
        return;
    }

    char ch;
    int rows = 0;
    int columns = 0;
    while ((ch = fgetc(filePointer)) != EOF)
    {
        if (ch != '\n')
        {
            columns++;
        }
        else
        {
            if (columns > inputInfo->columns)
            {
                inputInfo->columns = columns;
            }
            columns = 0;
            rows++;
        }
    }
    fclose(filePointer);
    inputInfo->rows = rows;
}
