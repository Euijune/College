#pragma once
#include "Student.h"

void Merge(Student values[], int leftFirst, int leftLast, int rightFirst, int rightLast)
    // Post: values[leftFirst]..values[leftLast] and 
    //       values[rightFirst]..values[rightLast] have been merged.
    //       values[leftFirst]..values[rightLast] is now sorted.
{
    int arySize = rightLast - leftFirst + 1;
    Student* tempArray = new Student[arySize];
    int index = 0;  // leftFirst�� 0�� �ƴ� ���, arySize = 2�ε� index = 3���� �����ϴ� ��찡 �߻��Ѵ�. �̷��� ���� ����
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