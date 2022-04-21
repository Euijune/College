#include <iostream>
#include "UnsortedType.h"

using namespace std;

int main() {
	int elems[5] = { 3, 2, 5, 6, 1 };
	int elems2[10] = { 0,0,1,1,2,2,3,3,4,4 };
	UnsortedType<int> list01, list02;

	for (int elem : elems)
		list01.InsertItem(elem);

	for (int elem : elems2)
		list02.InsertItem(elem);

	list01.DeleteItem_4A(44);
	list02.DeleteItem_4B(4);

	// print answer of Q4 - A
	int length_list01 = list01.LengthIs();
	for (int i = 0; i < length_list01; i++) {
		int temp;
		list01.GetNextItem(temp);
		cout << temp << " ";
	}
	cout << endl;

	// print answer of Q4 - B
	int length_list02 = list02.LengthIs();
	for (int i = 0; i < length_list02; i++) {
		int temp;
		list02.GetNextItem(temp);
		cout << temp << " ";
	}
	cout << endl;

	

	return 0;
}