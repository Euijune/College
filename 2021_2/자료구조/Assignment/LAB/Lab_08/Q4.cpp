#include <iostream>
#include <iomanip>
using namespace std;

#define MAX_ROWS 10
#define MAX_COLS 10
#define NumPaths_C(row, col, n) NumPaths_B(row-1, col-1, n-1)

int mat[MAX_ROWS][MAX_COLS]; // (1,1) ~ (MAX_ROWS, MAX_COLS)
int NumPaths(int row, int col, int n);
int NumPaths_B(int row, int col, int n);
void viewMat();

int main() {
	memset(mat, -1, MAX_ROWS * MAX_COLS * sizeof(int)); // mat 모든원소 -1로 초기화

	// view mat before NumPath func
	viewMat();

	cout << endl;
	cout << NumPaths(1, 1, 7) << endl;
	cout << NumPaths_C(1, 1, 7) << '\n'<<endl;
	cout << endl;

	// view mat after NumPath func
	viewMat();

	return 0;
}

int NumPaths(int row, int col, int n)
{
	if ((row == n) || (col == n))
		return 1;
	else
		return NumPaths(row + 1, col, n) + NumPaths(row, col + 1, n);
}

int NumPaths_B(int row, int col, int n)
{

	if (mat[row][col] == -1) { // 아직 구해지지 않은 경우
		if ((row == n) || (col == n))
			mat[row][col] = 1;
		else
			mat[row][col] = NumPaths_B(row + 1, col, n) + NumPaths_B(row, col + 1, n);
	}
	return mat[row][col];
}

void viewMat() {
	for (int row = 0; row < MAX_ROWS; row++) {
		for (int col = 0; col < MAX_COLS; col++)
			cout << setw(5) << mat[row][col];
		cout << '\n'<< endl;
	}
}