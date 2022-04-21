#pragma once
#include "Student.h"

void Split(Student* values[], int first, int last, int& splitPoint) {
    Student splitVal = *values[first];
    int saveFirst = first;
    bool onCorrectSide;

    first++;
    do
    {
        onCorrectSide = true;
        while (onCorrectSide)         // Move first toward last.
            if (splitVal < *values[first])
                onCorrectSide = false;
            else
            {
                first++;
                onCorrectSide = (first <= last);
            }

        onCorrectSide = (first <= last);
        while (onCorrectSide)             // Move last toward first.
            if (*values[last] <= splitVal)
                onCorrectSide = false;
            else
            {
                last--;
                onCorrectSide = (first <= last);
            }

        if (first < last)
        {
            splitVal.Swap(values[first], values[last]);
            first++;
            last--;
        }
    } while (first <= last);

    splitPoint = last;
    splitVal.Swap(values[saveFirst], values[splitPoint]);
}

void QuickSort_Pointer(Student* values[], int first, int last)
{
    if (first < last)
    {
        int splitPoint;

        Split(values, first, last, splitPoint);
        // values[first]..values[splitPoint-1] <= splitVal
        // values[splitPoint] = splitVal
        // values[splitPoint+1]..values[last] > splitVal

        QuickSort_Pointer(values, first, splitPoint - 1);
        QuickSort_Pointer(values, splitPoint + 1, last);
    }
}