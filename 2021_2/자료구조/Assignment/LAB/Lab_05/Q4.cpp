#include <iostream>
#include "QueTypeTemplate.h"
using namespace std;

void sendItem(QueType<int>& queue1, QueType<int>& queue2, int& item);
int Length(QueType<int>& queue);
//int Length_callByValue(QueType<int> queue);

int main() {
	int elems[6] = { 7,4,5,6,9,10 };
	QueType<int> Q;

	for (int elem : elems) {
		Q.Enqueue(elem);
	}

	// Answer of Q4 - a
	cout << Length(Q) << endl;
	cout << Q.IsEmpty() << endl;
	// Answer of Q4 - b
	cout << Q.Length() << endl;
	cout << Q.IsEmpty() << endl;	

	return 0;
}

void sendItem(QueType<int>& queue1, QueType<int>& queue2, int& item) {
	queue1.Dequeue(item);
	queue2.Enqueue(item);
}

// Q4 - a
int Length(QueType<int>& queue)
{
	int count = 0, item = -1;
	QueType<int> temp_Q;

	while (!queue.IsEmpty()) {
		sendItem(queue, temp_Q, item);
		count++;
	}

	while (!temp_Q.IsEmpty())
		sendItem(temp_Q, queue, item);

	return count;
}

// 중복 해제 오류발생
//int Length_callByValue(QueType<int> queue)
//{
//	int count = 0, item = -1;
//
//	while (!queue.IsEmpty()) {
//		queue.Dequeue(item);
//		count++;
//	}
//
//	return count;
//}