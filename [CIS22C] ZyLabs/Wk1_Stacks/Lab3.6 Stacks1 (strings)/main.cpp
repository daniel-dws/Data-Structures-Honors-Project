/**~*~*~*
CIS 22C
Project: Stack of strings

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
       string value;           // Value in the node
       StackNode *next;     // Pointer to next node
   };

   StackNode *top;          // Pointer to the stack top
   int length;

public:
   Stack_str(){ top = NULL; length = 0; }    //Constructor
   //~Stack_str();                           // Destructor

   // Stack operations
   bool isEmpty() {return length == 0;}
   bool push(string);
   // string pop();
   string peek() {return top->value;}
   int getLength() {return length;}
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

     Stack_str s; //Object
     string item = " "; //Cin value

     /* Write your code here */
     while (getline(cin, item) && item != "0") {
        s.push(item); //push onto stack while val != 0
     }
     
     cout << s.getLength() << endl;
     if (s.getLength() == 0) { //check if length of stack == 0
        cout << "Empty Stack!" << endl;
        cout << s.getLength() << endl; //getLength
     }
     else {
       cout << s.peek() << endl;
       cout << s.getLength() << endl;
     }
     return 0;
}
