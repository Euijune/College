/*
	Q5.cpp �ڵ带 © ��,
	QueType.h �� TreeType.h �� typedef char ItemType -> typedef int ItemType�� �ٲ� �������� �ۼ��Ͽ����ϴ�.
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
	int length = list.LengthIs(); //����Ʈ ũ�⸦ ��´�
	int* array = new int[length]; //���� �迭 �Ҵ�
	int item_info;
	int i;
	list.ResetList();
	for (i = 0; i < length; i++)
	{
		list.GetNextItem(item_info);
		array[i] = item_info;
	}
	AddElement(tree, array, 0, length - 1);
	delete[] array; // ���� �迭 ����
}
void AddElement(TreeType& tree, int Array[], int front, int rear)
{
	int mid; //�߰� ���� ����ϴ� ����
	if (front <= rear) { //�Լ��� ��������
		mid = (front + rear) / 2;
		tree.InsertItem(Array[mid]);
		AddElement(tree, Array, front, mid-1);
		AddElement(tree, Array, mid+1, rear);
	}
}