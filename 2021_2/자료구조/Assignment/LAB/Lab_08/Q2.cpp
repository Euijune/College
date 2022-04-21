#include <iostream>
using namespace std;

/*
	��� ������ �� ��ȿ�����̶�� �����մϴ�.

	��� �������� ������ ���, ���� ���� ������ �ɰ��� ����� �ϴµ�, �� ������� ������ �����ϴ�.
	8 = (1+1+1) + (1+1+1+1+1)
	��, 3�� �ѹ� ���ϴ� �� �ƴ϶�, 1�� 3�� ���ϸ� �� �������� ��ͷ� �ٽ� �Լ����� ȣ���ϹǷ� 
	�� �����ϰ� ���ŷӱ⿡ ��ȿ�����̶������߽��ϴ�.

	����, �Ǻ���ġ ������ N��° �� F(N) = F(N-1) + F(N-2)�ε�,
	F(N-1) = F(N-2) + F(N-3) ���� ��Ÿ�� �� �ֽ��ϴ�.
	��, F(N) = F(N-1) + F(N-2) = F(N-2) + F(N-3) + F(N-2) �ε�,
	�������� ù��° ���� F(N-2)�� �� ��° �׿����� �ٽ� ���ؾ� �ϴ°��� ��Ͱ� ��ȿ�� ���̶�� �����ϴ� �� ��° �����Դϴ�.
*/

int Fibonacci_recursive(int n);
int Fibonacci_non_recursive(int n);

int main() {
	cout << Fibonacci_recursive(11) << endl;
	cout << Fibonacci_non_recursive(11) << endl;

	return 0;
}

int Fibonacci_recursive(int n) {
	if (n <= 1)
		return n;
	else
		return Fibonacci_recursive(n - 1) + Fibonacci_recursive(n - 2);
}

int Fibonacci_non_recursive(int n) {
	if (n <= 1)
		return n;
	else {
		// pre2 : N-2��° ��
		// pre1 : N-1��° ��
		// curr : N��° ��
		int pre2 = 0;
		int pre1 = 1;
		int curr = 1;

		for (int i = 0; i < n-1; i++) {
			curr = pre2 + pre1;
			pre2 = pre1;
			pre1 = curr;
		}

		return curr;
	}
}