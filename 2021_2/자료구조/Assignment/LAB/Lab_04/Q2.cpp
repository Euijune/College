#include <iostream>
#include "MaxItem.h"
#include "StackType.h"

using namespace std;

StackType<int> StackCpy(StackType<int> old);
StackType<int> StackCpy_2(StackType<int> old);

int main() {
	StackType<int> A;
	StackType<int> C;
	StackType<int> D;
	int elems[6] = { 9,8,4,7,5,3 };

	// Making stack A
	for (int elem : elems) {
		A.Push(elem);
	}

	C = StackCpy(A);
	D = StackCpy_2(A);
	
	//test
	while (!C.IsEmpty()) {
		int temp = C.Top();
		C.Pop();
		cout << temp << " ";
	}
	cout << endl;
	while (!A.IsEmpty()) {
		int temp = A.Top();
		A.Pop();
		cout << temp << " ";
	}
	cout << endl;
	while (!D.IsEmpty()) {
		int temp = D.Top();
		D.Pop();
		cout << temp << " ";
	}
	cout << endl;


	return 0;
}

StackType<int> StackCpy(StackType<int> old) {
	StackType<int> old_cpy;
	StackType<int> New;

	// A -> C
	while (!old.IsEmpty()) {
		int temp = old.Top();
		old.Pop();
		old_cpy.Push(temp);
	}
	
	// C -> B
	while (!old_cpy.IsEmpty()) {
		int temp = old_cpy.Top();
		old_cpy.Pop();
		New.Push(temp);
	}

	return New;
};

// call by value 이므로 바로 복사가 된다.
// 하지만, 문제 의도는 StackCpy처럼 임시 stack을 만드는 것이다.
StackType<int> StackCpy_2(StackType<int> old) {

	return old;
};