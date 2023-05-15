/**~*~*~*
CIS 22C
Project: Queue of strings (pop)

Written by: Daniel Wong
IDE: ZyBooks
*~*/
#include <iostream>
#include <string>
using namespace std;

class Queue_str
{
private:
   // Structure for the queue nodes
   struct QueueNode {
       string value;        // Value in the node
       QueueNode *next;     // Pointer to next node
   };

   QueueNode *front;          // Pointer to the first node
   QueueNode *rear;           // Pointer to the last node
   int length;                // Number of nodes in the queue

public:
   Queue_str(){ front = rear = NULL; length = 0; }    //Constructor
   //~Queue_str();                                    // Destructor

   // Queue operations
   bool isEmpty() {return length == 0;}
   bool push(string);
   string pop();
   //string peek();
   //string peekRear();
   //int getLength();
};

/**~*~*~*
  Member function push: inserts the argument into the queue
*~**/
bool  Queue_str::push(string item)
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

/**~*~*~*
  Member function dequeue deletes the value at the front
  of the queue and returns it.
  Assume queue has at least one node
*~**/
string Queue_str::pop()
{
   /* Write your code here */
   QueueNode *pDel;
   
   string item = front->value; //temp value to return
   pDel = front;
   
   if (length == 1) //check if length is != 0
      rear = nullptr;
   front = front->next; //shift node
   
   length--; //lower value of length
   delete pDel;
   return item; //return final value
}

int main() {

     Queue_str que;
     string item;
    
     /* Write your code here */
     while (getline(cin, item) && item != "#") { //while item != 0
        que.push(item); //push
     }
     
     if (!que.isEmpty()) { //check if queue is not empty
        while (!que.isEmpty()) {
           cout << que.pop() << endl; //pop
        }
     }
     
     else {
        cout << "Empty Queue!" << endl;
     }
       
     return 0;
}
