#include <string>
#include <fstream>
typedef char ItemType;
struct TreeNode;
#include "QueType.h"
enum OrderType {PRE_ORDER, IN_ORDER, POST_ORDER};

class TreeType
{
public:
  TreeType();                    // constructor
 ~TreeType();                    // destructor
  TreeType(const TreeType& originalTree); 
  void operator=(const TreeType& originalTree);
  // copy constructor
  void MakeEmpty();
  bool IsEmpty() const;
  bool IsFull() const;
  int LengthIs() const; 
  void RetrieveItem(ItemType& item, bool& found);
  void InsertItem(ItemType item);
  void DeleteItem(ItemType item);
  void ResetTree(OrderType order); 
  void GetNextItem (ItemType& item, OrderType order, 
       bool& finished);
  void Print(std::ofstream& outFile) const;
  
  // Q1. Recursive version:
  TreeNode* PtrToSuccessor_recur(TreeNode*& tree);
  // Q1. Nonrecursive version:
  TreeNode* PtrToSuccessor_nonrecur(TreeNode*& tree);
  // Q3
  bool IsBST();
  // Q4
  int LeafCount();
  // Q5
  int SingleParentCount();

private:
  TreeNode* root;
  QueType preQue;
  QueType inQue;
  QueType postQue;
};

