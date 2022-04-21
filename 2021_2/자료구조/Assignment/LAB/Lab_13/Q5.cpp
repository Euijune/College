#include <iostream>

#define SIZE 9

template <class ItemType>
void Swap(ItemType& item1, ItemType& item2);

template <class ItemType>
void ReheapDown(ItemType values[], int root, int bottom);

template <class ItemType >
void HeapSort(ItemType values[], int numValues);

int main() {
	int nums[SIZE] = { 25, 17, 36, 2, 3, 100, 1, 19, 7 };
	HeapSort(nums, SIZE);

	return 0;
}

template <class ItemType>
void Swap(ItemType& item1, ItemType& item2)
// Post: Contents of item1 and item2 have been swapped.
{
	ItemType tempItem;

	tempItem = item1;
	item1 = item2;
	item2 = tempItem;
}

template <class ItemType>
void ReheapDown(ItemType values[], int root, int bottom)
// Pre: root is the index of a node that may violate the
// heap order property
// Post: Heap order property is restored between root and 
// bottom
{
	int maxChild;
	int rightChild;
	int leftChild;
	leftChild = root * 2 + 1;
	rightChild = root * 2 + 2;
	if (leftChild <= bottom) // ReheapDown continued
	{
		if (leftChild == bottom)
			maxChild = leftChild;
		else
		{
			if (values[leftChild] <= values[rightChild])
				maxChild = rightChild;
			else
				maxChild = leftChild;
		}
		if (values[root] < values[maxChild])
		{
			Swap(values[root], values[maxChild]);
			ReheapDown(values, maxChild, bottom);
		}
	}
}

template <class ItemType>
void HeapSort(ItemType values[], int numValues)
// Post: Sorts array values[ 0 . . numValues-1 ] into 
// ascending order by key
{
	std::cout << "입력한 배열\n";
	for (int i = 0; i < SIZE; i++)
		std::cout << values[i] << " ";
	std::cout << '\n';

	int index;
	// Convert array values[0..numValues-1] into a heap
	for (index = numValues / 2 - 1; index >= 0; index--)
		ReheapDown(values, index, numValues - 1);
	
	std::cout << "\nHeap으로 바꾼 배열\n";
	for (int i = 0; i < SIZE; i++)
		std::cout << values[i] << " ";
	std::cout << '\n';

	// Sort the array.
	std::cout << "\n정렬과정\n";
	for (index = numValues - 1; index >= 1; index--)
	{
		Swap(values[0], values[index]);
		ReheapDown(values, 0, index - 1);
		
		for (int i = 0; i < SIZE; i++)
			std::cout << values[i] << " ";
		std::cout << '\n';
	}
}