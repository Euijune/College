#include <iostream>
#include <string>
#include "Student.h"
#include "HashTable.h"
using namespace std;

int main() {
	Student stu[100];
	stu[0].InitValue(2003200111, (char*)"�̿���", 3.0);
	stu[1].InitValue(2004200121, (char*)"�ǿ���", 3.2);
	stu[2].InitValue(2005200132, (char*)"������", 2.7);
	stu[3].InitValue(2006200142, (char*)"Ȳ����", 2.9);

	HashTable<Student> ht;
	bool tf = false;

	Student temp;
	temp.InitValue(2020105643, (char*) "������", 4.3);

	ht.RetrieveItem(temp, tf);

	return 0;
}