/*
	QuickSort�� �Ʒ��� �����Ͽ�����, �̿� ����������� �ٸ����ľ˰��� ���� ������ ������ ����.
*/

#include <iostream>
#include "Student.h"
#include "QSort_Pointer.h"
using namespace std;

void SelectionSortPointer(Student* values[], int numValues);

int main() {
	Student stu[100];
	stu[0].InitValue(2003200111, (char*)"�̿���", 3.0);
	stu[1].InitValue(2004200121, (char*)"�ǿ���", 3.2);
	stu[2].InitValue(2005200132, (char*)"������", 2.7);
	stu[3].InitValue(2006200142, (char*)"Ȳ����", 2.9);

	Student* stuPtrs[4];

	for (int i = 0; i < 4; i++)
		stuPtrs[i] = &stu[i];

	cout << endl;
	SelectionSortPointer(stuPtrs, 4);
	
	PrintByPointer(cout, stuPtrs, 4);
	// �������� ���� Ȯ��
	cout << "�� ������\n";
	Print(cout, stu, 4);

	return 0;
}

void SelectionSortPointer(Student* values[], int numValues) {
	cout << "========== Choose Sorting Algorithm ==========\n";
	cout << "1. selectionSort(�̱���)\n";
	cout << "2. bubbleSort(�̱���)\n";
	cout << "3. insertionSort(�̱���)\n";
	cout << "4. mergeSort(�̱���)\n";
	cout << "5. quickSort\n";
	cout << "6. heapSort(�̱���)\n";

	cout << "\n�˰����� �����ϼ��� (��ȣ �Է�) : ";
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