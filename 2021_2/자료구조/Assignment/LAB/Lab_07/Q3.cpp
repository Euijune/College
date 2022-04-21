#include <iostream>
#include "TextEditor.h"
using namespace std;

/*
	���� 3 - d�� ���� �亯

	c�� Big-O�� O(N)�Դϴ�.
	c�� ���⵵�� O(1) �� �Ǵ� ����
	top ���� GoToTop()�� ȣ���ϴ� ���, trailer���� GoToTop()�� ȣ���ϴ� ���,
	bottom���� GoToBottom()�� ȣ���ϴ� ���, Header���� GoToTop()�� ȣ���ϴ� ��� �� 4���� �Դϴ�.

*/


int main() {
	TextEditor edit;
	char text[80] = "Hello";
	char text2[80] = "Nice to Meet you";

	edit.PrintText();	// header

	edit.GoToTop();	// header -> trailer
	edit.PrintText();

	edit.GoToTop();	// trailer -> trailer
	edit.PrintText();

	edit.GoToBottom();	// trailer -> header
	edit.PrintText();

	edit.GoToBottom();	// header -> header
	edit.PrintText();

	edit.InsertLine(text);
	edit.PrintText();

	edit.InsertLine(text2);
	edit.PrintText();

	edit.GoToTop();	// bottom -> top
	edit.GoToTop();	// top -> top
	edit.PrintText();

	edit.GoToBottom();	// top -> bottom
	edit.GoToBottom();	// bottom -> bottom
	edit.PrintText();

	return 0;
}