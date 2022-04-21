#include <iostream>
#include "QueType.h"
using namespace std;

// 함수가 잘 작동하는지 확인해본 코드입니다.
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