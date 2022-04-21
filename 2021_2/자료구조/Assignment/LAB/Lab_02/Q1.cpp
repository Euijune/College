#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char **argv)
{
	// �Է������̸��� ������� �̸��� argument�� �̿��Ͽ� ������ �ֵ��� ������ ��
	// win OS -> mac OS 
	ifstream input_file(argv[1]);
	ofstream output_file(argv[2]);

	char ch;
	while (!input_file.eof()) //������ ���� �ƴҶ����� ������ �ݺ���
	{
		// ���鹮�� ���� ��� ���� �� ����(1byte) ��ŭ ����
		input_file.get(ch);
		if (input_file.fail()) exit(100);	// ������ �о���µ� ������ ��� ����.
		if (input_file.eof()) break; // ���������� �� �� �о���°��� ����

		if (ch == '\r') // ch�� LF (��\r��) �̶��
			continue;
		else
			output_file << ch;
	}
	input_file.close();
	output_file.close();
	cout << "Finish";

	return 0;
}