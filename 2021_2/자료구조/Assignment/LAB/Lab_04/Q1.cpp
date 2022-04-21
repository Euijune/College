#include <iostream>
#include "StackType.h"
#include "MaxItem.h"

using namespace std;

int main() {
	StackType<int> stack;

	for (int i = 1; i <= 6; i++) {
		stack.Push(i);
	}

	while (!stack.IsEmpty()) {
		int res = stack.Top();
		stack.Pop();
		cout << res << endl;
	}

	return 0;
}