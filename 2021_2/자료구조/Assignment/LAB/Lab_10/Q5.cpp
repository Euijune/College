/*
	Q5.cpp 코드를 짤 때,
	QueType.h 와 TreeType.h 의 typedef char ItemType -> typedef int ItemType로 바꾼 기준으로 작성하였습니다.
*/

#include <iostream>
#include "SortedType.h"
#include "TreeType.h"

int elems[7] = { 1,2,3,4,5,6,7};
TreeType tree;

void AddElement(TreeType& tree, int Array[], int from, int to);
void MakeTree(TreeType& tree, SortedType<int>& list);

int main() {
	SortedType<int> slist;
	
	for (int elem : elems)
		slist.InsertItem(elem);

	MakeTree(tree, slist);

	return 0;
}

void MakeTree(TreeType& tree, SortedType<int>& list)
{
	int length = list.LengthIs(); //리스트 크기를 얻는다
	int* array = new int[length]; //동적 배열 할당
	int item_info;
	int i;
	list.ResetList();
	for (i = 0; i < length; i++)
	{
		list.GetNextItem(item_info);
		array[i] = item_info;
	}
	AddElement(tree, array, 0, length - 1);
	delete[] array; // 동적 배열 삭제
}
void AddElement(TreeType& tree, int Array[], int front, int rear)
{
	int mid; //중간 값을 기록하는 변수
	if (front <= rear) { //함수의 종료조건
		mid = (front + rear) / 2;
		tree.InsertItem(Array[mid]);
		AddElement(tree, Array, front, mid-1);
		AddElement(tree, Array, mid+1, rear);
	}
}