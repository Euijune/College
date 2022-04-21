#include <iostream>
#include "QueTypeTemplate.h"
using namespace std;

void sendItem(QueType<int>& queue1, QueType<int>& queue2, int& item);
bool Identical(QueType<int>& queue1, QueType<int>& queue2);

int main() {
	int elems1[11] = { 2,6,7,4,5,6,10,15,3, 1, 1};
	int elems2[9] = { 2,6,7,4,5,6,10,15,3 };
	bool resultA, resultB;
	QueType<int> Q1;
	QueType<int> Q2;

	for (int elem : elems1) {
		Q1.Enqueue(elem);
	}

	for (int elem : elems2) {
		Q2.Enqueue(elem);
	}

	// Answer of Q3 - a
	resultA = Identical(Q1, Q2);
	cout << resultA << endl;

	// Answer of Q3 - b
	resultB = Q1.Identical(Q2);
	cout << resultB << endl;

	// After checking Identical, queue is not empty.
	cout << "view all elem" << endl;
	while (!Q1.IsEmpty()) {
		int temp;
		Q1.Dequeue(temp);
		cout << temp << " ";
	}
	cout << endl;
	while (!Q2.IsEmpty()) {
		int temp;
		Q2.Dequeue(temp);
		cout << temp << " ";
	}
	cout << endl;

	return 0;
}

// queue1 ���� queue2�� ���Ҹ� �ϳ� �ű�� (FIFO�� ������)
void sendItem(QueType<int>& queue1, QueType<int>& queue2, int& item) {
	queue1.Dequeue(item);
	queue2.Enqueue(item);
}

// Q3 - a
bool Identical(QueType<int>& queue1, QueType<int>& queue2) {
	// reference�� �����ϴٸ�, �ӽ� que�� ������.
	// value�θ� �϶�� �Ѵٸ�, �ߺ� ���� ������ �ذ�����.
	bool RETURN = true;
	QueType<int> temp_q1;
	QueType<int> temp_q2;
	int item1 = -1, item2 = -1;

	while (!queue1.IsEmpty())
		sendItem(queue1, temp_q1, item1);

	while (!queue2.IsEmpty())
		sendItem(queue2, temp_q2, item2);

	// �� �� �ϳ��� empty���°� �ɶ����� ���Ҹ� ���Ѵ�. (���̰� �ٸ� ������ �����)
	while (!temp_q1.IsEmpty() && !temp_q2.IsEmpty()){
		sendItem(temp_q1, queue1, item1);
		sendItem(temp_q2, queue2, item2);

		if (item1 != item2)	RETURN = false;
	}

	// ���Ұ� ��� ���ٰ� ���� ��쿡, ���� �� queue�� ���̰� �ٸ��ٸ� (= �� ���� Empty�ε� �ٸ� ������ Empty�� �ƴ� ���)
	// ���� �ٸ� queue�̴�.
	if (RETURN && (temp_q1.IsEmpty() != temp_q2.IsEmpty()))
		RETURN = false;

	// �Է� �Ķ���� ������ ����
	if (!temp_q2.IsEmpty()) {	// �ӽ� q2�� ���Ұ� �����ִ� ���
		while (!temp_q2.IsEmpty())
			sendItem(temp_q2, queue2, item2);
	}
	if (!temp_q1.IsEmpty()) {	// �ӽ� q1�� ���Ұ� �����ִ� ���
		while (!temp_q1.IsEmpty())
			sendItem(temp_q1, queue1, item1);
	}
	
	return RETURN;
}