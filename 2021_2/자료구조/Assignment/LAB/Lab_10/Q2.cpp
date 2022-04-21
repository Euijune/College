#include <iostream>
#include "TreeType.h"

char case1[8] = { 'k', 'd', 'o', 'a', 'm', 'l', 'x', 'w' };

TreeType tree1;

int main() {
	for (char elem : case1)
		tree1.InsertItem(elem);

	tree1.PrintCOUT();
	std::cout << "\n\n";

	tree1.Ancestors('x');	// pdf¿¹Á¦ 
	tree1.Ancestors('l');	// leaf node ->info == value
	tree1.Ancestors('n');	
	tree1.Ancestors('w');	// leaf node ->info != value
	tree1.Ancestors('p');
	tree1.Ancestors('k');	// root node

	return 0;
}