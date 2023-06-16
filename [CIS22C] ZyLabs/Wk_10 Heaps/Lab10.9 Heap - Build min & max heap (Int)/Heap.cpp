/* *~*~*
Implementation file for the Heap class: min- or max-heap of integers
Written By: A. Student
Changed by: Daniel Wong
IDE: xCode
*~**/

#include "Heap.h"

/* *~*~*
 The private member function _reHeapUp rearranges the heap after insert by moving the
 last item up to the correct location in the heap
 *~**/
void Heap::_reHeapUp(int lastndx, int compare(int, int))
{
	if (lastndx) // means lastndx != 0, i.e. newElement is not heap's root
	{
        int parent = _findParent(lastndx); // parent = parent of newElement
		/* Write your code here */
        if (compare(heapAry[lastndx], heapAry[parent]) == -1)
        {
            int temp = heapAry[lastndx];
            heapAry[lastndx] = heapAry[parent];
            heapAry[parent] = temp;
            
            _reHeapUp(parent, compare);
        }
	}
}

/* *~*~*
 The private member function _reHeapDown rearranges the heap after delete by moving the
 data in the root down to the correct location in the heap
 *~**/
void Heap::_reHeapDown(int rootdex, int compare(int, int))
{
	int left = _findLeftChild(rootdex);
	if (left != -1) // if there's a left child
    {
        /* Write your code here */
        int largest = left;
        int right = _findRightChild(rootdex);
        if (right != -1) // if there's a right child
        {
            if (compare(heapAry[right], heapAry[left]) == -1)
            {
                largest = right;
            }
        }
        if (compare(heapAry[largest], heapAry[rootdex]) == -1)
        {
            int temp = heapAry[largest];
            heapAry[largest] = heapAry[rootdex];
            heapAry[rootdex] = temp;
            
            _reHeapDown(largest, compare);
        }
    }
}
/* *~*~*
 The public member function insertHeap inserts a new item into a heap.
 It calls _reheapUp.
 *~**/
bool Heap::insertHeap(int newItem, int compare(int, int))
{
	if (isFull())
		return false;
		
	/* Write your code here */
    heapAry[count] = newItem;
    _reHeapUp(count, compare);
    count++;
	
	return true;
}

/* *~*~*
 The public member function deleteHeap deletes the root of the heap and
 passes back the root's data. It calls _reheapDown.
 *~**/
bool Heap::deleteHeap(int &returnItem, int compare(int, int))
{
	if (isEmpty())
		return false;
		
	/* Write your code here */
    returnItem = heapAry[0];
    heapAry[0] = heapAry[count - 1];
    count--;
    _reHeapDown(0, compare);
     return true;
}
