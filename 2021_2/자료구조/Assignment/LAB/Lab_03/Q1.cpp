#include <iostream>
#include "ItemType.h"
#include "sorted.h"

using namespace std;

void MergeList(SortedType list1, SortedType list2, SortedType& result);

int main() {
	SortedType s_list1, s_list2, s_list3;
	ItemType itemList[MAX_ITEMS];

	for (int i = 0; i < MAX_ITEMS; i++) {
		itemList[i].Initialize(10-i);

		if (i < 5) {
			s_list1.InsertItem(itemList[i]);
		}
		else {
			s_list2.InsertItem(itemList[i]);
		}
	}

	// view
	s_list1.PrintContent();
	s_list2.PrintContent();

	// another way to view
	/*ItemType tempItem;
	for (int i = 0; i < s_list1.LengthIs(); i++) {
		s_list1.GetNextItem(tempItem);
		tempItem.Print(cout);
	}*/

	MergeList(s_list1, s_list2, s_list3);

	// view after merge
	s_list3.PrintContent();

	return 0;
}

// 문제 1 - b : 해당 MergeList 알고리즘의 big-O 표기법은 O(N^2)입니다.
void MergeList(SortedType list1, SortedType list2, SortedType& result)
{
	list1.ResetList();
	list2.ResetList();
	result.ResetList(); // 결과도 리스트이므로 빼먹지 말자

	// more readability
	//int length_list1, length_list2;
	int length_list1 = list1.LengthIs();
	int length_list2 = list2.LengthIs();

	for (int i = 0; i < length_list1; i++) {
		ItemType tmp;
		list1.GetNextItem(tmp);
		result.InsertItem(tmp);
	}

	for (int i = 0; i < length_list2; i++) {
		ItemType tmp;
		list2.GetNextItem(tmp);
		result.InsertItem(tmp);
	}
}