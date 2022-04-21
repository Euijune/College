#pragma once
#include <iostream>     //for debugging

class FullQueue
{};  

class EmptyQueue
{};  


template <class ItemType>
class QueType
{
public: 
    QueType();
    // Class constructor.
    // Because there is a default constructor, the precondition 
    // that the queue has been initialized is omitted.
    QueType(int max);
    // Parameterized class constructor.
    ~QueType();
    // Class destructor.
    void MakeEmpty();
    // Function: Initializes the queue to an empty state.
    // Post: Queue is empty.
    bool IsEmpty() const;
    // Function: Determines whether the queue is empty.
    // Post: Function value = (queue is empty)
    bool IsFull() const;
    // Function: Determines whether the queue is full.
    // Post: Function value = (queue is full)
    void Enqueue(ItemType newItem);
    // Function: Adds newItem to the rear of the queue.
    // Post: If (queue is full) FullQueue exception is thrown
    //       else newItem is at rear of queue.
    void Dequeue(ItemType& item);
    // Function: Removes front item from the queue and returns it in item.
    // Post: If (queue is empty) EmptyQueue exception is thrown
    //       and item is undefined
    //       else front element has been removed from queue and
    //       item is a copy of removed element.
    void ReplaceItem(ItemType oldItem, ItemType newItem);   // Q2 - B
    bool Identical(QueType<ItemType>& queue);  // Q3 - b
    int Length(); // Q4 - b
private:
    int front;
    int rear;
    ItemType* items;
    int maxQue;
};

template <class ItemType>
QueType<ItemType>::QueType(int max)
// Parameterized class constructor
// Post: maxQue, front, and rear have been initialized.
//       The array to hold the queue elements has been dynamically
//       allocated.
{
    maxQue = max + 1;
    front = maxQue - 1;
    rear = maxQue - 1;
    items = new ItemType[maxQue];
}

template <class ItemType>
QueType<ItemType>::QueType()          // Default class constructor
// Post: maxQue, front, and rear have been initialized.
//       The array to hold the queue elements has been dynamically
//       allocated.
{
    maxQue = 501;
    front = maxQue - 1;
    rear = maxQue - 1;
    items = new ItemType[maxQue];
}

template <class ItemType>
QueType<ItemType>::~QueType()         // Class destructor
{
    delete[] items;
}

template <class ItemType>
void QueType<ItemType>::MakeEmpty()
// Post: front and rear have been reset to the empty state.
{
    front = maxQue - 1;
    rear = maxQue - 1;
}

template <class ItemType>
bool QueType<ItemType>::IsEmpty() const
// Returns true if the queue is empty; false otherwise.
{
    return (rear == front);
}

template <class ItemType>
bool QueType<ItemType>::IsFull() const
// Returns true if the queue is full; false otherwise.
{
    return ((rear + 1) % maxQue == front);
}

template <class ItemType>
void QueType<ItemType>::Enqueue(ItemType newItem)
// Post: If (queue is not full) newItem is at the rear of the queue;
//       otherwise a FullQueue exception is thrown.  
{
    if (IsFull())
        throw FullQueue();
    else
    {
        rear = (rear + 1) % maxQue;
        items[rear] = newItem;
    }
}

template <class ItemType>
void QueType<ItemType>::Dequeue(ItemType& item)
// Post: If (queue is not empty) the front of the queue has been 
//       removed and a copy returned in item; 
//       othersiwe a EmptyQueue exception has been thrown.
{
    if (IsEmpty())
        throw EmptyQueue();
    else
    {
        front = (front + 1) % maxQue;
        item = items[front];
    }
}

// Q2 - B
template <class ItemType>
void QueType<ItemType>::ReplaceItem(ItemType oldItem, ItemType newItem) {
    if (IsEmpty())
        throw EmptyQueue();
    else {
        int i = front;
        while (i++ != rear) {
            if (i > maxQue - 1) i = 0;
            items[i] = (items[i] == oldItem) ? newItem : items[i];
        }

        // rear 와 front를 고려하지 않고 O(N)의 복잡도로 탐색을 할 때
        /* for (int i = 0; i < maxQue; i++) {
            if (items[i] == oldItem) {
                items[i] = newItem;
            }
        }*/
    }
}

// Q3 - b
template <class ItemType>
bool QueType<ItemType>::Identical(QueType<ItemType>& queue) {
    int i1 = front+1, i2 = queue.front+1;
    while (i1 != rear+1 && i2 != queue.rear+1) {
        if (items[i1] != queue.items[i2])    return false;
        // 개선 전 코드
        //i1++;
        //i2++;
        i1 = (i1 + 1) % maxQue;
        i2 = (i2 + 1) % maxQue;
    }

    // 큐의 길이가 다른 경우 예외처리
    if (i1 == rear + 1 && i2 == queue.rear + 1)	return true;
    else                                    return false;
}

// Q4 - b
template <class ItemType>
int QueType<ItemType>::Length() {
    // 개선 전 코드
    /*if (this->IsEmpty())    return 0;
    if (rear > front) {
        return rear - front;
    }*/
    
    if (rear >= front)
        return rear - front;
    else
        return maxQue - (front - rear);
}

