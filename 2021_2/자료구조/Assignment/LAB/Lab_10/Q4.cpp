#include <iostream>
#include "TreeType.h"

char case1[7] = { 'k', 'f', 'o', 'c', 'g', 'p', 'a'};
TreeType tree1;

int Smaller(TreeType tree, int value);

int main() {
	std::cout << Smaller(tree1, 'g') << '\n';
	std::cout << Smaller(tree1, 'p') << '\n';
	std::cout << Smaller(tree1, 'a') << '\n';

	return 0;
}

int Smaller(TreeType tree, int value)
{
	ItemType item;
	bool finished = false;
	int count = 0;
	tree.ResetTree(IN_ORDER);
	do {
		tree.GetNextItem(item, IN_ORDER, finished);
		if (item < value)
			count++;
		else
			finished = true;
	} while (!finished);
	return count;
}
