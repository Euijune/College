#include <iostream>
#include "PQLLType.h"

/*
	Q2�� Heap���� ������ priority queue �� ��� ������ ��¦ �ٸ��� �翬�ϴ�.
*/

int x, y, z;
int elems[10] = { 56, 27, 42, 26, 15, 3, 19, 25, 24, 5 };
int cmd[6] = { 28, 2, 40, x, y, z };

int main() {
	PQLLType<int> pqLL;

	for (int elem : elems)
		pqLL.Enqueue(elem);
	pqLL.PRINT();

	for (int i = 0; i < 6; i++) {
		if (i < 3)
			pqLL.Enqueue(cmd[i]);
		else
			pqLL.Dequeue(cmd[i]);
	}
	pqLL.PRINT();
	std::cout << cmd[3] << " " << cmd[4] << " " << cmd[5] << '\n';


	return 0;
}