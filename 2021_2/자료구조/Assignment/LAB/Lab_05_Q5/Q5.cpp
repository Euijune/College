#include <iostream>
#include "QueType.h"
using namespace std;

// �Լ��� �� �۵��ϴ��� Ȯ���غ� �ڵ��Դϴ�.
int main() {
	QueType Q(9);

	for (int i = 0; i < 10; i++) {
		Q.Enqueue(i * i);
	}

	cout << "Is Full?\n" << Q.IsFull() << endl;

	cout << "Item?\n";
	while (!Q.IsEmpty()) {
		int item;
		Q.Dequeue(item);
		cout << item << " ";
	}
	cout << endl;
	cout << "Is Empty?\n" << Q.IsEmpty() << endl;

	Q.Enqueue(999);
	cout << "Enqueue a number 999" << endl;
	cout << "Is Empty?\n" << Q.IsEmpty() << endl;
	Q.MakeEmpty();
	cout << "Make empty success!" << endl;
	cout << "Is Empty?\n" << Q.IsEmpty() << endl;

	return 0;
}