// For testing Q1 ~ Q4

#include <iostream>
#include "Student.h"
#include "SelectionSort.h"
#include "BubbleSort.h"
#include "InsertionSort.h"
#include "HeapSort.h"

int main() {
	Student stu[100];
	stu[0].InitValue(2003200111, (char*)"¿Ãøı¿Á", 3.0);
	stu[1].InitValue(2004200121, (char*)"±«ø¿¡ÿ", 3.2);
	stu[2].InitValue(2005200132, (char*)"±Ë¡¯¿œ", 2.7);
	stu[3].InitValue(2006200142, (char*)"»≤øπ¥‡", 2.9);

	// Q1
	/*SelectionSort(stu, 4);
	Print(std::cout, stu, 4);*/

	// Q2
	/*BubbleSort(stu, 4);
	Print(std::cout, stu, 4);*/

	// Q3
	/*InsertionSort(stu, 4);
	Print(std::cout, stu, 4);*/

	// Q4 ??
	HeapSort(stu, 4);
	Print(std::cout, stu, 4);

	return 0;
}