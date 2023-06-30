/*
    Lab: CIS 22C - Honors Project
    Name: Daniel Wong & Ben Hung
    Date: 5/22/23
    Description: A program that calculates the size of objects based on scanning a 2D array of a file.
*/

using namespace std;
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Matrix.h"
#include "StackADT.h"

struct Coords {
    int i;
    int j;
};

//Function Declarations
int calcArea(int i, int j, Matrix list);
int calcAreaStk(int i, int j, Matrix list);

/*
 This function (main) does the following:
     - Welcomes user and prompts for the word
     - Asks user for the filename
     - Calls recusive function to calculate area
     - Asks user to repeat program

     Function written by: Daniel Wong
     Debugged by: Ben Hung
*/

int main() {
    
    /*
    // Intro to the program.
    cout << "Welcome to the CIS22C Honors Project Program!" << endl;
    cout << "This program takes in an input file, finds the nonzero objects inside, then calculates the area of those objects." << endl;

    // Asking user what solution they would like to use (iterative or recursive).
    string solution;
    cout << "Would you like to use the recursive solution or iterative solution to calculate the area of these objects? (Enter recursive/iterative, or 'quit' to stop the program)" << endl;
    cin >> solution;

    // Quitting the program if "quit" is entered.
    if (solution == "quit") {
        return 0;
    }
    */

    // Getting the filename from the user.
    cout << "\nPlease enter the file you would like to parse:" << endl;
    string fileName;
    cin >> fileName;

    // Reading the number of rows and columns from the first line of the text file.
    ifstream inputFile;
    inputFile.open(fileName.c_str());

    // Validating the file.
    if(inputFile.fail()){
        std::cout << "Error opening " << fileName << " for reading." << std::endl;
        exit(EXIT_FAILURE);
    }

    // Getting the number of rows and columns.
    int rows;
    int cols;
    inputFile >> rows;
    inputFile >> cols;

    // Creating a Matrix object and reading the file from the name provided.
    Matrix list(rows, cols);
    list.readList(fileName);

    cout << list.checkEnd(0,0) << endl;
    //return 0;

    // Vector to keep track of number of areas as well as the number of objects in an area.
    vector<int> areas;
    
    // Creating the stack for the iterative version of the program.
    // Stack<Coords> stack;
    
    // Iterating through all the characters in the Matrix object, then calling the calcAreaStk() function on each.
    int area = 0;
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {

            
            // Checking that the object is non-zero before calling the calcAreaStk() function.
            if (list.getPosition(i, j) != '0' || list.getPosition(i, j) != 'x') {
                area = calcAreaStk(i, j, list);
                cout << "Moved on to next object." << endl;
            }

            if (area != 0) {
                areas.push_back(area);
            }
        }
    }
    for (int i = 0; i < areas.size(); i++) {
        cout << "Object " << i << ": " << areas.at(i) << " squares." << endl;
    }

    list.printList();

    return 0;
}


/*
    This function (calcAreaStk) does the following:
    Purpose: Iterative function meant for calculating the area of an object using a stack.
    
    Function written by: Daniel Wong
    Debugged by: Ben Hung
*/
int calcAreaStk(int i, int j, Matrix list) {

    Stack<Coords> stack;

    Coords currentItm;
    currentItm.i = i;
    currentItm.j = j;

    if (list.getPosition(i, j) != '0' && list.getPosition(i, j) != '*') {
        stack.push(currentItm);
    }

    // Creating a temp Coords item.
    Coords newObject;

    int area = 0;
    
    // While loop if stack is not empty.
    while (!stack.isEmpty() && !list.checkEnd(currentItm.i, currentItm.j)) {

        if (!list.outOfBounds(currentItm.i+1, currentItm.j) && list.getPosition(currentItm.i+1, currentItm.j) != '0' && list.getPosition(currentItm.i+1, currentItm.j) != 'x' && list.getPosition(currentItm.i+1, currentItm.j) != '*') {
            //cout << "If statement #1" << endl;
            list.setPosition(currentItm.i, currentItm.j, '*');
            newObject.i = currentItm.i+1;
            newObject.j = currentItm.j;
            stack.push(newObject);
            cout << "Item Pushed in statemtn 1: " << newObject.i << " " << newObject.j << endl;
            cout << "Item Pushed: " << list.getPosition(newObject.i, newObject.j) << endl;
            //list.setPosition(currentItm.i+1, currentItm.j, 'x');
            //list.setPosition(currentItm.i, currentItm.j, 'x');

            // Changing current position.
            currentItm.i += 1;
        }
        else if (!list.outOfBounds(currentItm.i-1, currentItm.j) && list.getPosition(currentItm.i-1, currentItm.j) != '0' && list.getPosition(currentItm.i-1, currentItm.j) != 'x' && list.getPosition(currentItm.i-1, currentItm.j) != '*') {
            //cout << "If statement #2" << endl;
            list.setPosition(currentItm.i, currentItm.j, '*');
            newObject.i = currentItm.i-1;
            newObject.j = currentItm.j;
            stack.push(newObject);
            cout << "Item Pushed in statement 2:" << newObject.i << " " << newObject.j << endl;
            cout << "Item Pushed: " << list.getPosition(newObject.i, newObject.j) << endl;
            //list.setPosition(currentItm.i-1, currentItm.j, 'x');
            //list.setPosition(currentItm.i, currentItm.j, 'x');

            // Changing current position.
            currentItm.i -= 1;
        }
        else if (!list.outOfBounds(currentItm.i, currentItm.j+1) && list.getPosition(currentItm.i, currentItm.j+1) != '0' && list.getPosition(currentItm.i, currentItm.j+1) != 'x' && list.getPosition(currentItm.i, currentItm.j+1) != '*') {
            //cout << "If statement #3" << endl;
            list.setPosition(currentItm.i, currentItm.j, '*');
            newObject.i = currentItm.i;
            newObject.j = currentItm.j+1;
            stack.push(newObject);
            cout << "Item Pushed in statement 3: " << newObject.i << " " << newObject.j << endl;
            cout << "Item Pushed: " << list.getPosition(newObject.i, newObject.j) << endl;
            //list.setPosition(currentItm.i, currentItm.j+1, 'x');
            //list.setPosition(currentItm.i, currentItm.j, 'x');

            // Changing current position.
            currentItm.j += 1;
        }
        else if (!list.outOfBounds(currentItm.i, currentItm.j-1) && list.getPosition(currentItm.i, currentItm.j-1) != '0' && list.getPosition(currentItm.i, currentItm.j-1) != 'x' && list.getPosition(currentItm.i, currentItm.j-1) != '*') {
            list.setPosition(currentItm.i, currentItm.j, '*');
            newObject.i = currentItm.i;
            newObject.j = currentItm.j-1;
            stack.push(newObject);
            cout << "Item Pushed in statement 4:" << newObject.i << " " << newObject.j << endl;
            cout << "Item Pushed: " << list.getPosition(newObject.i, newObject.j) << endl;
            //list.setPosition(currentItm.i, currentItm.j-1, 'x');
            //list.setPosition(currentItm.i, currentItm.j, 'x');

            // Changing current position.
            currentItm.j -= 1;
        }

        //cout << "Top of the stack: ";
        //cout << stack.peek().i << " " << stack.peek().j << endl;

        //cout << "1st while loop" << endl;
        //cout << currentItm.i << " " << currentItm.j << endl;
        //cout << (!stack.isEmpty() && !list.checkEnd(currentItm.i, currentItm.j)) << endl;
        //cout <<  "Dead End: " << list.checkEnd(currentItm.i, currentItm.j) << endl;
        //cout << "Non-empty Stack: " << !stack.isEmpty() << endl;
        while (list.checkEnd(currentItm.i, currentItm.j) && !stack.isEmpty()) {

            Coords poppedItem = stack.pop();
            // Setting position to 'x' after popping it from the stack.
            list.setPosition(poppedItem.i, poppedItem.j, 'x');
            cout << "Item Popped: " << list.getPosition(poppedItem.i, poppedItem.j) << endl;
            cout << "Item Popped Position: " << poppedItem.i << " " << poppedItem.j << endl;

            if (!stack.isEmpty()) {
                Coords temp = stack.peek();
                currentItm.i = temp.i;
                currentItm.j = temp.j;
            }
            area += 1;
            //cout << area << endl;
            //cout << "Inner while loop" << endl;

            cout <<  "Dead End: " << list.checkEnd(currentItm.i, currentItm.j) << endl;
        }
        /*
        if (!stack.isEmpty()) {
                Coords temp = stack.peek();
                currentItm.i = temp.i;
                currentItm.j = temp.j;
                //cout << "Current Position: " << currentItm.i << " " << currentItm.j << endl;
        }
        */
        //cout << (!stack.isEmpty() && !list.checkEnd(currentItm.i, currentItm.j)) << endl;
        //cout <<  list.checkEnd(currentItm.i, currentItm.j) << endl;
        //list.printList();
    }

    // Checking if area is just one object; then adding area.
    if (list.checkEnd(i, j) && stack.getLength() == 1 && list.getPosition(i, j) != '0' && list.getPosition(i, j) != 'x') {
        Coords poppedItem = stack.pop();

        // Setting position to 'x' after popping it from the stack.
        list.setPosition(poppedItem.i, poppedItem.j, 'x');

        area++;
    }

    return area;
}


/*
    This function (calcArea) does the following:
    Purpose: Recursive function meant for calculating the area of a object.
    
    Function written by: Ben Hung
     Debugged by: Daniel Wong
*/
/*
int calcArea(int i, int j, Matrix list) {
    
    // Initializing the area variable.
    int area;
    
    // Don't run the program if i or j are negative or above the max number of rows/cols.
    if (i < 0 || j < 0 || i > list.getRows()-1 || j > list.getCols()-1) {
        area = 0;
    }
    // Checking if object is nonzero.
    else if (list.getPosition(i, j) != '0' && list.getPosition(i, j) != 'x') {
        area = 1;

        // If we find a nonzero object, setting the object to 'x' to ensure we don't count the same object twice.
        list.setPosition(i, j, 'x');

        // Searching for areas in all directions (up, down, right, and left).
        area += calcArea(i+1, j, list);
        area += calcArea(i-1, j, list);
        area += calcArea(i, j+1, list);
        area += calcArea(i, j-1, list);
    }
    else {
        // If a object with the char '0' is found, returning area is 0.
        area = 0;
    }
    return area;
}
*/
