#include <iostream>
#include "UnsortedType.h"

using namespace std;

template <class ItemType>
void MergeLists(UnsortedType<ItemType>& l_a, UnsortedType<ItemType>& l_b, UnsortedType<ItemType>& result);

int main(){
	int elems[5] = { 1,3,5,7,9 };
	int length_res1, length_res2;
	UnsortedType<int> list01, list02, res1, res2;

	for (int elem : elems) {
		list01.InsertItem(elem);
		list02.InsertItem(elem + 1);
	}

	// 서로 다른 길이의 list로 테스트할 때
	//list01.InsertItem(100);

	MergeLists(list01, list02, res1);
	length_res1 = res1.LengthIs();
	list01.MergeLists(list02, res2);
	length_res2 = res2.LengthIs();	

	// print answer for Q3 - C
	for (int i = 0; i < length_res1; i++) {
		int temp;
		res1.GetNextItem(temp);
		cout << temp << " ";
	}
	cout << endl;

	// print answer for Q3 - D
	for (int i = 0; i < length_res2; i++) {
		int temp;
		res2.GetNextItem(temp);
		cout << temp << " ";
	}
	cout << endl;

	return 0;
}

// Q3 - C
template <class ItemType>
void MergeLists(UnsortedType<ItemType>& l_a, UnsortedType<ItemType>& l_b, UnsortedType<ItemType>& result)
{
	int length_l_a, length_l_b;
	length_l_a = l_a.LengthIs();
	length_l_b = l_b.LengthIs();

	ItemType Item;
	for (int i = 0; i < length_l_b; i++) {
		l_b.GetNextItem(Item);
		result.InsertItem(Item);
	}
	l_b.ResetList();

	for (int i = 0; i < length_l_a; i++) {
		l_a.GetNextItem(Item);
		result.InsertItem(Item);
	}
	l_a.ResetList();

	
}