#include <iostream>
#include "StackType.h"

using namespace std;

int main() {
	StackType s1;
	ItemType elems[7] = { 8, 5, 2, 1, 1, 3, 1 };

	for (ItemType& elem : elems) {
		s1.Push(elem);
	}

	s1.Print();
	cout << endl;

	while (!s1.IsEmpty()) {
		cout << s1.Top() << " ";
		s1.Pop();
	}
	cout << endl;
}