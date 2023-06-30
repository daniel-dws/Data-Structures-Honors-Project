// Specification file for the LinkedList class
// Written By: Daniel Wong
// Reviewed & Modified by: Daniel Wong
// IDE: Xcode

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "ListNodeADT.h"

template <class T>
class LinkedList
{
private:
    ListNode<T> *head;
    int length;

public:
    LinkedList();   // constructor
    ~LinkedList();  // destructor

    // Linked list operations
    int getLength() const {return length;}
    bool isEmpty() const {return length == 0;}
    void insertNode(const T &);
    bool deleteNode(const T &);
    
    void displayListForw() const;
    void displayListBack() const;
    bool searchList(const T &, T &) const;
};

// **************************************************
// Constructor
// This function allocates and initializes a sentinel node
//      A sentinel (or dummy) node is an extra node added before the first data record.
//      This convention simplifies and accelerates some list-manipulation algorithms,
//      by making sure that all links can be safely dereferenced and that every list
//      (even one that contains no data elements) always has a "first" node.
// **************************************************
template <class T>
LinkedList<T>::LinkedList()
{
    head = new ListNode<T>; // head points to the sentinel node
    head->setNext(head);
    head->setPrev(head);
    length = 0;
}

// **************************************************
// The insertNode function inserts a new node in a
// sorted linked list
// **************************************************
template <class T>
void LinkedList<T>::insertNode(const T &dataIn)
{
    ListNode<T> *newNode;  // A new node
    ListNode<T> *pCur;     // To traverse the list
    ListNode<T> *pPre;     // The previous node
    
    // Allocate a new node and store dataIn there.
    newNode = new ListNode<T>(dataIn);

    // Initialize pointers
    pCur = head->getNext();

    // Find location: skip all nodes whose code is less than dataIn's code
    while (pCur != head && newNode->getData().getCode() > pCur->getData().getCode())
    //while (pCur != head && newNode->getData() > pCur->getData())
    {
        pCur = pCur->getNext();
    }
    
    // Insert the new node between pPre and pCur
    pPre = pCur->getPrev();
    pPre->setNext(newNode);
    newNode->setNext(pCur);
    newNode->setPrev(pPre);
    pCur->setPrev(newNode);
      
    // Update the counter
    length++;
}

// **************************************************
// The deleteNode function searches for a node
// in a sorted linked list; if found, the node is
// deleted from the list and from memory.
// **************************************************
//bool LinkedList::deleteNode(string target)
template <class T>
bool LinkedList<T>::deleteNode(const T &target)
{
    ListNode<T> *pCur;       // To traverse the list
    ListNode<T> *pPre;       // To point to the previous node
    bool deleted = false;
        
    // Initialize pointers
    pCur = head->getNext();
    //pPre = head->getPrev();

    // Find node containing the target: Skip all nodes whose gpa is less than the target
    while (pCur != head && pCur->getData() < target)
    {
        pCur = pCur->getNext();
    }
        
    // If found, delete the node
    if (pCur != head && pCur->getData() == target)
    {
        pPre = pCur->getPrev();
        pPre->setNext(pCur->getNext());
            
        /* Write your code here */
        pCur->getNext()->setPrev(pCur->getPrev());
       
        //pPre->setNext(pCur->getPrev());
        delete pCur;
        deleted = true;
        length--;
    }
    return deleted;
}

// **************************************************
// displayList shows the value
// stored in each node of the linked list
// pointed to by head, except the sentinel node
// **************************************************
template <class T>
void LinkedList<T>::displayListForw() const
{
     ListNode<T> *pCur;  // To move through the list

     // Position pCur: skip the head of the list.
     pCur = head->getNext();

     // While pCur points to a node, traverse the list.
     while (pCur != head)
     {
         // Display the value in this node.
         pCur->getData().hDdisplay();
         
          //std::cout << pCur->getData();
         
         // Move to the next node.
         pCur = pCur->getNext();
    }
    std::cout << std::endl;
}

// **************************************************
// displayList shows the value
// stored in each node of the linked list
// pointed to by head, except the sentinel node
// **************************************************
template <class T>
void LinkedList<T>::displayListBack() const
{
     ListNode<T> *pPre;  // To move through the list

     // Position pCur: skip the head of the list.
     pPre = head->getPrev();

     // While pCur points to a node, traverse the list.
     while (pPre != head)
     {
         // Display the value in this node.
         pPre->getData().hDdisplay();
         
          //std::cout << pPre->getData();
         
         // Move to the next node.
         pPre = pPre->getPrev();
    }
    std::cout << std::endl;
}

// **************************************************
// The searchList function looks for a target college
// in the sorted linked list: if found, returns true
// and copies the data in that node to the output parameter
// **************************************************
template <class T>
bool LinkedList<T>::searchList(const T &target, T &dataOut) const
{
    bool found = false; // assume target not found
    ListNode<T> *pCur;         // To move through the list
    
    // Position pCur: skip the head of the list.
    pCur = head->getNext();
    // Find location: skip all nodes whose code is less than target
   /* Write your code here */
    while (pCur != head && pCur->getData() < target) {
        pCur = pCur->getNext();
    }
        // If found, copy data to the output parameter, and change the flag to true
        /* Write your code here */
    if (pCur->getData() == target) { //if target is found
        found = true; //update boolean to true
        dataOut = pCur->getData(); //return object of the node
        //break; //Break after target is found so loop stops running
    }

    return found;
}

// **************************************************
// Destructor
// This function deletes every node in the list.
// **************************************************
template <class T>
LinkedList<T>::~LinkedList()
{
    ListNode<T> *pCur;     // To traverse the list
    ListNode<T> *pNext;    // To hold the address of the next node
    
    // Position nodePtr: skip the head of the list
    pCur = head->getNext();
    // While pCur is not at the end of the list...
    while(pCur != head)
    {
        // Save a pointer to the next node.
        pNext = pCur->getNext();
        
        // Delete the current node.
        delete pCur;
        
         // Position pCur at the next node.
        pCur = pNext;
    }
    
    delete head; // delete the sentinel node
}



#endif

