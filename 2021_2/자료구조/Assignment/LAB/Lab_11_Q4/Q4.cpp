#include <iostream>
#include "StackPQType.h"

int main() {
	StackPQType<int> spq;

	spq.Push(3);
	spq.Push(6);
	spq.Pop();
	spq.Push(5);
	spq.Push(4);
	spq.Pop();
	spq.Push(7);
	spq.Push(11);
	spq.Push(2);
	spq.Push(1);
	spq.Pop();
	spq.Pop();

	return 0;
}

/*
	디버깅을 하려면, 아래 Debug in PQType.h 함수를 PQType.h에 추가하라.
	그 아래 Debug in StackPQType.h 의 함수는 StackPQType.h의 push와 pop연산 마지막에 추가하라.
*/
// Debug in PQType.h
//template<class ItemType>
//void PQType<ItemType>::PRINT()
//{
//	for (int i = 0; i < length; i++) {
//		std::cout << items.elements[i] << " ";
//	}
//	std::cout << '\n';
//}
//
//template<class ItemType>
//void PQType<ItemType>::PRINTTIMESTAMP() {
//	for (int i = 0; i < length; i++) {
//		std::cout << items.timestamp[i] << " ";
//	}
//	std::cout << '\n';
//}

// Debug in StackPQType.h
//items.PRINT();
//items.PRINTTIMESTAMP();
