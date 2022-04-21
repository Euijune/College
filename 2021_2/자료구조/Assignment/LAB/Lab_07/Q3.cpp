#include <iostream>
#include "TextEditor.h"
using namespace std;

/*
	문제 3 - d에 대한 답변

	c의 Big-O는 O(N)입니다.
	c의 복잡도가 O(1) 이 되는 경우는
	top 에서 GoToTop()을 호출하는 경우, trailer에서 GoToTop()을 호출하는 경우,
	bottom에서 GoToBottom()을 호출하는 경우, Header에서 GoToTop()을 호출하는 경우 총 4가지 입니다.

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