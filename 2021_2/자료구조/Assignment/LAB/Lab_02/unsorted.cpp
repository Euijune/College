// Implementation file for Unsorted.h
#include <iostream>
#include "unsorted.h"
UnsortedType::UnsortedType()
{
  length = 0;
}
bool UnsortedType::IsFull() const
{
  return (length == MAX_ITEMS);
}

int UnsortedType::LengthIs() const
{
  return length;
}
void UnsortedType::RetrieveItem(ItemType& item, bool& found) 
// Pre:  Key member(s) of item is initialized. 
// Post: If found, item's key matches an element's key in the 
//       list and a copy of that element has been stored in item; 
//       otherwise, item is unchanged. 
{
  bool moreToSearch;
  int location = 0;
  found = false;

  moreToSearch = (location < length);

  while (moreToSearch && !found) 
  {
    switch (item.ComparedTo(info[location]))
    {
      case LESS    : 
      case GREATER : location++;
                     moreToSearch = (location < length);
                     break;
      case EQUAL   : found = true;
                     item = info[location];
                     break;
    }
  }
}
void UnsortedType::InsertItem(ItemType item)
// Post: item is in the list.
{
  info[length] = item;
  length++;
}
void UnsortedType::DeleteItem(ItemType item)
// Pre:  item's key has been initialized.
//       An element in the list has a key that matches item's.
// Post: No element in the list has a key that matches item's.
{
  int location = 0;

  while (item.ComparedTo(info[location]) != EQUAL)
    location++;

  info[location] = info[length - 1];
  length--;
}
void UnsortedType::DeleteItem_A(ItemType item)
// Pre:  item's key has been initialized.
//       element in the list has a key that matches item's.
//       위 조건을 만족하는 element가 list에 없을 수도 있다.
// Post: No element in the list has a key that matches item's.
//       item이 list에 없다면, 아무 변화없음
{
    int location = 0;

    for (int i = 0; i < length; i++) {
        if (item.ComparedTo(info[location]) == EQUAL) {
            info[location] = info[length - 1];
            length--;
            break;
        }
    }

}
void UnsortedType::DeleteItem_C(ItemType item)
// Pre:  item's key has been initialized.
//       element in the list has a key that matches item's.
//       element는 두 개 이상일 수 있음.
// Post: No element in the list has a key that matches item's.

/*
    이 코드엔 문제가 조금 있다. 예를들어, list info = 1,2,3,4,5,1 일때, 1을 지우려하면 정상적으로 지워지지 않는다.
    이에 대해 개선된 코드를 생각해보자 (실습때)
*/
{
    int indx = 0;
    while (indx < length) {
        if ((item.ComparedTo(info[indx]) == EQUAL)) {
            info[indx] = info[length - 1];  // 만약 info[length-1]의 값도 지워야 하는 값이라면? 
            length--;
        }
        else {
            indx++;
        }
    }
}
void UnsortedType::ResetList()
// Post: currentPos has been initialized.
{
  currentPos = -1;
}

void UnsortedType::GetNextItem(ItemType& item)
// Post: item is current item.
//       Current position has been updated.
{
  currentPos++;
  item = info[currentPos];
}
