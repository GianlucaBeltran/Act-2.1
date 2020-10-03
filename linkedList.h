#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include <stddef.h>
#include <iostream>

template <class T>
class Node
{
private:
    T val;
    Node<T> *next;

public:
    ~Node<T>() {};
    Node<T>(T pVal, Node<T> *pNext) 
    {
        val = pVal;
        next = pNext;
    }

    T getVal() {return val;}
    void setVal(T pVal) {val = pVal;}
    Node<T> *getNext() {return next;}
    void setNext(Node<T> *pNext) {next = pNext;}
};

template <class T>
class LinkedList
{
private:
    Node<T> *head;
    //Node<T> *tail;

public:
    ~LinkedList() 
    {
        // TODO;
    }
    LinkedList()
    {
        head = NULL;
    }

    int length()
    {
        int length = 0;
        Node<T> *ptr = head;
        while(ptr != NULL)
        {
            length++;
            ptr = ptr->getNext();
        }
        return length;
    }

    void print()
    {
        if (isEmpty())
            std::cout << "List is empty." << std::endl;
        
        else
        {
        Node<T> *ptr = head;
        while(ptr != NULL)
        {
            std::cout << ptr->getVal() << ", ";
            ptr = ptr->getNext();
        }
        std::cout << std::endl;
        }
    }

    void push(T pVal)
    {
        Node<T> *node = new Node<T> (pVal, head);
        head = node;
    }

    void append(T pVal)
    {
        Node<T> *ptr = head;
        Node<T> *node = new Node<T> (pVal, NULL);
        while(ptr->getNext() != NULL)
        {
            ptr = ptr->getNext();
        }
        ptr->setNext(node);
    }

    int insertItem(T pVal, int index)
    {
        if( index > length())
            return -1;
        if(index < 0)
            return -2;
        if(index == 0)
        {
            push(pVal);
            return 1;
        }

        int i = 0;
        Node<T> *ptr = head;
        Node<T> *pre = NULL;
        
        while(index > i && ptr != NULL)
        {
            pre = ptr;
            ptr = ptr->getNext();
            i++;
        }
        Node<T> *node = new Node<T> (pVal, ptr);
        pre->setNext(node);
        return 1;

    }

    bool isEmpty()
    {
        return head == NULL;
    }

    int deleteItem(int index)
    {
        if (isEmpty())
            return -1;
        if(index >= length())
            return -1;
        if (index < 0)
            return -2;
        if (index == 0)
        {
            Node<T> *temp = head;
            head = head->getNext();
            delete temp;
            return 1;
        }
        int i = 0;
        Node<T> *ptr = head;
        Node<T> *pre = NULL;
        while(ptr->getNext() != NULL && index > i)
        {
            pre = ptr;
            ptr = ptr->getNext();
            i++;
        }
        pre->setNext(ptr->getNext());
        delete ptr;

        return 1;
    }

    T getNth(int index, T &item)
    {
        if (index < 0)
            return -1;
        if (index >= length())
            return -2;

        int i = 0;
        Node<T> *ptr = head;
        while (ptr->getNext() != NULL && index > i)
        {
            ptr = ptr->getNext();
            i++;
        }
        item = ptr->getVal();
        return 1;
    }
    
    int Count(T searchFor) //Counts number of times searchFor appears in linkedlist. Temporal complexity: O(n)
    {
        int count = 0;
        Node<T> *ptr = head;
        while (ptr != NULL)
        {
            if (ptr->getVal() == searchFor)
                count ++;

            ptr = ptr->getNext();
        }

        return count;
    }

    void DeleteList() //Deletes entire linkedlist. Temporal complexity: O(n)
    {
        Node<T> *ptr = head;
        Node<T> *pre = NULL;
        while (ptr != NULL)
        {
            pre = ptr; 
            ptr = ptr->getNext();
            delete pre;
        }
        head = NULL;
    }

    void SortedInsert(Node<T> *newNode) //Inserts given node into sorted linkedlist. Temporal complexity: O(n)
    {
        Node<T> *ptr = head;
        while(ptr->getNext() != NULL)
        {
            if (ptr->getVal() >= newNode->getVal())
            {
                newNode->setNext(ptr->getNext());
                ptr->setNext(newNode);
                return;
            }

            ptr = ptr->getNext();
        }

        ptr->setNext(newNode);
    }

    void RemoveDuplicates() //Removes duplicates from linkedlist. Temporal complexity: O(n)
    {
        Node<T> *ptr = head;
        Node<T> *temp = NULL;
        while(ptr->getNext() != NULL)
        {
            temp = ptr;
            ptr = ptr->getNext();
            if(ptr->getVal() == temp->getVal())
            {
                temp->setNext(ptr->getNext());
                delete ptr;
                ptr = temp;
            }
        }
    }

    void Reverse() //Reverse order of linkedlist. Temporal complexity: O(n)
    {
        Node<T> *ptr = head;
        Node<T> *pre = NULL;
        Node<T> *temp = NULL;
        while(ptr != NULL)
        {
            temp = ptr->getNext();
            ptr->setNext(pre);
            pre = ptr;
            ptr = temp;
        }
        head = pre;
    }

};

#endif