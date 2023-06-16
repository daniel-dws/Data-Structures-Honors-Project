/* *~*~*
Implementation file for the Heap class: min-heap of integers
Written By: A. Student
Changed by: Daniel Wong
IDE: xCode
*~**/

#include "Heap.h"

/* *~*~*
 The private member function _reHeapUp rearranges the heap after insert by moving the
 last item up to the correct location in the heap
 *~**/
void Heap::_reHeapUp(int lastndx)
{
    if (lastndx) // means lastndx != 0, i.e. newElement is not heap's root
    {
        int parent = _findParent(lastndx); // parent = parent of newElement
        // finish writing this recursive function
         /* Write  your code here */
        if (heapAry[lastndx] < heapAry[parent])
        {
            int temp = heapAry[lastndx];
            heapAry[lastndx] = heapAry[parent];
            heapAry[parent] = temp;
            
            _reHeapUp(parent);
        }
    }
}

/* *~*~*
 The private member function _reHeapDown rearranges the heap after delete by moving the
 data in the root down to the correct location in the heap
 *~**/
void Heap::_reHeapDown(int rootdex)
{
    int left = _findLeftChild(rootdex);
    // finish writing this recursive function
    if (left != -1) // if there's a left child
    {
        /* Write your code here */
        int largest = left;
        int right = _findRightChild(rootdex);
        if (right != -1) // if there's a right child
        {
            if (heapAry[right] < heapAry[left])
            {
                largest = right;
            }
        }
        if (heapAry[largest] < heapAry[rootdex])
        {
            int temp = heapAry[largest];
            heapAry[largest] = heapAry[rootdex];
            heapAry[rootdex] = temp;
            
            _reHeapDown(largest);
        }
    }
}

/* *~*~*
 The private member function _printIndented (recursive)
 prints the heap as an indented tree (Right-Root-Left)
 *~**/

/* Write  your code here */
void Heap::_printIndented(int index, void visit(int, int), int level)
{
    if (index < count && index != -1)
    {
        _printIndented(_findRightChild(index), visit, level+1);
        
        visit(heapAry[index], level);
        
        _printIndented(_findLeftChild(index), visit, level+1);
    }
}

/* *~*~*
 The public member function insertHeap inserts a new item into a heap.
 It calls _reheapUp.
 *~**/
bool Heap::insertHeap(int newItem)
{
    // finish writing this function
    if (isFull())
        return false;
   /* Write  your code here */
    heapAry[count]= newItem;
    _reHeapUp(count);
    count++;
    
   return true;
}

/* *~*~*
 The public member function deleteHeap deletes the root of the heap and
 passes back the root's data. It calls _reheapDown.
 *~**/
bool Heap::deleteHeap(int &returnItem)
{
    // finish writing this function
    if (isEmpty())
        return false;
 /* Write  your code here */
   returnItem = heapAry[0];
   heapAry[0] = heapAry[count - 1];
   count--;
   _reHeapDown(0);
    return true;
}

/* *~*~*
 The public member function printIndented
 prints the heap as an indented tree (Right-Root-Left)
 It calls _printIndented.
 *~**/
 
 /* Write  your code here */
void Heap::printIndented(void visit(int, int))
{
    _printIndented(0, visit, 0);
}

