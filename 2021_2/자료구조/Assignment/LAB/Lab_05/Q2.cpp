#include <iostream>
#include "QueTypeTemplate.h"
using namespace std;

void ReplaceItem(QueType<int>& queue, int oldItem, int newItem);

// operating with QueTypeTemplate.cpp
int main() {
	int elems[10] = { 2,6,7,4,5,6,10,15,6,6 };
	QueType<int> Q_A;
	QueType<int> Q_B;

	for (int elem : elems) {
		Q_A.Enqueue(elem);
		Q_B.Enqueue(elem);
	}

	ReplaceItem(Q_A, 6, 20);
	Q_B.ReplaceItem(6, 22);

	// Answer of Q2 - A
	cout << "After replacing Q_A : ";
	while (!Q_A.IsEmpty()) {
		int elem;
		Q_A.Dequeue(elem);

		cout << elem << " ";
	}
	cout << endl;

	// Answer of Q2 - B
	cout << "After replacing Q_B : ";
	while (!Q_B.IsEmpty()) {
		int elem;
		Q_B.Dequeue(elem);

		cout << elem << " ";
	}
	cout << endl;

	return 0;
}

// Q2 - A
void ReplaceItem(QueType<int>& queue, int oldItem, int newItem) {
	QueType<int> temp_Q;
	
	int item;
	while (!queue.IsEmpty())
	{
		queue.Dequeue(item);
		if (oldItem == item)	temp_Q.Enqueue(newItem);
		else					temp_Q.Enqueue(item);
	}

	while (!temp_Q.IsEmpty())
	{
		temp_Q.Dequeue(item);
		queue.Enqueue(item);
	}
}