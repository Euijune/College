#include <iostream>
#include "StackType.h"
using namespace std;

int main() {
	int items[6] = { 3,1,2,5,4,6 };
	StackType origin, origin_deepcpy;

	for (int elem : items) {
		origin.Push(elem);
	}

	origin_deepcpy.Copy(origin);
	origin.Pop();
	origin.Push(777);

	/*origin_deepcpy.Pop();
	origin_deepcpy.Pop();
	origin_deepcpy.Push(333);
	origin_deepcpy.Push(444);*/

	while (!origin.IsEmpty()) {
		cout << origin.Top() << " ";
		origin.Pop();
	}
	cout << endl;

	while (!origin_deepcpy.IsEmpty()) {
		cout << origin_deepcpy.Top() << " ";
		origin_deepcpy.Pop();
	}
	cout << endl;

	return 0;
}