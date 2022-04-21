#include <iostream>
#include "ItemType.h"
#include "unsorted.h"
using namespace std;
const int num = 5;

void getItemAll(UnsortedType& lst);

int main() {
    UnsortedType lst;
    lst.ResetList();
    ItemType itm[num];

    //test for DeleteItem_A
    //int val = 0;
    //for (auto& elem : itm) {    // itm[i].Print(cout) = i
    //    elem.Initialize(val);
    //    val++;
    //}

    //for (int i = 0; i < num; i++) {
    //    lst.InsertItem(itm[i]);
    //}

    //getItemAll(lst);    // 0 1 2 3 4 

    //ItemType temp;
    //temp.Initialize(9);
    //lst.DeleteItem_A(temp);

    //getItemAll(lst);  // 4 1 2 3

    // test for DeleteItem_C
    itm[0].Initialize(3);
    itm[1].Initialize(1);
    itm[2].Initialize(4);
    itm[3].Initialize(3);
    itm[4].Initialize(2);

    for (int i = 0; i < num; i++) {
        lst.InsertItem(itm[i]);
    }

    getItemAll(lst);    // 3 1 4 3 2
    lst.DeleteItem_C(itm[0]);
    getItemAll(lst);    // 2 1 4

    return 0;
}

void getItemAll(UnsortedType& lst) {
    int lst_size = lst.LengthIs();
    for (int i = 0; i < lst_size; i++) {
        ItemType tmp;
        lst.GetNextItem(tmp);
        tmp.Print(cout); cout << " ";
    }
    cout << endl;
    lst.ResetList();
}