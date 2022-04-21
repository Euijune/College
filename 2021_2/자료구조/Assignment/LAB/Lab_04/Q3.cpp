#include <iostream>
#include "DoubleStackType.h"
#include "DoubleStack_MaxItem.h"

using namespace std;

int main() {
	DoubleStack ds;
	
	for (int i = 1; i <= 5; i++) {
		ds.Push(i);
	}
	for (int i = 1003; i <= 1007; i++) {
		ds.Push(i);
	}

	ds.Print();

	return 0;
}