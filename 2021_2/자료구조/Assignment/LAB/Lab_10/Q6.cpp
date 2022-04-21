#include <iostream>
#include "UnsortedType.h"
#include "TreeType.h"

ItemType elems[7] = { 'g', 'k', 'z', 'h', 'b', 'e', 'a' };	// Unsorted List ����
ItemType elems2[7] = { 'g', 'b', 'a', 'e', 'k', 'h', 'z' };	// Tree ����

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
	if (list_length != tree_length) //���̸� ���� ��, ������ �˻��Ѵ�.
		return false;
	else
	{
		ItemType item;
		bool found;
		list.ResetList(); //list�� iterator�� ����� �غ� �Ѵ�
		for (int i = 0; i < list_length; i++) {
			list.GetNextItem(item); // list���� �ϳ��� �������� �����´�
			tree.RetrieveItem(item, found); //Ʈ���� �ش� �������� �ִ��� �˻�. O(logN)�� �ɸ�.

			if (!found)	return false;
		}

		return true;
	}
}

/*
	�������� list���� ������ tree�� ã�� ����� O(logN)�� ���⵵�� ������.
	
		�츮�� ����ϴ� TreeType�� Binary search tree�� ������, ���� ���ĵ� �� tree���� � ���� ã�°���
		���ĵ� list���� ���� Ž���� ����ϴ� ���� �����ϴ�. ��, ���⵵�� ���� Ž���� ���⵵ O(log N)�� ����.

	�������� tree���� ������ list�� ã�� ����� O(N)�� ���⵵�� ������.

		�츮�� ����ϴ� list�� ������ ���� ���� Unsorted Type�̴�. ���ĵ��� �ʴ� list���� Ư�� ���� ã�� ����
		�־��� ���, ��� �ε����� Ž���ؾ� �ϱ⶧���� O(N)�� ���⵵�� ������. �׷��⿡ tree���� ������ �������� list�� ã�°���
		O(N)�� ���⵵�� ���� ���̴�.
*/