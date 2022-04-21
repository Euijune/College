#include <iostream>
#include "ItemType.h"
#include "sorted.h"

using namespace std;

int BinarySearch_A(int array[], int sizeOfArray, int value);
int BinarySearch_B(int array[], int sizeOfArray, int value);
int BinarySearch_C(int array[], int sizeOfArray, int value);

void TestBinSearch(int array[], int sizeOfArray, int Value[]);

int main() {
	int list[10] = {1,2,3,4,5,6,7,8,9,10 };
	int list_size = sizeof(list) / sizeof(int);

	// (11, 7, 2) 3가지 case에 대해 이진 탐색을 시도합니다.
	int value[3] = { 11, 7, 2 };

	TestBinSearch(list, list_size, value);

	return 0;
}

int BinarySearch_A(int array[], int sizeOfArray, int value) {
	int midPoint;
	int first = 0;
	int last = sizeOfArray - 1;
	bool moreToSearch = (first <= last);

	while (moreToSearch)
	{
		midPoint = (first + last) / 2;

		if (value < array[midPoint]) {	// LESS
			last = midPoint - 1;
			moreToSearch = (first <= last);
		}
		else if (value > array[midPoint]) {	// GREATER
			first = midPoint + 1;
			moreToSearch = (first <= last);
		}
		else {	// EQUAL
			return midPoint;
		}
	}

	return -1;
}

int BinarySearch_B(int array[], int sizeOfArray, int value) {

	/*
		해당하는 값이 없을 경우, value보다 작은 값들 중 가장 큰 값을 반환하라는데 
		이것은 midpoint(나의 답)인가, first(모범 답)인가?
		midpoint가 맞다. 잘 생각해보자.
		Ex) 1 2 4 5 6 7 에서 search 3 하는 경우 와 1 3 4 5 6 에서 search 2하는 경우
	*/
	int midPoint = -1;
	int first = 0;
	int last = sizeOfArray - 1;
	bool moreToSearch = (first <= last);

	while (moreToSearch)
	{
		midPoint = (first + last) / 2;

		if (value < array[midPoint]) {	// LESS
			last = midPoint - 1;
			moreToSearch = (first <= last);
		}
		else if (value > array[midPoint]) {	// GREATER
			first = midPoint + 1;
			moreToSearch = (first <= last);
		}
		else {	// EQUAL
			return array[midPoint];
		}
	}

	midPoint = (first + last) / 2;
	return array[midPoint];
}

int BinarySearch_C(int array[], int sizeOfArray, int value) {
	int midPoint = -1;
	int first = 0;
	int last = sizeOfArray - 1;
	bool moreToSearch = (first <= last);

	while (moreToSearch)
	{
		midPoint = (first + last) / 2;

		if (value < array[midPoint]) {	// LESS
			last = midPoint - 1;
			moreToSearch = (first <= last);
		}
		else if (value > array[midPoint]) {	// GREATER
			first = midPoint + 1;
			moreToSearch = (first <= last);
		}
		else {	// EQUAL
			return array[midPoint];
		}
	}

	midPoint = (first + last) / 2 + 1;
	if (midPoint >= sizeOfArray) {
		return -1;
	}
	else {
		return array[midPoint];
	}	
}

void TestBinSearch(int array[], int sizeOfArray, int Value[]) {
	cout << "============================ Q2 - A ANSWER ==============================" << endl;
	int resultA, resultB, resultC;

	resultA = BinarySearch_A(array, sizeOfArray, Value[0]);
	cout << resultA << endl; // -1 리턴

	resultA = BinarySearch_A(array, sizeOfArray, Value[1]);
	cout << resultA << endl; // 6 리턴

	resultA = BinarySearch_A(array, sizeOfArray, Value[2]);
	cout << resultA << endl; // 1 리턴

	cout << "============================ Q2 - B ANSWER ==============================" << endl;

	resultB = BinarySearch_B(array, sizeOfArray, Value[0]);
	cout << resultB << endl; // 10 리턴

	resultB = BinarySearch_B(array, sizeOfArray, Value[1]);
	cout << resultB << endl; // 7 리턴

	resultB = BinarySearch_B(array, sizeOfArray, Value[2]);
	cout << resultB << endl; // 2 리턴

	cout << "============================ Q2 - C ANSWER ==============================" << endl;

	resultC = BinarySearch_C(array, sizeOfArray, Value[0]);
	cout << resultC << endl; // -1 리턴

	resultC = BinarySearch_C(array, sizeOfArray, Value[1]);
	cout << resultC << endl; // 7 리턴

	resultC = BinarySearch_C(array, sizeOfArray, Value[2]);
	cout << resultC << endl; // 2 리턴
}