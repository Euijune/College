class FullStack
	// Exception class thrown by Push when stack is full.
{};

class EmptyStack
	// Exception class thrown by Pop and Top when stack is emtpy.
{};

#include "DoubleStack_MaxItem.h"
// DoubleStack_MaxItem.h must be provided by the user of this class.
// This file must contains the definition of MAX_ITEMS,
// the maximum number of items on the stack.

class DoubleStack
{
private:
	int top_small; // 1000보다 작거나 같은 스택의 top
	int top_big; // 1000보다 큰 스택의 top
	int items[MAX_ITEMS];
public:
	DoubleStack();
	// Class constructor.
	bool IsFull() const; // stack is full?
	bool IsEmpty() const; // stack is empty?
	void Push(int item); // C에서 구현할 push 연산
	void Pop();
	//Function : if top_small is not -1, Removes top item from the stack_small(its elements <= 1000);
	//			 otherwise, Removes top item from the stack_big(its elements > 1000).
	//Pre : DoubleStack has been initialized
	//Post : If (DoubleStack is empty), EmptyStack exception is thrown;
    //       otherwise, top element has been removed from DoubleStack.
	int Top(); 
	//Function : if top_small is not -1, Returns a copy of top item on the stack_small(its elements <= 1000);
	//			 otherwise, Returns a copy of top item on the stack_big(its elements > 1000).
	//Pre : DoubleStack has been initialized
	//Post : If Doublestack is empty, EmptyStack exception is thrown;
	//       otherwise, top element has been removed from Doublestack.
	void Print();
	//Function : print all elements in the doublestack. However, print elements in the stack_small first.
	//Pre : DoubleStack has been initialized.
	//Post : print all elements and doublestack is Empty.	
};

DoubleStack::DoubleStack() {
	top_small = -1;
	top_big = MAX_ITEMS;
}

bool DoubleStack::IsFull() const{
	return (top_big - top_small == 1);
}

bool DoubleStack::IsEmpty() const {
	return (top_small == -1 && top_big == MAX_ITEMS);
}

void DoubleStack::Push(int item) {
	if (IsFull())
		throw FullStack();

	if (item <= 1000) {
		top_small++;
		items[top_small] = item;
	}
	else {
		top_big--;
		items[top_big] = item;
	}
}

void DoubleStack::Pop() {
	if (IsEmpty())
		throw EmptyStack();

	if (top_small > -1) {
		top_small--;
	}
	else {
		top_big++;
	}
}

int DoubleStack::Top() {
	if (IsEmpty())
		throw EmptyStack();

	if (top_small > -1) {
		return items[top_small];
	}
	else {
		return items[top_big];
	}
}

void DoubleStack::Print() {
	while (!IsEmpty()) {
		std::cout << Top() << " ";
		Pop();
	}
}