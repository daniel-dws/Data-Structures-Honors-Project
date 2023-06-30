/**~*~*~*~*
   Stack template
~*/

#include <cstddef>
#ifndef QUEUE_ADT
#define QUEUE_ADT

using namespace std;

template <class T>
class Queue
{
private:
    // Structure for the stack nodes
    struct QueueNode
    {
      T value;          // Value in the node
      QueueNode *next;  // Pointer to next node
    };

    QueueNode *front;  // Pointer to the first node
    QueueNode *rear;   // Pointer to the last node
    int length;

public:
    Queue() {front = rear = nullptr; length = 0;} //QueueNode Constuctor
    ~Queue();//Destructor
    bool isEmpty() {return length == 0;} //isEmpty
    int getLength() {return length;} //getLength
    T pop(); //pop
    bool push(T); //push
    T peek() {return front->value;} //peek
    T peekRear() {return rear->value;}//peekRear
};

template <class T>
Queue<T>::~Queue()
{
    QueueNode *temp;
    while (front != nullptr){
        temp = front;
        front = front->next;
        delete temp;
    }
}
    
template <class T>
T Queue<T>::pop()
{
    QueueNode *pDel; // Temporary pointer
    // delete the value at the front of the queue
    T item = front->value;
    pDel = front;
    if( length == 1 )
        rear = NULL;
    
    front = front->next;
    length--;
    delete pDel;
    return item;
}

    
template <class T>
bool Queue<T>::push(T item)
{
   QueueNode *newNode; // Pointer to a new node

   // Allocate a new node and store num there.
   newNode = new QueueNode;
   if (!newNode)
       return false;
   newNode->value = item;
   newNode->next = NULL;
   
   // Update links and counter
   if (!front) // front is NULL: empty queue
       front = newNode;
   else
       rear->next = newNode;
       
   rear = newNode;
   length++;

   return true;
}

    
#endif
    
