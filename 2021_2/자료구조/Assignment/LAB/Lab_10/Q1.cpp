#include <iostream>
#include "TreeType.h"

char case1[7] = { 'k', 'd', 'o', 'a', 'f', 'x', 'v'};

TreeType tree1, tree2;

int main() {
	for (char elem : case1)
		tree1.InsertItem(elem);
	for (char elem : case1)
		tree2.InsertItem(elem);

	tree1.PrintCOUT();
	std::cout << '\n';

	tree1.DeleteItem('d');

	tree1.PrintCOUT();
	std::cout << '\n';

	tree2.PrintCOUT();
	std::cout << '\n';

	tree2.DeleteItem('o');

	tree2.PrintCOUT();
	std::cout << '\n';

}

// 디버깅 : 이것을 TreeType.cpp 와 .h에 추가하세요.
// Debug


// Debug

