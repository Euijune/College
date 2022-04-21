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

	// (11, 7, 2) 3���� case�� ���� ���� Ž���� �õ��մϴ�.
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
		�ش��ϴ� ���� ���� ���, value���� ���� ���� �� ���� ū ���� ��ȯ�϶�µ� 
		�̰��� midpoint(���� ��)�ΰ�, first(��� ��)�ΰ�?
		midpoint�� �´�. �� �����غ���.
		Ex) 1 2 4 5 6 7 ���� search 3 �ϴ� ��� �� 1 3 4 5 6 ���� search 2�ϴ� ���
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
	cout << resultA << endl; // -1 ����

	resultA = BinarySearch_A(array, sizeOfArray, Value[1]);
	cout << resultA << endl; // 6 ����

	resultA = BinarySearch_A(array, sizeOfArray, Value[2]);
	cout << resultA << endl; // 1 ����

	cout << "============================ Q2 - B ANSWER ==============================" << endl;

	resultB = BinarySearch_B(array, sizeOfArray, Value[0]);
	cout << resultB << endl; // 10 ����

	resultB = BinarySearch_B(array, sizeOfArray, Value[1]);
	cout << resultB << endl; // 7 ����

	resultB = BinarySearch_B(array, sizeOfArray, Value[2]);
	cout << resultB << endl; // 2 ����

	cout << "============================ Q2 - C ANSWER ==============================" << endl;

	resultC = BinarySearch_C(array, sizeOfArray, Value[0]);
	cout << resultC << endl; // -1 ����

	resultC = BinarySearch_C(array, sizeOfArray, Value[1]);
	cout << resultC << endl; // 7 ����

	resultC = BinarySearch_C(array, sizeOfArray, Value[2]);
	cout << resultC << endl; // 2 ����
}