#include <iostream>
using namespace std;

/*
	재귀 버전이 더 비효율적이라고 생각합니다.

	재귀 버전으로 구현할 경우, 가장 작은 경우까지 쪼개서 계산을 하는데, 이 계산방식은 다음과 같습니다.
	8 = (1+1+1) + (1+1+1+1+1)
	즉, 3을 한번 더하는 게 아니라, 1을 3번 더하며 그 과정에서 재귀로 다시 함수까지 호출하므로 
	더 복잡하고 번거롭기에 비효율적이라고생각했습니다.

	또한, 피보나치 수열의 N번째 수 F(N) = F(N-1) + F(N-2)인데,
	F(N-1) = F(N-2) + F(N-3) 으로 나타낼 수 있습니다.
	즉, F(N) = F(N-1) + F(N-2) = F(N-2) + F(N-3) + F(N-2) 인데,
	덧셈식의 첫번째 항인 F(N-2)를 세 번째 항에서도 다시 구해야 하는것이 재귀가 비효율 적이라고 생각하는 두 번째 이유입니다.
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
		// pre2 : N-2번째 수
		// pre1 : N-1번째 수
		// curr : N번째 수
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