#include <iostream>
#include "TreeType.h"

char case1[8] = { 'k', 'd', 'o', 'a', 'm', 'l', 'x', 'w' };

TreeType tree1;

int main() {
	for (char elem : case1)
		tree1.InsertItem(elem);

	tree1.PrintCOUT();
	std::cout << "\n\n";

	tree1.Ancestors_re('x');	// pdf¿¹Á¦ 
	std::cout << '\n';
	tree1.Ancestors_re('l');	// leaf node ->info == value
	std::cout << '\n';
	tree1.Ancestors_re('n');
	std::cout << '\n';
	tree1.Ancestors_re('w');	// leaf node ->info != value
	std::cout << '\n';
	tree1.Ancestors_re('p');
	std::cout << '\n';
	tree1.Ancestors_re('k');	// root node

	return 0;
}