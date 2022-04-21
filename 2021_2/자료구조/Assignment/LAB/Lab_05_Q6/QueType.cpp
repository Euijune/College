#include "QueType.h"
// #include <iostream>  // for debugging

QueType::QueType(int max)
// Parameterized class constructor
// Post: maxQue, front, and rear have been initialized.
//       The array to hold the queue elements has been dynamically
//       allocated.
{
  maxQue = max + 1;
  front = maxQue - 1;
  rear = maxQue - 1;
  items = new ItemType[maxQue];
  minimum_pos = -1;
}
QueType::QueType()          // Default class constructor
// Post: maxQue, front, and rear have been initialized.
//       The array to hold the queue elements has been dynamically
//       allocated.
{
  maxQue = 501;
  front = maxQue - 1;
  rear = maxQue - 1;
  items = new ItemType[maxQue];
  minimum_pos = -1;
}
QueType::~QueType()         // Class destructor
{
  delete [] items;
}

void QueType::MakeEmpty()
// Post: front and rear have been reset to the empty state.
{
  front = maxQue - 1;
  rear = maxQue - 1;
  minimum_pos = -1;
}

bool QueType::IsEmpty() const
// Returns true if the queue is empty; false otherwise.
// -1   -1  -1  -1  -1  -1
// front                rear 
// 위와 같은 경우도 Empty로 간주한다.
{
    bool findPositive = false;

    if (front < rear) {
        for (int i = front + 1; i <= rear; i++) {
            if (items[i] != -1) {
                findPositive = true;
                break;
            }
        }
    }
    else {
        for (int i = front + 1; i < maxQue; i++) {
            if (items[i] != -1) {
                findPositive = true;
                break;
            }
        }
        for (int i = 0; i <= rear; i++) {
            if (items[i] != -1) {
                findPositive = true;
                break;
            }
        }
    }
    
    if (findPositive)   return (rear == front);
    else                return true;
    //return rear == front;
}

bool QueType::IsFull() const
// Returns true if the queue is full; false otherwise.
{
  return ((rear + 1) % maxQue == front);
}

void QueType::Enqueue(ItemType newItem)
// Post: If (queue is not full) newItem is at the rear of the queue;
//       otherwise a FullQueue exception is thrown.  
{
  if (IsFull())
    throw FullQueue();
  else
  {
      // searching item of which value is -1
      bool findNeg = false;

      if (front < rear) {
          for (int i = front + 1; i <= rear; i++) {
              if (items[i] == -1) {
                  items[i] = newItem;
                  findNeg = true;
              }
          }
      }
      else {
          for (int i = front + 1; i < maxQue; i++) {
              if (items[i] == -1) {
                  items[i] = newItem;
                  findNeg = true;
              }
          }
          for (int i = 0; i <= rear; i++) {
              if (items[i] == -1) {
                  items[i] = newItem;
                  findNeg = true;
              }
          }
      }
      // Case : Queue doesn't have item of which value is -1
      if (!findNeg) {
          rear = (rear + 1) % maxQue;
          items[rear] = newItem;
      }

      // initialize minimun_pos
      if (minimum_pos == -1) {  // empty queue에 처음 원소를 넣을때
          minimum_pos++;
      }
      else {
          if (front < rear) {
              for (int i = front + 1; i <= rear; i++) {
                  if (items[i] == -1)   continue;
                  minimum_pos = (items[i] < items[minimum_pos]) ? i : minimum_pos;
              }
          }
          else {
              for (int i = front + 1; i < maxQue; i++) {
                  if (items[i] == -1)   continue;
                  minimum_pos = (items[i] < items[minimum_pos]) ? i : minimum_pos;
              }
              for (int i = 0; i <= rear; i++) {
                  if (items[i] == -1)   continue;
                  minimum_pos = (items[i] < items[minimum_pos]) ? i : minimum_pos;
              }
          }
      }
      //Debugging
      //std::cout << "Enqueue:: minimun_pos = " << minimum_pos << ", front = " << front << ", rear = " << rear << std::endl;
  }
}

void QueType::Dequeue(ItemType& item)
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

void QueType::MinDequeue(ItemType& item)
// Post: If (queue is not empty) the front of the queue has been 
//       removed and a copy returned in item; 
//       othersiwe a EmptyQueue exception has been thrown.
{
    if(IsEmpty())
        throw EmptyQueue();
    else
    {
        item = items[minimum_pos];
        items[minimum_pos] = -1;
        
        bool findMinimum_pos = false;
        
        //Debugging
        //std::cout << "Dequeue:: minimun_pos = " << minimum_pos << ", front = " << front << ", rear = " << rear << std::endl;

        // initialize minimun_pos
        if (front < rear) {
            for (int i = front + 1; i <= rear; i++) {
                if (items[i] == -1)   continue;
                if (findMinimum_pos) {
                    minimum_pos = (items[i] < items[minimum_pos]) ? i : minimum_pos;
                }
                else {
                    minimum_pos = i;
                    findMinimum_pos = true;
                }
                
            }
        }
        else {
            for (int i = front + 1; i < maxQue; i++) {
                if (items[i] == -1)   continue;
                if (findMinimum_pos) {
                    minimum_pos = (items[i] < items[minimum_pos]) ? i : minimum_pos;
                }
                else {
                    minimum_pos = i;
                    findMinimum_pos = true;
                }
            }
            for (int i = 0; i <= rear; i++) {
                if (items[i] == -1)   continue;
                if (findMinimum_pos) {
                    minimum_pos = (items[i] < items[minimum_pos]) ? i : minimum_pos;
                }
                else {
                    minimum_pos = i;
                    findMinimum_pos = true;
                }
            }
        }
    }
}

int QueType::getMinimum_pos() {
    return minimum_pos;
}