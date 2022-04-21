class FullStack
    // Exception class thrown by Push when stack is full.
{};

class EmptyStack
    // Exception class thrown by Pop and Top when stack is emtpy.
{};

#include "PQType.h"

template<class ItemType>
class StackPQType
{
public:

    StackPQType();
    // Class constructor.
    bool IsFull() const;
    // Function: Determines whether the stack is full.
    // Pre:  Stack has been initialized.
    // Post: Function value = (stack is full)
    bool IsEmpty() const;
    // Function: Determines whether the stack is empty.
    // Pre:  Stack has been initialized.
    // Post: Function value = (stack is empty)
    void Push(ItemType item);
    // Function: Adds newItem to the top of the stack.
    // Pre:  Stack has been initialized.
    // Post: If (stack is full), FullStack exception is thrown;
    //     otherwise, newItem is at the top of the stack.
    void Pop();
    // Function: Removes top item from the stack.
    // Pre:  Stack has been initialized.
    // Post: If (stack is empty), EmptyStack exception is thrown;
    //     otherwise, top element has been removed from stack.


private:
    int top;
    PQType<ItemType> items;
};

template <class ItemType>
StackPQType<ItemType>::StackPQType()
    :items{ 50 }
{
    top = -1;
}

template <class ItemType>
bool StackPQType<ItemType>::IsEmpty() const
{
    return (top == -1);
}

template <class ItemType>
bool StackPQType<ItemType>::IsFull() const
{
    return items.IsFull();
}

template <class ItemType>
void StackPQType<ItemType>::Push(ItemType newItem)
{
    if (IsFull())
        throw FullStack();
    top++;
    items.Enqueue(newItem);
}

template <class ItemType>
void StackPQType<ItemType>::Pop()
{
    if (IsEmpty())
        throw EmptyStack();
    top--;
    ItemType temp;
    items.Dequeue(temp);
}
