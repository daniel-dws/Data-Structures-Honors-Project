// Specification file for the ListNode class
// Written by: Daniel Wong
// Reviewed & Modified by: Daniel Wong
// IDE: xCode

#ifndef LISTNODE_H
#define LISTNODE_H
#include <iostream>
//#include "Park.h"
// ^^^  not included here anymore

template <class T>
class ListNode
{
private:
    T data;      // store data
    ListNode *forw;    // a pointer to the next node in the list
    ListNode *back;    // a pointer to the previous node in the list
public:
    //Constructor
    ListNode(){forw = back = NULL;}
    ListNode(const T &dataIn, ListNode *forw = NULL, ListNode *back = NULL){ data = dataIn;}
    
    // setters
    // set the forw pointer
    void setNext(ListNode* nextPtr) {forw = nextPtr;}
        
    // set the back pointer
    /* Write your code here: setPrev() */
    void setPrev(ListNode* backPtr) {back = backPtr;}
        
    // getters
    // return pointer in the next node
    ListNode *getNext() const {return forw;}
        
    // return pointer in the previous node
    /* Write your code here: getPrev() */
    ListNode *getPrev() const {return back;}
       
    // return data object in the listnode: getData()
    /* Write your code here */
    T getData() {return data;}

};

#endif
