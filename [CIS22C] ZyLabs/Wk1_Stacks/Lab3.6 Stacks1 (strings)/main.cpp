/**~*~*~*
CIS 22C
Project: Stack of strings

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
       string value;           // Value in the node
       StackNode *next;     // Pointer to next node
   };

   StackNode *top;          // Pointer to the stack top
   int length;

public:
   Stack_str(){ top = NULL; length = 0; }    //Constructor
   //~Stack_str();                           // Destructor

   // Stack operations
   bool isEmpty() {/* Write your code here */ }
   bool push(string);
   // string pop();
   string peek() {/* Write your code here */ }
   int getLength() {/* Write your code here */ }
};

/**~*~*~*
  Member function push: pushes the argument onto the stack.
*~**/
bool Stack_str::push(string item)
{
   StackNode *newNode; // Pointer to a new node

   // Allocate a new node and store item there.
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


int main() {

     Stack_str s;
     string item;

     /* Write your code here */
     
     return 0;
}