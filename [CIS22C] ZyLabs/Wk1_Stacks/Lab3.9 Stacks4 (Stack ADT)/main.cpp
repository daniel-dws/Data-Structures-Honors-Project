/**~*~*~*
CIS 22C
Project: Stack ADT

Written by: Daniel Wong
IDE: ZyBooks
*~*/

#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>

#include "StackADT.h"

using namespace std;

void printInfo();
void processNumbers(string, Stack<int> &);
void printStack(Stack<int> &);

int main()
{
    printInfo();
   
    cout << "Enter input file name: \n";
    string filename;
    getline(cin, filename); // assume valid
    
    // declare stack here
    Stack<int> elementStack;
        
    // call processNumbers()
    processNumbers(filename, elementStack);
   
    // call printStack()
    printStack(elementStack);

    return 0;
}


/**~*~*~*~*~
This function displays the project's title
*~*/
void printInfo()
{
    cout << " ~*~ Project: Stack ADT ~*~ " << endl;
}


// define processNumbers(), a function to process the input file
void processNumbers(string filename, Stack<int> &elemStack) {
   
   // declare 2nd stack for keeping track of maximum in here
   //Called by constructor
   Stack<int> maxStack;
   
   // processNumbers also prints data
   ifstream inFile(filename);
   
   //if file cannot be accessed
   if(!inFile)
   {
      cout << "There was an error opening \""<< filename << "\"" << ". Exiting." << endl;
      exit(EXIT_FAILURE);
   }
    
   else {
      cout << endl << "Input File: " << filename << endl;
   }
    
    int input_num = 0; //take in value of numbers
    while (inFile >> input_num) //input files into var
    {
       
       if (input_num == 0) {
          cout << "Count: " << elemStack.getLength() << endl;
       }
       
       else if (input_num == 1) {
          if (elemStack.isEmpty()) {
            cout << "Top: Empty" << endl;
          }
          else {
             cout << "Top: " << elemStack.peek() << endl;
             cout << "Max: " << maxStack.peek() << endl;
          }
       }
       
       else if (input_num > 0) {
          // if elemstack is not empty and input_num > elemStack.peek(),
          // maxStack.push() input_num
          if (!elemStack.isEmpty() && input_num > maxStack.peek()) {
            maxStack.push(input_num);
          }
          
          // if elemstack is not empty and input_num < elemStack.peek(),
          else if (!elemStack.isEmpty() && input_num < maxStack.peek()) {
             maxStack.push(maxStack.peek());
          }
          
          // if elemStack is empty, maxStack.push() input_Num
          else if (elemStack.isEmpty()){
            maxStack.push(input_num);
          }
          elemStack.push(input_num);
       }
       
       else if (input_num < 0) {
         if (elemStack.isEmpty()) {
            cout << "Pop: Empty" << endl;
          }
          
         else {
            cout << "Pop: " << elemStack.peek() << endl;
            elemStack.pop();
            
          //REFERENCE Largest value of stack
            maxStack.pop();
            
            if (!maxStack.isEmpty()) {
               cout << "Max: " << maxStack.peek() << endl;
            }
         }
       }
    }
    inFile.close();
}

// define printStack(), a function to print the stack
void printStack(Stack<int> &elementStack) {
   if (elementStack.isEmpty()) { //check if element stack is empty
      cout << "Stack: Empty" << endl;
   } else {
      cout << "Stack: ";
      while (!elementStack.isEmpty()) { //if element stack is not empty, pop values
         cout << elementStack.peek() << " ";
         elementStack.pop();
      }
      cout << endl;
   }
}
