#include <iostream>
#include "PQLLType.h"

/*
	Q2의 Heap으로 구현한 priority queue 와 출력 순서가 살짝 다른건 당연하다.
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