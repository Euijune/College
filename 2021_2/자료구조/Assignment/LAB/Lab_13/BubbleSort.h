#include "Student.h"

void BubbleUp(Student values[], int startIndex, int endIndex)
// Post: Adjacent pairs that are out of order have been 
//       switched between values[startIndex]..values[endIndex]
//       beginning at values[endIndex].
{
    for (int index = endIndex; index > startIndex; index--) {
        char* Name = values[index].getName();
        char* PreName = values[index - 1].getName();

        if (strncmp(Name, PreName, 3) < 0)  // Name < PreName
            Swap(values[index], values[index - 1]);
    }
}

void BubbleSort(Student values[], int numValues)
// Post: The elements in the array values are sorted by key.
{
    int current = 0;

    while (current < numValues - 1)
    {
        BubbleUp(values, current, numValues - 1);
        current++;
    }
}