#include <iostream>
#include "UnsortedType.h"
using namespace std;

int main() {
	/*
		Sort�� parameter�� location�� main()���� �� �� �ִ� ����� �����ϴ�.
		���� insertItem �� �������� sort�Լ��� �߰��Ͽ�, item ���԰� ���ÿ� ������ �ϵ��� ��������ϴ�.
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