#include <iostream>
#include "TreeType.h"

char case1[5] = { '6', '3', '8', '2', '7' };
char case2[5] = { '3', '2', '4', '1', '5' };

TreeType tree1, tree2;

int main() {
	for (char elem : case1)
		tree1.InsertItem(elem);
	for (char elem : case2)
		tree2.InsertItem(elem);

	std::cout << tree1.IsBST() << '\n';
	std::cout << tree2.IsBST();
}