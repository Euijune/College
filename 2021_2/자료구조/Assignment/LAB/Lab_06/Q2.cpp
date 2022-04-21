#include <iostream>
#include "QueType.h"

using namespace std;

template <class ItemType>
void ReplaceItem(QueType<ItemType>& queue, ItemType oldItem, ItemType newItem);

int main() {
	int elems[10] = { 0,0,1,1,2,2,3,3,4,4 };
	QueType<int> q1, q2;

	for (int elem : elems) {
		q1.Enqueue(elem);
		q2.Enqueue(elem);
	}
	
	ReplaceItem(q1, 4, 11);
	q2.ReplaceItem(4, 22);

	// print result of Q2 - A
	while (!q1.IsEmpty()) {
		int temp;
		q1.Dequeue(temp);
		cout << temp << " ";
	}
	cout << endl;

	// print result of Q2 - B
	while (!q2.IsEmpty()) {
		int temp;
		q2.Dequeue(temp);
		cout << temp << " ";
	}
	cout << endl;
	
	return 0;
}

// Q2 - A
template <class ItemType>
void ReplaceItem(QueType<ItemType>& queue, ItemType oldItem, ItemType newItem)
{
	QueType<int> temp_queue;
	int temp_Item;

	while (!queue.IsEmpty())
	{
		//Dequeue
		queue.Dequeue(temp_Item);

		if (temp_Item == oldItem)
		{
			temp_queue.Enqueue(newItem);
		}
		else {
			temp_queue.Enqueue(temp_Item);
		}
	}
		while (!temp_queue.IsEmpty())
		{
			temp_queue.Dequeue(temp_Item);
			queue.Enqueue(temp_Item);
		}
}