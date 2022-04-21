#include <iostream>
#include <random>
#include "QueType.h"
using namespace std;

ItemType* makeRandomInt(int N) {
	ItemType* randList = new ItemType[N];
	random_device rd;
	mt19937 gen(rd());
	// 0~99���� ������ ���� �յ������ ����
	uniform_int_distribution<ItemType> dis(0, 99);

	for (int i = 0; i < N; i++) {
		randList[i] = dis(gen);
	}

	return randList;
}

int main() {
	ItemType* randList;
	int numberOfRandInt = 10;
	QueType Q;

	randList = makeRandomInt(numberOfRandInt);

	cout << "Ten randint            : ";
	for (int i = 0; i < numberOfRandInt; i++) {
		ItemType elem = randList[i];
		cout << elem << " ";
		Q.Enqueue(elem);
	}
	cout << endl;

	cout << "Ten randint from Queue : ";
	while (!Q.IsEmpty()) {
		ItemType elem;
		Q.Dequeue(elem);
		cout << elem << " ";
	}
	cout << endl;

	delete[] randList;

	return 0;
}