/**~*~*~*
CIS 22C
Project: Stack of strings (pop)

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
   int length;

public:
   Stack_str(){ top = NULL; length = 0; }    //Constructor
   // ~Stack_str();                          // Destructor

   // Stack operations
   bool isEmpty() {return length == 0;}/* Write your code here */
   bool push(string);
   string pop();
   string peek();
   int getLength() {return length;}
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
string Stack_str::pop()
{
   StackNode *currNode;
   currNode = top;
   
   string temp = top->value; //hold temporary value of node
   
   top = top->next; //move value onto next
   delete currNode; //delete node
   
   length--; //lower the length
   return temp;
}

int main() {

   Stack_str s;
   string item;
     
   /* Write your code here to test the push and pop functions */
   while (getline(cin, item) && item != "0") {
      s.push(item); //push item while val != 0
   }
   
   int stackLength = s.getLength(); //hold length in var

   if (s.getLength() != 0) { //check if stack length !=0
      for (int i = 0; i < stackLength; i++) {
         cout << s.pop() << endl; //pop values in a loop accordingly
      }
   }
   
   else {
       cout << "Empty Stack!" << endl;
   }
}
