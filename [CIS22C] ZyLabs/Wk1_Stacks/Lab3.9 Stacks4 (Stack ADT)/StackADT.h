/**~*~*~*~*
   Stack template
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
    // Destructor

    // Stack operations:
    // push()
    // pop()
    // peek()
    // isEmpty()
    // getLength()
};

/**~*~*~*~*
  Member function push inserts the argument onto
  the stack.
*~**/





/**~*~*~*~*
  Member function pop deletes the value at the top
  of the stack and returns it.
  Assume stack is not empty.
*~**/





/**~*~*~*~*
  Destructor:
  Traverses the list deleting each node (without calling pop)
*~**/


#endif
