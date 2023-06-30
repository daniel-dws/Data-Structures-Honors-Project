/**~*~*~*
CIS 22C
Project: Stack of strings (Destructor)

Written by: Daniel Wong
IDE: ZyBooks
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
   int length;              // Number of nodes

public:
   Stack_str(){ top = NULL; length = 0; }    //Constructor
   ~Stack_str();                             // Destructor

   // Stack operations
   // bool isEmpty();
   bool push(string);
   // string pop();
   // string peek();
   // int getLength();
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

/**~*~*~*
   Destructor
*~**/
Stack_str::~Stack_str()
{
   StackNode *currNode;
   StackNode *tempNode;

   // Position nodePtr at the top of the stack.
   currNode = top;

   // Traverse the list deleting each node.
   while (currNode != nullptr)
   {
      tempNode = currNode; //set node value with a temporary to delete
      cout << currNode->value << " - deleted!" << endl;
      delete currNode; //delete node
      currNode = NULL; //set value = null
      currNode = tempNode->next; //move value on from temp
   }
   
   cout << "Empty stack!" << endl;
}

int main() {

     Stack_str s;
     string item = " ";
     
     /* Write your code here */
     while (getline(cin, item) && item != "0") {
        s.push(item); //push item while val != 0
     }
     
     return 0;
}
