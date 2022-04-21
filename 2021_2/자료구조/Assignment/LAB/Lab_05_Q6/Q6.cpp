#include <iostream>
#include "QueType.h"
using namespace std;

int main() {
	// IsEmpty를 이렇게 바꿔도 되는지 물어보고, 안된다고 하면 while IsEmpty를 여기다 어떻게 써야할지 물어보자.
	int elems[6] = { 5, 4, 2, 3, 1, 8 };
	QueType Q;
	QueType Q2;

	for (int elem : elems) {
		Q.Enqueue(elem);
		Q2.Enqueue(elem);
	}

	cout << "\n================================= pdf에 나온 예시와 동일하게 출력 =================================\n";
	cout << "current minimun_pos : " << Q.getMinimum_pos() << endl;

	int temp;
	Q.MinDequeue(temp);
	cout << "Dequeue minimum element" << endl;
	cout << "minimum element = " << temp << endl;

	cout << "current minimun_pos : " << Q.getMinimum_pos() << endl;
	Q.Enqueue(6);
	cout << "Enqueue 6" << endl;
	cout << "current minimun_pos : " << Q.getMinimum_pos() << endl;

	while (!Q.IsEmpty()) {
		int item;
		Q.Dequeue(item);
		cout << item << " ";
	}
	cout << endl;

	cout << "\n================================= MinDequeue 연속호출 테스트 =================================\n";
	while (!Q2.IsEmpty()) {
		int item;
		Q2.MinDequeue(item);
		cout << item << " ";
	}
	cout << endl;
	cout << Q2.getMinimum_pos() << endl;	

	return 0;
}