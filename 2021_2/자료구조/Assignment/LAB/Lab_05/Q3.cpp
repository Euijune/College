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

// queue1 에서 queue2로 원소를 하나 옮긴다 (FIFO를 따른다)
void sendItem(QueType<int>& queue1, QueType<int>& queue2, int& item) {
	queue1.Dequeue(item);
	queue2.Enqueue(item);
}

// Q3 - a
bool Identical(QueType<int>& queue1, QueType<int>& queue2) {
	// reference도 가능하다면, 임시 que를 만들자.
	// value로만 하라고 한다면, 중복 해제 오류를 해결하자.
	bool RETURN = true;
	QueType<int> temp_q1;
	QueType<int> temp_q2;
	int item1 = -1, item2 = -1;

	while (!queue1.IsEmpty())
		sendItem(queue1, temp_q1, item1);

	while (!queue2.IsEmpty())
		sendItem(queue2, temp_q2, item2);

	// 둘 중 하나가 empty상태가 될때까지 원소를 비교한다. (길이가 다른 경우까지 고려함)
	while (!temp_q1.IsEmpty() && !temp_q2.IsEmpty()){
		sendItem(temp_q1, queue1, item1);
		sendItem(temp_q2, queue2, item2);

		if (item1 != item2)	RETURN = false;
	}

	// 원소가 모두 같다고 나온 경우에, 만약 두 queue의 길이가 다르다면 (= 한 쪽은 Empty인데 다른 한쪽은 Empty가 아닌 경우)
	// 서로 다른 queue이다.
	if (RETURN && (temp_q1.IsEmpty() != temp_q2.IsEmpty()))
		RETURN = false;

	// 입력 파라미터 원상태 복구
	if (!temp_q2.IsEmpty()) {	// 임시 q2에 원소가 남아있는 경우
		while (!temp_q2.IsEmpty())
			sendItem(temp_q2, queue2, item2);
	}
	if (!temp_q1.IsEmpty()) {	// 임시 q1에 원소가 남아있는 경우
		while (!temp_q1.IsEmpty())
			sendItem(temp_q1, queue1, item1);
	}
	
	return RETURN;
}