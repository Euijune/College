#include <iostream>
#include "UnsortedType.h"
using namespace std;

int main() {
	/*
		Sort의 parameter인 location을 main()에서 줄 수 있는 방법이 없습니다.
		따라서 insertItem 맨 마지막에 sort함수를 추가하여, item 삽입과 동시에 정렬을 하도록 만들었습니다.
	*/

	UnsortedType<int> list;
	list.InsertItem(5);
	list.InsertItem(7);
	list.InsertItem(1);
	list.InsertItem(4);

	int temp;
	for (int i = 0; i < 4; i++) {
		list.GetNextItem(temp);
		cout << temp << " ";
	}

	return 0;
}