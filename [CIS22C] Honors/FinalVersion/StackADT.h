/**~*~*~*~*
   Stack ADT template 

   Written by: Ben Hung and Daniel Wong
   IDE Used: Visual Studio Codes
*~*/

#ifndef STACK_ADT
#define STACK_ADT

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
    // Constructor
    Stack() { top = NULL; length = 0; }
    // Destructor
    ~Stack();
    // Stack operations:
    bool push(T);
    T pop();
    
    // Returns the top value of the stack.
    T peek() { return top->value; }
    
    // Checks if the stack is empty.
    bool isEmpty() {
      return length == 0;
    }
    
    // Returns the length of the stack.
    int getLength() { return length;  }
};

/**~*~*~*~*
  Member function push inserts the argument onto
  the stack.
*~**/
template <class T>
bool Stack<T>::push(T value) {

  // Creating a new node to insert in the stack.
  StackNode *newNode;

   // Allocate a new node and store value there.
   newNode = new StackNode;
   if (!newNode)
       return false;
   newNode->value = value;

   // Update links and length.
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
T Stack<T>::pop() {

  // Creating temporary node to store top.
  StackNode *topNode;
  topNode = top;

  // Storing the value at the top.
  T temp = top->value;

  // Moving to the next item, since the top will be deleted.
  top = top->next;

  // Deleting the value at the top.
  delete topNode;
  length--;

  return temp;
}

/**~*~*~*~*
  Destructor:
  Traverses the list deleting each node (without calling pop)
*~**/

template <class T>
Stack<T>::~Stack() {
  StackNode *currNode;
  StackNode *tempNode;

  // Creating a node to point at the top of the stack.
  currNode = top;

  // Creating a temporary node to store currNode->next.
  tempNode = new StackNode;

  // Traverse the list, deleting each node.
  while (currNode) 
  {

    // Storing the currNode->next in a temporary node.
    tempNode->next = currNode->next;

    // Deleting the top node.
    delete currNode;
    // currNode = NULL;

    // Pointing the node to the now top node.
    currNode = tempNode->next;
  }
}

#endif
