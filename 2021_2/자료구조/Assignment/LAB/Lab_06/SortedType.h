// Header file for Unsorted List ADT.  
template <class ItemType>
struct NodeType;

// Assumption:  ItemType is a type for which the operators "<" 
// and "==" are defined-either an appropriate built-in type or
// a class that overloads these operators.

template <class ItemType>
class SortedType
{
public:
  SortedType();     // Class constructor	
  ~SortedType();    // Class destructor

  bool IsFull() const;
  // Determines whether list is full.
  // Post: Function value = (list is full)

  int  LengthIs() const;
  // Determines the number of elements in list.
  // Post: Function value = number of elements in list.

  void MakeEmpty();
  // Initializes list to empty state.
  // Post:  List is empty.

  void RetrieveItem(ItemType& item, bool& found);
  // Retrieves list element whose key matches item's key 
  // (if present).
  // Pre:  Key member of item is initialized.
  // Post: If there is an element someItem whose key matches 
  //       item's key, then found = true and item is a copy 
  //       of someItem; otherwise found = false and item is 
  //       unchanged. 
  //       List is unchanged.
  
  void InsertItem(ItemType item); 
  // Adds item to list.
  // Pre:  List is not full.
  //       item is not in list. 
  // Post: item is in list.

  void DeleteItem(ItemType item);
  // Deletes the element whose key matches item's key.
  // Pre:  Key member of item is initialized.
  //       One and only one element in list has a key matching
  //       item's key.
  // Post: No element in list has a key matching item's key.

  void ResetList();
  // Initializes current position for an iteration through the
  // list.
  // Post: Current position is prior to list.

  void GetNextItem(ItemType&);
  // Gets the next element in list.
  // Pre:  Current position is defined.
  //       Element at current position is not last in list.
  // Post: Current position is updated to next position.
  //       item is a copy of element at current position.

  void MergeLists(SortedType<ItemType>& other, SortedType<ItemType>& result);
  
  void DeleteItem_5A(ItemType item);

  void DeleteItem_5B(ItemType item);

private:
  NodeType<ItemType>* listData;
  int length;
  NodeType<ItemType>* currentPos;
};
template<class ItemType>
struct NodeType
{
    ItemType info;
    NodeType* next;
};
template <class ItemType>
SortedType<ItemType>::SortedType()  // Class constructor
{
  length = 0;
  listData = NULL;
}
template<class ItemType>
bool SortedType<ItemType>::IsFull() const
// Returns true if there is no room for another ItemType 
//  on the free store; false otherwise.
{
  NodeType<ItemType>* location;
  try
  {
    location = new NodeType<ItemType>;
    delete location;
    return false;
  }
  catch(std::bad_alloc exception)
  {
    return true;
  }
}
template <class ItemType>
int SortedType<ItemType>::LengthIs() const
// Post: Number of items in the list is returned.
{
  return length;
}
template <class ItemType>
void SortedType<ItemType>::MakeEmpty()
// Post: List is empty; all items have been deallocated.
{
    NodeType<ItemType>* tempPtr;

    while (listData != NULL)
    {
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }
    length = 0;
}
template <class ItemType>
void SortedType<ItemType>::RetrieveItem(ItemType& item, 
     bool& found)
{
  bool moreToSearch;
  NodeType<ItemType>* location;

  location = listData;
  found = false;
  moreToSearch = (location != NULL);

  while (moreToSearch && !found)
  {
    if (location->info < item)
    {
      location = location->next;
      moreToSearch = (location != NULL);
    }
    else if (item == location->info)
    {
      found = true;
      item = location->info;
    }
    else
      moreToSearch = false;
  }
}

template <class ItemType>
void SortedType<ItemType>::InsertItem(ItemType item)
{
  NodeType<ItemType>* newNode;  // pointer to node being inserted
  NodeType<ItemType>* predLoc;  // trailing pointer (후행)
  NodeType<ItemType>* location; // traveling pointer
  bool moreToSearch;

  location = listData;
  predLoc = NULL;
  moreToSearch = (location != NULL);

  // Find insertion point.
  while (moreToSearch)
  {
    if (location->info < item)
    {
      predLoc = location;
      location = location->next;
      moreToSearch = (location != NULL);
    }
    else
      moreToSearch = false;
  }

  // Prepare node for insertion
  newNode = new NodeType<ItemType>;
  newNode->info = item;
  // Insert node into list.
  if (predLoc == NULL)         // Insert as first
  {
    newNode->next = listData;
    listData = newNode;
  }
  else
  {
    // pointer 구조 
    // before : predLoc -> location
    // after : predLoc -> newNode -> location
    newNode->next = location;
    predLoc->next = newNode;
  }
  length++;
}

template <class ItemType>
void SortedType<ItemType>::DeleteItem(ItemType item)
// Pre:  item's key has been initialized.
//       An element in the list has a key that matches item's.
// Post: No element in the list has a key that matches item's.
{
    NodeType<ItemType>* location = listData;
    NodeType<ItemType>* tempLocation;

    // Locate node to be deleted.
    if (item == listData->info)
    {
        tempLocation = location;
        listData = listData->next;		// Delete first node.
    }
    else
    {
        while (!(item==(location->next)->info))
          location = location->next;

        // Delete node at location->next
        tempLocation = location->next;
        location->next = (location->next)->next;
    }
    delete tempLocation;
    length--;
}
template <class ItemType>

void SortedType<ItemType>::ResetList()
// Post: Current position has been initialized.
{
  currentPos = NULL;
}
 
template <class ItemType>
void SortedType<ItemType>::GetNextItem(ItemType& item)
// Post:  Current position has been updated; item is 
//        current item.
{
  if (currentPos == NULL)
    currentPos = listData;
  item = currentPos->info; 
  currentPos = currentPos->next;
} 

template <class ItemType>
SortedType<ItemType>::~SortedType()
// Post: List is empty; all items have been deallocated.
{
    NodeType<ItemType>* tempPtr;

    while (listData != NULL)
    {
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }
}


// Q3 - B
template <class ItemType>
void SortedType<ItemType>::MergeLists(SortedType<ItemType>& other, SortedType<ItemType>& result)
{
    /*1. NodeType의 포인터 변수 2개를 추가하고, 각각 listData와 other list의 listData를 가리키도록 한다.
        Ex) NodeType<ItemType>* ptr1 = listData;
        2. 아이템을 비교 하며 합병을 시작한다.단, 둘 리스트의 길이가 같다는 보장이 없으므로, 길이가 짧은 쪽이 끝났을 경
            우 긴쪽을 그 뒤에 붙이는 예외 처리를 하도록 한다.
            Ex) while (ptr1 != NULL && ptr2 != NULL) 그리고 둘 중 하나가 먼저 끝났을 때에 대한 처리.*/
    NodeType<ItemType>* ptr1 = listData;
    NodeType<ItemType>* ptr2 = other.listData;

    while (ptr1 != NULL && ptr2 != NULL) {
        result.InsertItem(ptr1->info);
        ptr1 = ptr1->next;
        result.InsertItem(ptr2->info);
        ptr2 = ptr2->next;
    }

    // 두 list의 길이가 같은 경우 아래코드 실행 x
    if (ptr1 == NULL && ptr2 != NULL) {
        while (ptr2 != NULL) {
            result.InsertItem(ptr2->info);
            ptr2 = ptr2->next;
        }
    }
    else if (ptr1 != NULL && ptr2 == NULL) {
        while (ptr1 != NULL) {
            result.InsertItem(ptr1->info);
            ptr1 = ptr1->next;
        }
    }
}

// Q5 - A
template <class ItemType>
void SortedType<ItemType>::DeleteItem_5A(ItemType item) {
    NodeType<ItemType>* predLoc;  // trailing pointer (후행)
    NodeType<ItemType>* location; // traveling pointer
    bool moreToSearch;

    location = listData;
    predLoc = NULL;
    moreToSearch = location != NULL;

    // Find item.
    if (listData->info == item) {
        listData = listData->next;  // Delete first node
        length--;
    }
    else {
        while (moreToSearch) {
            if (location->info != item) {
                predLoc = location;
                location = location->next;
                moreToSearch = location != NULL;
            }
            else {
                predLoc->next = location->next;
                length--;
                moreToSearch = false;
            }
        }
    }
}

// Q5 - B
template <class ItemType>
void SortedType<ItemType>::DeleteItem_5B(ItemType item) {
    NodeType<ItemType>* predLoc;  // trailing pointer (후행)
    NodeType<ItemType>* location; // traveling pointer
    bool moreToSearch;

    location = listData;
    predLoc = NULL;
    moreToSearch = (location->info <= item);

    // Find item.
    while (moreToSearch) {
        if (location->info != item) {
            predLoc = location;
            location = location->next;
            moreToSearch = (location != NULL);
        }
        else {
            if (predLoc == NULL) {
                listData = listData->next;  // Delete first node
                location = listData;
                moreToSearch = (location != NULL);
            }
            else {
                predLoc->next = location->next;
                location = predLoc;
            }
            length--;
        }
    }
}

// midterm_principle_test
template <class ItemType>
bool    SortedType<ItemType>::RetrieveItem(ItemType& item)
{
    NodeType<ItemType>* location;
    int low = 0;
    int high = length - 1;

    while (low <= high) {
        int     mid = (low + high) / 2;
        location = listData;
        for (int i = 0; i < mid; i++)
            location = location->next; // a
        if (location->info == item)
            return true;
        if (location->info > item)
            high = mid - 1; // b
        else
            low = mid + 1; // c
    }
    return false;
}