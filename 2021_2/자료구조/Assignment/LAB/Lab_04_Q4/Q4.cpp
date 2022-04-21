/*
문제 4번의 a는 ReplaceItem_a 로 Q4.cpp파일에 존재하며,
문제 4번의 b는 ReplaceItem_b 로 StackType.h에 존재합니다.
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
	// stack에 Push연산을 통해 값을 입력함.

	for (ItemType elem : elems) {
		stack.Push(elem);
	}

	//ReplaceItem_a(stack, 3, 5); // for testing Q4-a.
	stack.ReplaceItem_b(3, 15); // for testing Q4-b.

	while (!stack.IsEmpty()) //스택 내용 출력
	{
		ItemType item = stack.Top();
		stack.Pop();
		// cout << "Item : " << item << endl; // pdf에 쓰여있던, 원래 출력형식
		cout << item << " "; // 바꾼 출력형식
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