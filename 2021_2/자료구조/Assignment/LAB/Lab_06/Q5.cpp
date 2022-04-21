#include <iostream>
#include "SortedType.h"

using namespace std;

int main() {
	int elems[5] = { 3, 2, 5, 6, 1 };
	int elems2[10] = { 4,4,3,3,2,2,1,1,0,0 };
	SortedType<int> list01, list02;

	for (int elem : elems)
		list01.InsertItem(elem);

	for (int elem : elems2)
		list02.InsertItem(elem);

	list01.DeleteItem_5A(44);
	list02.DeleteItem_5B(44);

	// print answer of Q5 - A
	int length_list01 = list01.LengthIs();
	for (int i = 0; i < length_list01; i++) {
		int temp;
		list01.GetNextItem(temp);
		cout << temp << " ";
	}
	cout << endl;

	// print answer of Q5 - B
	int length_list02 = list02.LengthIs();
	for (int i = 0; i < length_list02; i++) {
		int temp;
		list02.GetNextItem(temp);
		cout << temp << " ";
	}
	cout << endl;

	return 0;
}