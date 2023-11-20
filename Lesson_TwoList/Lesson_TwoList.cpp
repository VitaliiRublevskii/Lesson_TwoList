

#include <iostream>
#include "TwoList.h"


int main()
{
    TwoList<int> list1;
    TwoList<int> list2;


    list1.AddToHead(3);
    list1.AddToHead(5);
    list1.AddToHead(9);
    list1.AddToTail(15);
    list1.AddToTail(21);
    list1.AddToTail(35);

    list1.print();
    cout << endl;

    cout << "Element from head  :  " << list1.DeleteFromHead() << endl;
    list1.print();
    cout << endl;
    list1.DeleteFromTail();
    list1.print();
    cout << endl;

    list2.AddToHead(4);
    list2.AddToHead(8);
    list2.AddToHead(10);
    list2.AddToTail(16);
    list2.AddToTail(22);
    list2.AddToTail(38);
    list2.print();

    cout << "list1 + list2" << endl;
    TwoList<int> list3;

    list3 = list1 + list2;
    list3.print();
    cout << endl;

    list1 += 55;
    list1.print();
    cout << endl;

   // list1[2];
   // list1.print();
   // cout << endl;

}
