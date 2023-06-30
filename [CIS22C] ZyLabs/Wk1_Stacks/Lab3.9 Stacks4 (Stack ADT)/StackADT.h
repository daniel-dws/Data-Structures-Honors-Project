/**~*~*~*~*
   Stack template
*~*/

//Written By: Daniel Wong

#ifndef STACK_ADT
#define STACK_ADT

using namespace std;

template <class T>
class Stack
{
private:
    // Structure for the stack nodes
    struct StackNode
    {
      T value;          // Value in the node
      StackNode *next;  // Pointer to next node
    };

    StackNode *top;     // Pointer to the stack top
    int length;

public:
    Stack(){ top = NULL; length = 0; }    //Constructor
    ~Stack();                          // Destructor

    // Stack operations:
    bool push(T); // push()
    T pop(); // pop()
    T peek(); // peek()
    bool isEmpty(); // isEmpty()
    int getLength() {return length;} // getLength()
};
template <class T>
bool Stack<T>::isEmpty()
{
   if (length == 0) {
      return true;
   }
   else {
      return false;
   }
}

template <class T>
T Stack<T>::peek()
{
   return top->value;
}



/**~*~*~*~*
  Member function push inserts the argument onto
  the stack.
*~**/
template <class T>
bool Stack<T>::push(T item)
{
   StackNode *newNode; // Pointer to a new node

   // Allocate a new node and store num there.
   newNode = new StackNode;
   if (!newNode)
       return false;
   newNode->value = item;

   // Update links and counter
   newNode->next = top;
   top = newNode;
   length++;

   return true;
}

/**~*~*~*~*
  Member function pop deletes the value at the top
  of the stack and returns it.
  Assume stack is not empty.
*~**/
template <class T>
T Stack<T>::pop()
{
   StackNode *currNode;
   currNode = top;
   
   T temp = top->value;
   top = top->next;
   delete currNode;
   
   length--;
   return temp;
}

/**~*~*~*~*
  Destructor:
  Traverses the list deleting each node (without calling pop)
*~**/

template <class T>
Stack<T>::~Stack()
{
    StackNode *pCur;     // To traverse the list
    StackNode *pNext;    // To hold the address of the next node
    
    // Position nodePtr: skip the head of the list
    pCur = top;
    // While pCur is not at the end of the list...
    while(pCur != NULL)
    {
        // Save a pointer to the next node.
        //pNext = top->next; // ERROR: double free!
        pNext = pCur->next;
        
        // Delete the current node.
        delete pCur;
        
         // Position pCur at the next node.
        pCur = pNext;
    }
    
    //delete top; // delete the sentinel node
}

#endif
