#include <stdio.h>
#include <iostream>

#define SIZE 30

void printArray(const int arr[][SIZE], int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            std::cout<<" "<<arr[i][j]<<" ";
        }
        std::cout<<"\n";
    }
}

void spiral(int n, int output[][SIZE])
{
    bool increment = true;

    bool lineEnded = false;
    bool columnEndend = false;

    int line = 0;
    int column = 0;

    auto spiralSize = SIZE * SIZE;
    for(int number = 1; number <= spiralSize; number++) 
    {
        if(lineEnded && columnEndend) 
        {
            lineEnded = false;
            columnEndend = false;
        }

        if(columnEndend == false)
        {
            output[line][column] = number;
            auto nextColumn = increment ? column + 1 : column -1; 

            if(nextColumn == SIZE || output[line][nextColumn] != 0) {
                columnEndend = true;
                line = increment ? line + 1 : line -1; 
            } else {
                column = nextColumn;
            }

            continue;
        }

        if(lineEnded == false)
        {
            output[line][column] = number;
            auto nextLine = increment ? line + 1 : line -1; 

            if(nextLine == SIZE || output[nextLine][column] != 0) {
                lineEnded = true;

                increment = !increment;
                column = increment ? column + 1 : column -1; 
            } else {
                line = nextLine;
            }
        }
    }
}

int main(void)
{
    int array [SIZE][SIZE] = {0};
    spiral(SIZE, array);
    printArray(array, SIZE);
    return 0;
}