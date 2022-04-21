#pragma once
#include "Student.h"

void Merge(Student values[], int leftFirst, int leftLast, int rightFirst, int rightLast)
    // Post: values[leftFirst]..values[leftLast] and 
    //       values[rightFirst]..values[rightLast] have been merged.
    //       values[leftFirst]..values[rightLast] is now sorted.
{
    int arySize = rightLast - leftFirst + 1;
    Student* tempArray = new Student[arySize];
    int index = 0;  // leftFirst가 0이 아닐 경우, arySize = 2인데 index = 3부터 시작하는 경우가 발생한다. 이러한 오류 방지
    int saveFirst = leftFirst;

    while ((leftFirst <= leftLast) && (rightFirst <= rightLast))
    {
        if (values[leftFirst] < values[rightFirst])
        {
            tempArray[index] = values[leftFirst];
            leftFirst++;
        }
        else
        {
            tempArray[index] = values[rightFirst];
            rightFirst++;
        }
        index++;
    }

    while (leftFirst <= leftLast)
        // Copy remaining items from left half.

    {
        tempArray[index] = values[leftFirst];
        leftFirst++;
        index++;
    }

    while (rightFirst <= rightLast)
        // Copy remaining items from right half.
    {
        tempArray[index] = values[rightFirst];
        rightFirst++;
        index++;
    }

    int index_tempArr = 0;
    for (index = saveFirst; index <= rightLast; index++) {
        values[index] = tempArray[index_tempArr];
        index_tempArr++;
    }

    delete[] tempArray;
}

void MergeSort(Student values[], int first, int last)
// Post: The elements in values are sorted by key.
{
    if (first < last)
    {
        int middle = (first + last) / 2;
        MergeSort(values, first, middle);
        MergeSort(values, middle + 1, last);
        Merge(values, first, middle, middle + 1, last);
    }
}