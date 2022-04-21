#include <iostream>

#define SIZE 9

template <class ItemType >
void GetHeightSum(ItemType values[], int numValues);
template <class ItemType >
int GetHeight(ItemType values[], int start, int numValues);

int main() {
	int values[SIZE] = { 25, 17, 36, 2, 6, 100, 1, 19, 7};
	GetHeightSum(values, SIZE);

	return 0;
}

template <class ItemType >
void GetHeightSum(ItemType values[], int numValues)
{
	int index, sum = 0;
	// non-leaf 노드에 대해 그 노드를 루트로 하는 subtree의 height 계산
	for (index = 0; index < numValues; index++) {
		int temp = GetHeight(values, index, numValues - 1);
		sum += temp;
		std::cout << "test::" << values[index] << ", "<<temp << std::endl;
	}
	std::cout << "sum of heights = " << sum << std::endl;
}

template <class ItemType >
int GetHeight(ItemType values[], int start, int numValues)
{
	if (start >= numValues/2 ) return 0; // start가 leaf이거나 tree 밖에 있는 경우
	int l_height = GetHeight(values, start * 2 + 1, numValues); // left subtree의 height
	int r_height = GetHeight(values, start * 2 + 2, numValues); // right subtree의 height
	return l_height > r_height ? l_height + 1 : r_height + 1; // “subtree height 중 큰 값 + 1” 을 리턴
}