#include <iostream>
#include "StackType.h"

using namespace std;

void ReplaceItem(StackType& stack, ItemType oldItem, ItemType newItem);

int main() {
	ItemType elems[7] = { 8, 5, 2, 1, 1, 3, 1};
	StackType s1, s2;

	for (ItemType& elem : elems) {
		s1.Push(elem);
		s2.Push(elem);
	}

	// before ReplaceItem : 1 3 1 1 2 5 3
	ReplaceItem(s1, 1, 11);
	s2.ReplaceItem(1, 22);

	// print result of Q1 - A
	while (!s1.IsEmpty()) {
		cout << s1.Top() << " ";
		s1.Pop();
	}
	cout << endl;

	// print result of Q1 - B
	while (!s2.IsEmpty()) {
		cout << s2.Top() << " ";
		s2.Pop();
	}
	cout << endl;

	return 0;
}

// Q1 - A
void ReplaceItem(StackType& stack,ItemType oldItem, ItemType newItem)
{
	StackType temp_stack; //백업용 스택
	ItemType temp_Item; // top을 받는 아이템
	while (!stack.IsEmpty())
	{
		temp_Item = stack.Top();
		stack.Pop();

		//top의 결과가 oldItem과 같거나 다를 경우, temp_stack에 넣는 부분
		if (temp_Item == oldItem)
		{
			temp_stack.Push(newItem);
		}
		else {
			temp_stack.Push(temp_Item);
		}
	}
	while (!temp_stack.IsEmpty())
	{
		temp_Item = temp_stack.Top();
		temp_stack.Pop();
		stack.Push(temp_Item);
	}
}