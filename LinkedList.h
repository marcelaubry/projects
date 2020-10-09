//  Marcel Aubry
//  U02577685
//  LinkedList.h
//
//  Copyright Â© Tali Moreshet. All rights reserved.
//

#ifndef LinkedList_h
#define LinkedList_h

#include <iostream>

using namespace std;

template <class T = int>
class Node {
public:
    Node();                                         // default constructor
    Node(const T& data, Node<T>* next = nullptr);   // donstructor
    T data;                                         // node data
    Node<T>* next;                                  // node next pointer
};

template <class T = int>
class LinkedList {
public:
    LinkedList();                                   // constructor
    ~LinkedList();                                  // destructor
    T deleteFromHead();                             // removes and returns content of head
    T deleteFromTail();                              // removes and returns content of tail
    void deleteNode(T data);                         // removes node with specified data
    void InsertToHead(T data);                      // insert node with data at the head
    void InsertToTail(T data);                      // insert node with data at the tail
    int getSize();                                  // returns size of linked list
    void print();                                   // prints linked list
private:
    Node<T>* head;                                  // head of linked list
};


/******* From here down is the content of the LinkedList.cpp file: ***********************/

 /* Implementation of Node */

 // default constructor
 template<class T>
 Node<T>::Node()
 {
 }
 
 // constructor
 template<class T>
 Node<T>::Node(const T& data, Node<T>* next)
 {
     this->data = data;
     this->next = next;
 }
 
 /* Implementation of linked list */

 // constructor
 template <class T>
 LinkedList<T>::LinkedList()
 {
     head = nullptr;
 }

 // destructor
 template <class T>
 LinkedList<T>::~LinkedList()
 {
    Node<T>* currentPtr = head;
    while (nullptr != currentPtr)
    {
        Node<T>* tempPtr = currentPtr->next;
        delete currentPtr;
        currentPtr = tempPtr;
    }
 }

 template <class T>
 T LinkedList<T>::deleteFromHead()
 {
    if (nullptr != head)
    { 
        Node<T>* copyHead = head;
        T deletedValue = copyHead->data; 
        head = head->next;
        delete copyHead;
        return deletedValue;
    }
    return T(0);
 }


 template <class T>
 T LinkedList<T>::deleteFromTail()
 {
    if (nullptr == head) return T(0);
    if (nullptr == head->next) return deleteFromHead();
    Node<T>* currentPtr = head;
    Node<T>* nextPtr = head->next;
    while (nextPtr->next != nullptr)
    {
        currentPtr = nextPtr;
        nextPtr = nextPtr->next;
    }
    T deletedValue = nextPtr->data;
    delete nextPtr;
    currentPtr->next = nullptr;
    return deletedValue;
 }
 
 template <class T>
 void LinkedList<T>::deleteNode(T data)
 {
    if (nullptr == head) return;
    if (head->data == data)
    {
        deleteFromHead();
        return;
    }

    Node<T>* currentPtr = head;
    for (Node<T>* nextPtr = head->next; nextPtr != nullptr; 
         currentPtr = nextPtr, nextPtr = nextPtr->next)
    {
        if (nextPtr->data == data)
        {
            currentPtr->next = nextPtr->next;
            delete nextPtr;
            return;
        }
    }
 }
 

 template <class T>
 void LinkedList<T>::InsertToHead(T data)
 {
     Node<T> * newNode = new Node<T>(data, nullptr);
     
     if (head == nullptr)
         head = newNode;
     else
     {
         newNode->next = head;
         head = newNode;
     }
 }


 template <class T>
 void LinkedList<T>::InsertToTail(T data)
 {
     Node<T>* newNode = new Node<T>(data, nullptr);

     if (head == nullptr) head = newNode;
     else
     {
        Node<T>* currentPtr = head;
        while (currentPtr->next != nullptr)
        {
            currentPtr = currentPtr->next;
        }
        currentPtr->next = newNode;
     }
 }


 template <class T>
 int LinkedList<T>::getSize()
 {
     int count = 0;
     Node<T>* currentPtr = head;
     while(currentPtr != nullptr)
     {
        ++count;
        currentPtr = currentPtr->next;
     }
     return count;
 }


 template <class T>
 void LinkedList<T>::print()
 {
     if (head == nullptr)
     {
         cout << "Linked list is empty" << endl;;
         return;
     }
     
     cout << head->data << " ";
     
     if (head->next == nullptr)
     {
         cout << endl;
         return;
     }
 
     Node<T>* currNode = head->next;
     Node<T>* prevNode = head;
 
     
     while (currNode->next != nullptr)
     {
         cout << currNode->data << " ";
         prevNode = currNode;
         currNode = currNode->next;
     }
 
     cout << currNode->data << endl;
     return;
 }

// StackFromList inherits from LinkedList
// Part B
 template <class T = int> 
 class StackFromList 
{
    public:
        StackFromList();
        ~StackFromList();
        void push(T);
        T pop();
        bool isEmpty();

    private: 
        LinkedList <T> _myLinkedList;
 };

template <class T>
 StackFromList<T>::StackFromList() { }

template <class T>
 StackFromList<T>::~StackFromList() { }

template <class T>
 void StackFromList<T>::push(T data)
 {
    _myLinkedList.InsertToHead(data);
 }

template <class T>
 T StackFromList<T>::pop()
 {
    return _myLinkedList.deleteFromHead();
 }

 template <class T>
 bool StackFromList<T>::isEmpty()
 {
    return (0 == _myLinkedList.getSize());
 }

// Part C
 template <class T = int> 
 class QueueFromList 
{
    public:
        QueueFromList();
        ~QueueFromList();
        void enqueue(T data);
        T dequeue();
        bool isEmpty();

    private: 
        LinkedList <T> _myLinkedList;
 };

template <class T>
 QueueFromList<T>::QueueFromList() { }

template <class T>
 QueueFromList<T>::~QueueFromList() { }

template <class T>
 void QueueFromList<T>::enqueue(T data)
 {
    _myLinkedList.InsertToTail(data);
 }

template <class T>
 T QueueFromList<T>::dequeue()
 {
    return _myLinkedList.deleteFromHead();
 }

 template <class T>
 bool QueueFromList<T>::isEmpty()
 {
    return (0 == _myLinkedList.getSize());
 }
#endif /* LinkedList_h */