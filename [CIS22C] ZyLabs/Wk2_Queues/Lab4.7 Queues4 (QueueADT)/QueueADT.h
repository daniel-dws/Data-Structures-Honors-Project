/**~*~*~*
   Queue template
*~**/
#ifndef QUEUE_ADT_H
#define QUEUE_ADT_H

template <class T>
class Queue
{
private:
   // Structure for the stack nodes
   struct QueueNode {
       T value;        // Value in the node
       QueueNode *next;     // Pointer to next node
   };

   QueueNode *front;          // Pointer to the first node
   QueueNode *rear;           // Pointer to the last node
   int length;                // Number of nodes in the queue

public:
   Queue(){ front = rear = NULL; length = 0; }    //Constructor
   ~Queue();                                    // Destructor

   // Queue operations
   /* Write your code here */
   // isEmpty
   // push
   // pop
   // peek
   // peekRear
   // getLength 
};

/**~*~*~*
  Member function push: inserts the argument into the queue
*~**/
/* Write your code here */


/**~*~*~*
  Member function deletes the value at the front
  of the queue and returns it.
  Assume queue has at least one node
*~**/
/* Write your code here */

/**~*~*~*
   Destructor
*~**/
/* Write your code here */

#endif

