#include <stdio.h>
#include <iostream>
#include <vector>

#define SIZE 30

using namespace std;

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

vector<int> spiralTraverse(const vector<vector<int>> array) {
    if(array.size() == 0) return {};
    if(array.size() == 1) return array[0];
    
    vector<vector<int>> visited(array.size(), vector<int>(array[0].size(), {0})); 
    vector<int> output;

    int line = 0;
    int column = 0;

    bool lineEnded = false;
    bool columnEnded = false;

    auto maxDim = array.size() * array[0].size();
    bool increment = true;

    while(output.size() < maxDim) {
        if(lineEnded && columnEnded) {
            lineEnded = false;
            columnEnded = false;
        }

        if(!columnEnded) {
            output.push_back(array[line][column]);
            visited[line][column] = 1;

            auto nextColumn = increment ? column + 1 : column - 1;
            if(nextColumn == array[0].size() || nextColumn == -1 || visited[line][nextColumn] == 1) {
                columnEnded = true;
                line = increment ? line + 1 : line -1; 
            } else {
                column = nextColumn;
            }
            continue;
        }

        if(!lineEnded) {
            output.push_back(array[line][column]);
            visited[line][column] = 1;

            auto nextLine = increment ? line + 1 : line - 1;
            if(nextLine == array.size() || visited[nextLine][column] == 1) {
                lineEnded = true;

                increment = !increment;
                column = increment ? column + 1 : column -1; 
            } else {
                line = nextLine;
            }
            continue;
        }
    }


    return output;
}

int main(void)
{
    int array [SIZE][SIZE] = {0};
    spiral(SIZE, array);
    printArray(array, SIZE);

    auto output = spiralTraverse({{4, 2, 3, 6, 7, 8, 1, 9, 5, 10}, {12, 19, 15, 16, 20, 18, 13, 17, 11, 14}, {12, 19, 15, 16, 20, 18, 13, 17, 11, 14}});
    for(auto iter : output) std::cout<<iter<<" ";
    return 0;
}