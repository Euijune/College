// Definition of class PQLLType, which represents the Priority Queue ADT
class FullPQLL {};
class EmptyPQLL {};
#include "SortedType.h"

template<class ItemType>
class PQLLType
{
public:
	PQLLType();
	~PQLLType();
	void MakeEmpty();
	bool IsEmpty() const;
	bool IsFull() const;
	void Enqueue(ItemType newItem);
	void Dequeue(ItemType& item);

private:
	int length;
	SortedType<ItemType> linkedlist;
	//int maxItems;
};

template<class ItemType>
PQLLType<ItemType>::PQLLType()
{
	length = 0;
}

template<class ItemType>
PQLLType<ItemType>::~PQLLType()
{
}

template<class ItemType>
void PQLLType<ItemType>::MakeEmpty()
{
	length = 0;
}

//����Ʈ�� �������� �߰��մϴ�.
template<class ItemType>
void PQLLType<ItemType>::Enqueue(ItemType newItem)
{
	if (linkedlist.IsFull())
		throw FullPQLL();
	else
	{
		length++;
		linkedlist.InsertItem(newItem); // ������ �߰�
	}
}

//����Ʈ�� ���� �տ� �ִ� �������� ��������, �ش� �������� �����մϴ�.
template<class ItemType>
void PQLLType<ItemType>::Dequeue(ItemType& item)
{
	if (length == 0)
		throw EmptyPQLL();
	else {
		linkedlist.ResetList(); // iterator�� ����� �غ�
		linkedlist.GetNextItem(item); //����Ʈ���� �������� ���
		linkedlist.DeleteItem(item); //�ش� ������ ����
		length--;
	}
}

template<class ItemType>
bool PQLLType<ItemType>::IsFull() const
// Post: Returns true if the queue is full; false, otherwise.
{
	return linkedlist.IsFull();
}

template<class ItemType>
bool PQLLType<ItemType>::IsEmpty() const
// Post: Returns true if the queue is empty; false, otherwise.
{
	return length == 0;
}