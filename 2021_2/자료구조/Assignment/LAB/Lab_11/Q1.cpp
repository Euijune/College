#include <iostream>
#include "PQType.h"

/*
	PQType.h의 Enqueue, Dequeue의 ReheapUp / ReheapDown을 _nonrecur붙여서 test
*/

char items[7] = { 'E', 'H', 'I', 'D', 'G', 'F', 'A' };

int main() {
	PQType<char> pq(7);
	for (char item : items)
		pq.Enqueue(item);
	pq.PRINT();

	char temp;
	pq.Dequeue(temp);
	std::cout << temp << '\n';
	pq.PRINT();

	pq.Dequeue(temp);
	std::cout << temp << '\n';
	pq.PRINT();

	return 0;
}


// 디버깅 : PQType.h에 아래 함수를 추가하라.
// Debug
//template<class ItemType>
//void PQType<ItemType>::PRINT()
//{
//	for (int i = 0; i < length; i++) {
//		std::cout << items.elements[i] << " ";
//	}
//	std::cout << '\n';
//}

// 디버깅 : PQLLType.h에 아래 함수를 추가하라.
// Debug
//template<class ItemType>
//void PQLLType<ItemType>::PRINT()
//{
//	linkedlist.PRINT();
//}

// 디버깅 : SortedType.h에 아래 함수를 추가하라.
//template <class ItemType>
//void SortedType<ItemType>::PRINT() {
//	ResetList();
//	ItemType temp;
//	for (int i = 0; i < length; i++) {
//		GetNextItem(temp);
//		std::cout << temp << " ";
//	}
//	std::cout << '\n';
//}
