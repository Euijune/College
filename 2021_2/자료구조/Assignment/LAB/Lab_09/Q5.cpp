#include <iostream>
#include "TreeType.h"

char case1[6] = { '6', '3', '8', '2', '7', '9' };
char case2[5] = { '3', '2', '4', '1', '5' };
char case3[1] = { '1' };

TreeType tree1, tree2, tree3;

int main() {
	for (char elem : case1)
		tree1.InsertItem(elem);
	for (char elem : case2)
		tree2.InsertItem(elem);
	for (char elem : case3)
		tree3.InsertItem(elem);

	std::cout << tree1.SingleParentCount() << '\n';
	std::cout << tree2.SingleParentCount() << '\n';
	std::cout << tree3.SingleParentCount() << '\n';
}