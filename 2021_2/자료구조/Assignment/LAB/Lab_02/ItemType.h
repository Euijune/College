// The following declarations and definitions go into file 
// ItemType.h. 
#pragma once
#include <fstream>

const int MAX_ITEMS = 10;
enum RelationType  {LESS, GREATER, EQUAL};

class ItemType 
{ 
public:
  ItemType();
  RelationType ComparedTo(ItemType) const;
  void Print(std::ostream&) const;
  void Initialize(int number);
  int GetValue();

private:
  int value;
};
 
