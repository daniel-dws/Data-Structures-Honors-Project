/**~*~*~*
CIS 22C
Project: Stack of strings (pop)

Written by:
IDE:
*~*/
#include <iostream>
#include <string>
using namespace std;

class Stack_str
{
private:
   // Structure for the stack nodes
   struct StackNode {
       string value;        // Value in the node
       StackNode *next;     // Pointer to next node
   };

   StackNode *top;          // Pointer to the stack top
   int length;

public:
   Stack_str(){ top = NULL; length = 0; }    //Constructor
   // ~Stack_str();                          // Destructor

   // Stack operations
   bool isEmpty(); /* Write your code here */
   bool push(string);
   string pop();
   string peek();
   int getLength();
};

/**~*~*~*
  Member function push: pushes the argument onto the stack.
*~**/
bool Stack_str::push(string item)
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

/**~*~*~*
  Member function pop pops the value at the top
  of the stack off, and returns it
  Assume stack is not empty
*~**/
/* Define the pop function */


int main() {

     Stack_str s;
     string item;

     /* Write your code here to test the push and pop functions */
     
     return 0;
}