#include <iostream>
#include "Student.h"
#include "HashTable.h"
using namespace std;

int main() {
	HashTable<Student> ht;
	bool tf = false;

	Student temp;
	temp.InitValue(2020105643, (char*)"¿Ã¿«¡ÿ", 4.3);

	ht.RetrieveItem(temp, tf);

	return 0;
}