#include <iostream>
#include "Student.h"
#include "QuickSort.h"
#include "MergeSort.h"
using namespace std;

int main() {
	Student stu[100];
	stu[0].InitValue(2003200111, (char*)"¿Ãøı¿Á", 3.0);
	stu[1].InitValue(2004200121, (char*)"±«ø¿¡ÿ", 3.2);
	stu[2].InitValue(2005200132, (char*)"±Ë¡¯¿œ", 2.7);
	stu[3].InitValue(2006200142, (char*)"»≤øπ¥‡", 2.9);
	//QuickSort(stu, 0, 3);
	MergeSort(stu, 0, 3);

	Print(cout, stu, 4);

	return 0;
}