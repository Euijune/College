#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char **argv)
{
	// 입력파일이름과 출력파일 이름은 argument를 이용하여 받을수 있도록 변경할 것
	// win OS -> mac OS 
	ifstream input_file(argv[1]);
	ofstream output_file(argv[2]);

	char ch;
	while (!input_file.eof()) //파일의 끝이 아닐때까지 루프를 반복함
	{
		// 공백문자 여부 상관 없이 한 문자(1byte) 만큼 읽음
		input_file.get(ch);
		if (input_file.fail()) exit(100);	// 파일을 읽어오는데 실패할 경우 종료.
		if (input_file.eof()) break; // 마지막문자 두 번 읽어오는것을 방지

		if (ch == '\r') // ch가 LF (‘\r’) 이라면
			continue;
		else
			output_file << ch;
	}
	input_file.close();
	output_file.close();
	cout << "Finish";

	return 0;
}