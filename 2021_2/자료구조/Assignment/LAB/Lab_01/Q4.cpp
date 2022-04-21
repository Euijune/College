#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int MAX_ROWS  = 50;

class SquareMatrix {
/*
* SquareMatrix ADT specification

����
	public :
		void MakeEmpty(int);	// (�Է��� int������ ũ��) - 1 �� ũ�⸦ ����, �����Ұ� 0���� �ʱ�ȭ�� ���簢 ����� �޸𸮿� �Ҵ�
		void StoreValue(int, int, int);	// Ư�� ��ġ�� ���ҿ� ���� ����
		void Add(SquareMatrix&);	// �� ����� ����
		void Subtract(SquareMatrix&);	// �� ����� ����
		void Copy(SquareMatrix&);	// �� ����� �ٸ���ķ� �����Ѵ�.
		int GetItem(int, int);	// private�� ��ġ�ϴ� matrix�� �� ���ҿ� �����ϴ� �Լ�
		void PrintMatrix();	// matrix ��������� ��� ���Ҹ� ����Ѵ�.
		
	private :
		int matrix[50][50];	// �ִ� 50 X 50 ũ������� ����� �����ϴ� ���� 
		int row;	// �ʱ�ȭ�� ����� �� ũ�� (MakeEmpty�� ���� �ڵ����� ����)
		int col;	// �ʱ�ȭ�� ����� �� ũ�� (MakeEmpty�� ���� �ڵ����� ����)
����

	MakeEmpty(n)
		��� : matrix�� n �� �� ���θ� 0���� �ʱ�ȭ�ϸ�, matrix�� ��� �� ũ�⸦ n���� �����Ѵ�.
		���� : n�� �ִ� ũ��� 50
		��� : n���� �� ���� 0���� �ʱ�ȭ, ������� row�� col�� ���� n���� ����.

	StoreValue(i, j, value)
		��� : value�� matrix�� i��° ��, j��° �� ( = matrix[i][j] ) �� ��ġ�� �����Ѵ�.
		���� : 0 <= i <= 50, 0 <= j <= 50, value�� int�ڷ���
		��� : matrix[i][j] = value

	Add(matrix_other)
		��� : �� ���(matrix, matrix_other)�� ���������� �����Ѵ�.
		���� : matrix�� SquareMatrix�� ��������̰�, matrix_other�� �ٸ� SquareMatrix ��ü�� ��������̴�.
			   �� ����� �ʱ�ȭ �Ǿ�������, ���� ������ ���� ������ ���ƾ� �Ѵ�.
		��� : �� ����� ������ �����Ͽ� �� ����� matrix�� �����Ѵ�.

	Subtract(matrix_other)
		��� : �� ���(matrix, matrix_other)�� ��������(matrix - matrix_other)�� �����Ѵ�. 
		���� : matrix�� SquareMatrix�� ��������̰�, matrix_other�� �ٸ� SquareMatrix ��ü�� ��������̴�.
			   �� ����� �ʱ�ȭ �Ǿ�������, ���� ������ ���� ������ ���ƾ� �Ѵ�.
		��� : �� ����� ������ �����Ͽ� �� ����� matrix�� �����Ѵ�.

	Copy(matrix_other)
		��� : �� ����� �ٸ� ��ķ� �����Ѵ�.
		���� : matrix�� SquareMatrix�� ��������̰�, matrix_other�� �ٸ� SquareMatrix ��ü�� ��������̴�.
			   �� ����� �ʱ�ȭ �Ǿ�������, ���� ������ ���� ������ ���ƾ� �Ѵ�.
		��� : ������ ����� �� ���ҵ�� ������ ���� ���� ���ο� ����� matrix_other ��������� �����Ѵ�.

	GetItem(i, j)
		��� : matrix�� i�� j���� ���Ҹ� �����´�.
		���� : matrix�� �ʱ�ȭ�Ǿ��־�� �ϸ�, 0 <= i <= row, 0 <= j <= col
		��� : int���� matrix i�� j�� ���Ұ��� ��ȯ�Ѵ�.

	PrintMatrix()
		��� : matrix�� ��� ���Ҹ� ����Ѵ�
		���� : matrix�� �ʱ�ȭ�Ǿ��־�� �Ѵ�.
		��� : ���â�� matrix�� ��� ���Ҹ� ��/���� �����Ͽ� ����Ѵ�.

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