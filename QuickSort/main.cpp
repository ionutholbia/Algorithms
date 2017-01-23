#include <stdio.h>
#include <vector>
#include <iostream>

int Partition(std::vector<int>& array, int firstElement, int lastElement)
{
    int pivot = array[lastElement];
    int wall = firstElement;

    for(int i = firstElement; i < lastElement; i++)
    {
        if(array[i] < pivot)
        {
            std::swap(array[wall], array[i]);
            wall++;
        }
    }

    //swap the next wall with the pivot to it's real place
    std::swap(array[wall], array[lastElement]);
    return wall;
}

void QuickSort(std::vector<int>& array, int firstElement, int lastElement)
{   
    if(firstElement < lastElement)
    {
        int lastPartitionElement = Partition(array, firstElement, lastElement);
        QuickSort(array, firstElement, lastPartitionElement - 1);
        QuickSort(array, lastPartitionElement + 1, lastElement);
    }
}

int main(void)
{
    std::vector<int> array;
    array.push_back(3);
    array.push_back(56);
    array.push_back(4);
    array.push_back(1);
    array.push_back(67);
    array.push_back(2);
    array.push_back(7);
    array.push_back(32);
    array.push_back(1);

    QuickSort(array, 0, array.size() - 1);

    for (std::vector<int>::const_iterator i = array.begin(); i != array.end(); ++i)
    {
        std::cout << *i << ' '<< std::endl;
    }   

    return 0;
}