// Specification file for the ListNode class
// Written By: A. Student
// Reviewed & Modified by: <Write your name here>
// IDE: Xcode

#ifndef LISTNODE_H
#define LISTNODE_H
#include <iostream>
#include "Park.h"

class ListNode
{
private:
    Park data;         // store data
    ListNode *forw;    // a pointer to the next node in the list
    ListNode *back;    // a pointer to the previous node in the list
public:
    //Constructor
    ListNode(){forw = back = NULL;}
    ListNode(const Park &dataIn, ListNode *forw = NULL, ListNode *back = NULL){ data = dataIn;}
    
    // setters
    // set the forw pointer
    void setNext(ListNode* nextPtr) {forw = nextPtr;}
     // set the back pointer
     /* Write your code here: setPrev() */
    
    // getters
    // return pointer in the next node
    ListNode *getNext() const {return forw;}
   // return pointer in the previous node
   /* Write your code here: getPrev() */
   
    // return data object in the listnode: getData()
    /* Write your code here */
};

#endif
