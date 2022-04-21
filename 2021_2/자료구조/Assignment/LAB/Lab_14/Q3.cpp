/*
	QuickSort를 아래에 구현하였으며, 이와 같은방법으로 다른정렬알고리즘도 구현 가능할 것으로 보임.
*/

#include <iostream>
#include "Student.h"
#include "QSort_Pointer.h"
using namespace std;

void SelectionSortPointer(Student* values[], int numValues);

int main() {
	Student stu[100];
	stu[0].InitValue(2003200111, (char*)"이웅재", 3.0);
	stu[1].InitValue(2004200121, (char*)"권오준", 3.2);
	stu[2].InitValue(2005200132, (char*)"김진일", 2.7);
	stu[3].InitValue(2006200142, (char*)"황예닮", 2.9);

	Student* stuPtrs[4];

	for (int i = 0; i < 4; i++)
		stuPtrs[i] = &stu[i];

	cout << endl;
	SelectionSortPointer(stuPtrs, 4);
	
	PrintByPointer(cout, stuPtrs, 4);
	// 원데이터 변형 확인
	cout << "원 데이터\n";
	Print(cout, stu, 4);

	return 0;
}

void SelectionSortPointer(Student* values[], int numValues) {
	cout << "========== Choose Sorting Algorithm ==========\n";
	cout << "1. selectionSort(미구현)\n";
	cout << "2. bubbleSort(미구현)\n";
	cout << "3. insertionSort(미구현)\n";
	cout << "4. mergeSort(미구현)\n";
	cout << "5. quickSort\n";
	cout << "6. heapSort(미구현)\n";

	cout << "\n알고리즘을 선택하세요 (번호 입력) : ";
	int cmd;
	cin >> cmd;

	switch (cmd) {
	case 1:
		cout << "1\n";
		break;
	case 2:
		cout << "2\n";
		break;
	case 3:
		cout << "3\n";
		break;
	case 4:
		cout << "4\n";
		break;
	case 5:
		cout << "Start quickSort...\n";
		QuickSort_Pointer(values, 0, 3);
		cout << "Finish\n";
		break;
	case 6:
		cout << "6\n";
		break;
	}
}