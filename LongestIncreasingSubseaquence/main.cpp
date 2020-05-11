#include <vector>
#include <stdio.h>

/*

Find the longest increasing subsequence of a given array of integers, A.

In other words, find a subsequence of array in which the subsequence’s elements are in strictly increasing order, and in which the subsequence is as long as possible.
This subsequence is not necessarily contiguous, or unique.
In this case, we only care about the length of the longest increasing subsequence.


Input 2:
    A = [0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15]
    
Output 2:
    6
*/


int getLongestSubsequenceLenght(std::vector<int>& input)
{
    std::vector<int> map(input.size(), 1);

    int maxLenght = 1;

    for(int mapIndex = 1; mapIndex < input.size(); mapIndex++)
    {
        auto currentRunMax = map[mapIndex];
        for(int movingIndex = 0; movingIndex < mapIndex; movingIndex++) {
            if(input[movingIndex] > input[mapIndex]) continue;

            if(map[movingIndex] + map[mapIndex] > currentRunMax) {
                currentRunMax = map[movingIndex] + map[mapIndex];
            }
        }

        map[mapIndex] = currentRunMax;

        if(currentRunMax > maxLenght) {
            maxLenght = currentRunMax;
        }
    }

    return maxLenght;
}

int main(void) 
{
    std::vector<int> input = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    printf("Maximum Lenght: %d", getLongestSubsequenceLenght(input));
    return 0;
}