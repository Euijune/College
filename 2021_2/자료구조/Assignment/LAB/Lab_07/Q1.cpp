#include <iostream>
#include "SortedType.h"

using namespace std;

int main() {
	SortedType<char> s1;
	SortedType<int> s2;
	s1.InsertItem('X');
	s1.InsertItem('Y');
	s1.InsertItem('Z');

	for (int i = 0; i < 5; i++) {
		s2.InsertItem(5-i);
	}

	s1.PrintReverse();
	s2.PrintReverse();

	return 0;
}