#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int MAX_ROWS  = 50;

class SquareMatrix {
/*
* SquareMatrix ADT specification

구조
	public :
		void MakeEmpty(int);	// (입력한 int정수의 크기) - 1 의 크기를 갖는, 모든원소가 0으로 초기화된 정사각 행렬을 메모리에 할당
		void StoreValue(int, int, int);	// 특정 위치의 원소에 값을 대입
		void Add(SquareMatrix&);	// 두 행렬의 덧셈
		void Subtract(SquareMatrix&);	// 두 행렬의 뺄셈
		void Copy(SquareMatrix&);	// 한 행렬을 다른행렬로 복사한다.
		int GetItem(int, int);	// private에 위치하는 matrix의 각 원소에 접근하는 함수
		void PrintMatrix();	// matrix 멤버변수의 모든 원소를 출력한다.
		
	private :
		int matrix[50][50];	// 최대 50 X 50 크기까지의 행렬을 저장하는 변수 
		int row;	// 초기화된 행렬의 행 크기 (MakeEmpty를 통해 자동으로 지정)
		int col;	// 초기화된 행렬의 열 크기 (MakeEmpty를 통해 자동으로 지정)
연산

	MakeEmpty(n)
		기능 : matrix의 n 행 열 내부를 0으로 초기화하며, matrix의 행과 열 크기를 n으로 지정한다.
		조건 : n의 최대 크기는 50
		결과 : n안의 행 열은 0으로 초기화, 멤버변수 row와 col의 값을 n으로 지정.

	StoreValue(i, j, value)
		기능 : value를 matrix의 i번째 행, j번째 열 ( = matrix[i][j] ) 의 위치에 저장한다.
		조건 : 0 <= i <= 50, 0 <= j <= 50, value는 int자료형
		결과 : matrix[i][j] = value

	Add(matrix_other)
		기능 : 두 행렬(matrix, matrix_other)의 덧셈연산을 수행한다.
		조건 : matrix는 SquareMatrix의 멤버변수이고, matrix_other는 다른 SquareMatrix 객체의 멤버변수이다.
			   두 행렬은 초기화 되어있으며, 행의 개수와 열의 개수가 같아야 한다.
		결과 : 두 행렬의 덧셈을 수행하여 그 결과를 matrix에 저장한다.

	Subtract(matrix_other)
		기능 : 두 행렬(matrix, matrix_other)의 뺄셈연산(matrix - matrix_other)을 수행한다. 
		조건 : matrix는 SquareMatrix의 멤버변수이고, matrix_other는 다른 SquareMatrix 객체의 멤버변수이다.
			   두 행렬은 초기화 되어있으며, 행의 개수와 열의 개수가 같아야 한다.
		결과 : 두 행렬의 뺄셈을 수행하여 그 결과를 matrix에 저장한다.

	Copy(matrix_other)
		기능 : 한 행렬을 다른 행렬로 복사한다.
		조건 : matrix는 SquareMatrix의 멤버변수이고, matrix_other는 다른 SquareMatrix 객체의 멤버변수이다.
			   두 행렬은 초기화 되어있으며, 행의 개수와 열의 개수가 같아야 한다.
		결과 : 복사할 행렬의 각 원소들과 동일한 값을 가진 새로운 행렬을 matrix_other 멤버변수에 저장한다.

	GetItem(i, j)
		기능 : matrix의 i행 j열의 원소를 가져온다.
		조건 : matrix는 초기화되어있어야 하며, 0 <= i <= row, 0 <= j <= col
		결과 : int형의 matrix i행 j열 원소값을 반환한다.

	PrintMatrix()
		기능 : matrix의 모든 원소를 출력한다
		조건 : matrix는 초기화되어있어야 한다.
		결과 : 출력창에 matrix의 모든 원소를 행/열을 구분하여 출력한다.

*/
private:
	int matrix[50][50];
	int row;
	int col;
public:
	void MakeEmpty(int);
	void StoreValue(int, int, int);
	void Add(SquareMatrix&);
	void Subtract(SquareMatrix&);
	void Copy(SquareMatrix&);
	int GetItem(int, int);
	void PrintMatrix();
};

void SquareMatrix::MakeEmpty(int n)
{
	int i, j = 0;
	row = n;
	col = n;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			matrix[i][j] = 0;
}

void SquareMatrix::StoreValue(int i, int j, int value)
{
	matrix[i][j] = value;
}

void SquareMatrix::Add(SquareMatrix& matrix_other)
{
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			matrix[i][j] += matrix_other.GetItem(i, j);
		}
	}
}

void SquareMatrix::Subtract(SquareMatrix& matrix_other)
{
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			matrix[i][j] -= matrix_other.GetItem(i, j);
		}
	}
}
void SquareMatrix::Copy(SquareMatrix& matrix_other)
{
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			matrix_other.StoreValue(i, j, matrix[i][j]);
		}
	}
}

int SquareMatrix::GetItem(int i, int j)
{
	int elem = matrix[i][j];
	return elem;
}

void SquareMatrix::PrintMatrix()
{
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout  << matrix[i][j]<< " ";
		}
		cout << endl;
	}
}