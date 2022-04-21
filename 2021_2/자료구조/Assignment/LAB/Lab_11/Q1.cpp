#include <iostream>
#include "PQType.h"

/*
	PQType.h�� Enqueue, Dequeue�� ReheapUp / ReheapDown�� _nonrecur�ٿ��� test
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


// ����� : PQType.h�� �Ʒ� �Լ��� �߰��϶�.
// Debug
//template<class ItemType>
//void PQType<ItemType>::PRINT()
//{
//	for (int i = 0; i < length; i++) {
//		std::cout << items.elements[i] << " ";
//	}
//	std::cout << '\n';
//}

// ����� : PQLLType.h�� �Ʒ� �Լ��� �߰��϶�.
// Debug
//template<class ItemType>
//void PQLLType<ItemType>::PRINT()
//{
//	linkedlist.PRINT();
//}

// ����� : SortedType.h�� �Ʒ� �Լ��� �߰��϶�.
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
