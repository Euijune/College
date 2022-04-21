#include <iostream>
#include "QueType.h"

using namespace std;

void MergeQueue(QueType queue1, QueType queue2, QueType& result)
{
	ItemType tempItem1;
	ItemType tempItem2;
	while (_____[a]_____) {
		queue1.Dequeue(tempItem1);
		queue2.Dequeue(tempItem2);


		if (_____[b]_____) {
			result.Enqueue(tempItem1);
			result.Enqueue(tempItem2);
		}
		else {
			result.Enqueue(tempItem2);
			result.Enqueue(tempItem1);
		}
	}


	while (_____[c]_____) {
		queue1.Dequeue(tempItem1);
		reuslt.Enqueue(tempItem1);
	}


	while (_____[d]_____) {
		queue2.Dequeue(tempItem2);
		result.Enqueue(tempItem2);
	}
}

int main() {
	int elems[5] = { 1,2,3,4,5 };
	int elems2[6] = { 6,7,8,9,10,11 };
	QueType Q_A;
	QueType Q_B;
	QueType result;

	for (int elem : elems) {
		Q_A.Enqueue(elem);
	}
	for (int elem : elems2) {
		Q_B.Enqueue(elem);
	}

	MergeQueue(Q_A, Q_B, result);

	return 0;
}