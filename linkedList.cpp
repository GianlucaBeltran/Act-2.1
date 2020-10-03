#include "linkedList.h"

using namespace std;

int main()
{
    //Create linkedlist
    LinkedList<int> list;
    //Create Nodes for testing
    Node<int> newNode(3, NULL);
    Node<int> newNode1(1, NULL);
    Node<int> newNode2(0, NULL);
    Node<int> newNode3(5, NULL);
    //Fill list with ordered vallues
    list.push(0);
    for(int i = 1; i < 5; i++)
        list.append(i);
    
    //Print first version of linkedlist
    list.print();

    //Use sorted insert to insert Nodes into linkedlist
    list.SortedInsert(&newNode);
    list.SortedInsert(&newNode1);
    list.SortedInsert(&newNode2);
    list.SortedInsert(&newNode3);
    //Print second version of linkedlist
    list.print();
    //Remove duplicates from linkedlist and print third version
    list.RemoveDuplicates();
    list.print();

    //Reverse linkedlist and print fourth version
    list.Reverse();
    list.print();

    //Delete linkedlist and print fifth version
    list.DeleteList();
    list.print();

    return 0;
}

