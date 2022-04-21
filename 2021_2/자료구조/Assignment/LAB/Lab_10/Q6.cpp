#include <iostream>
#include "UnsortedType.h"
#include "TreeType.h"

ItemType elems[7] = { 'g', 'k', 'z', 'h', 'b', 'e', 'a' };	// Unsorted List 원소
ItemType elems2[7] = { 'g', 'b', 'a', 'e', 'k', 'h', 'z' };	// Tree 원소

bool MatchingItem_Unsorted(TreeType& tree, UnsortedType<ItemType>& list);

int main() {
	UnsortedType<ItemType> list;
	TreeType tree;

	for (ItemType elem : elems)
		list.InsertItem(elem);

	for (ItemType elem : elems2)
		tree.InsertItem(elem);

	// view
	ItemType temp;
	for (int i = 0; i < list.LengthIs(); i++) {
		list.GetNextItem(temp);
		std::cout << (char)temp << " ";
	}
	std::cout << '\n';
	tree.PrintCOUT();
	std::cout << '\n';

	std::cout<<MatchingItem_Unsorted(tree, list);

	return 0;
}

bool MatchingItem_Unsorted(TreeType& tree, UnsortedType<ItemType>& list)
{
	int list_length = list.LengthIs();
	int tree_length = tree.LengthIs();
	if (list_length != tree_length) //길이를 먼저 비교, 같은지 검사한다.
		return false;
	else
	{
		ItemType item;
		bool found;
		list.ResetList(); //list에 iterator를 사용할 준비를 한다
		for (int i = 0; i < list_length; i++) {
			list.GetNextItem(item); // list에서 하나의 아이템을 가져온다
			tree.RetrieveItem(item, found); //트리에 해당 아이템이 있는지 검색. O(logN)이 걸림.

			if (!found)	return false;
		}

		return true;
	}
}

/*
	아이템을 list에서 가져와 tree로 찾는 방법은 O(logN)의 복잡도를 가진다.
	
		우리가 사용하는 TreeType은 Binary search tree기 때문에, 값이 정렬된 이 tree에서 어떤 값을 찾는것은
		정렬된 list에서 이진 탐색을 사용하는 경우와 동일하다. 즉, 복잡도는 이진 탐색의 복잡도 O(log N)과 같다.

	아이템을 tree에서 가져와 list로 찾는 방법은 O(N)의 복잡도를 가진다.

		우리가 사용하는 list는 정렬이 되지 않은 Unsorted Type이다. 정렬되지 않는 list에서 특정 값을 찾는 경우는
		최악의 경우, 모든 인덱스를 탐색해야 하기때문에 O(N)의 복잡도를 가진다. 그렇기에 tree에서 가져온 아이템을 list로 찾는것은
		O(N)의 복잡도를 갖는 것이다.
*/