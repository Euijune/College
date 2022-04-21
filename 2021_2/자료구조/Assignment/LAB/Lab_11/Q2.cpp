#include <iostream>
#include "PQType.h"

int x, y, z;
int elems[10] = { 56, 27, 42, 26, 15, 3, 19, 25, 24, 5 };
int cmd[6] = { 28, 2, 40, x, y, z };

int main() {
	PQType<int> pq(15);

	for (int elem : elems)
		pq.Enqueue(elem);
	pq.PRINT();

	for (int i = 0; i < 6; i++) {
		if (i < 3)
			pq.Enqueue(cmd[i]);
		else
			pq.Dequeue(cmd[i]);
	}
	pq.PRINT();
	std::cout << cmd[3] << " " << cmd[4] << " " << cmd[5] << '\n';


	return 0;
}
