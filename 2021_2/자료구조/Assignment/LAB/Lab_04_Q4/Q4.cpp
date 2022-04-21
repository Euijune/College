/*
���� 4���� a�� ReplaceItem_a �� Q4.cpp���Ͽ� �����ϸ�,
���� 4���� b�� ReplaceItem_b �� StackType.h�� �����մϴ�.
*/

#include <iostream>
#include "StackType.h"
using namespace std;

void ReplaceItem_a(StackType& st, int oldItem, int
	newItem);

int main()
{
	StackType stack;
	ItemType elems[8] = { 8, 3, 9, 8, 3, 7, 5, 3 };
	// stack�� Push������ ���� ���� �Է���.

	for (ItemType elem : elems) {
		stack.Push(elem);
	}

	//ReplaceItem_a(stack, 3, 5); // for testing Q4-a.
	stack.ReplaceItem_b(3, 15); // for testing Q4-b.

	while (!stack.IsEmpty()) //���� ���� ���
	{
		ItemType item = stack.Top();
		stack.Pop();
		// cout << "Item : " << item << endl; // pdf�� �����ִ�, ���� �������
		cout << item << " "; // �ٲ� �������
	}
	cout << endl; 
	return 0;
}

void ReplaceItem_a(StackType& st, ItemType oldItem, ItemType newItem)
{
	StackType stack;

	while (!st.IsEmpty()) {
		ItemType item = (st.Top() == oldItem) ? newItem : st.Top();
		st.Pop();
		stack.Push(item);
	}

	while (!stack.IsEmpty()) {
		ItemType item = stack.Top();
		stack.Pop();
		st.Push(item);
	}
}