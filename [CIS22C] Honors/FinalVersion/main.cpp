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
int calcArea(int i, int j, Matrix& list);
int calcAreaStk(int i, int j, Matrix& list);
void printIntro();
void iterativeSolution(Matrix& list);
void recursiveSolution(Matrix& list);
Matrix readInputFile();
void convertLow(string &solution);
string promptSol();

/*
 This function (main) does the following:
     - Welcomes user and prompts for the word
     - Asks user for the filename
     - Calls recursive function to calculate area
     - Asks user to repeat program

     Function written by: Daniel Wong
     Debugged by: Ben Hung
*/

int main() {

    // Printing the welcome message for the program.
    printIntro();
    string solution = " ";

    while (solution != "quit") {
        
        // Getting the input from the user; changing the input to lowercase.
        solution = promptSol();
        convertLow(solution);

        // Reading from file and running method chosen.
        if (solution == "recursive" || solution == "iterative") {
            Matrix list = readInputFile();

            if (solution == "recursive") {
                recursiveSolution(list);
            }
            else if (solution == "iterative") {
                iterativeSolution(list);
            }
            else {
                cout << "Your input is invalid. Please try again." << endl;
            }
        }
    }

    return 0;
}

/*
    This function (printIntro) does the following:
    Purpose: Prints the welcome message of the program.
*/
void printIntro() {
    cout << "Welcome to the CIS22C Honors Project Program!" << endl;
    cout << "This program takes in an input file, finds the nonzero objects inside, then calculates the area of those objects." << endl;
}

/*
    This function (convertLow) does the following:
    Purpose: Converts a string to lowercase.
*/
void convertLow(string &solution) {
    // Changing solution to all lowercase.
    for (int i = 0; solution[i] != '\0'; ++i) {
        solution[i] = tolower(solution[i]);
    }
}

/*
    This function (promptSol) does the following:
    Purpose: Asks the user what method they want to utilize: iterative or recursive.
*/
string promptSol() {

    // Asking the user.
    string solution;
    cout << "\nWould you like to use the recursive solution or iterative solution to calculate the area of these objects? (Enter recursive/iterative, or 'quit' to stop the program)" << endl;
    cin >> solution;
    return solution;
}

/*
    This function (calcAreaStk) does the following:
    Purpose: Iterative function meant for calculating the area of an object using a stack.
    
    Function written by: Daniel Wong
    Debugged by: Ben Hung
*/
int calcAreaStk(int i, int j, Matrix& list) {

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

        if (!list.outOfBounds(currentItm.i+1, currentItm.j) && 
            list.getPosition(currentItm.i+1, currentItm.j) != '0' && 
            list.getPosition(currentItm.i+1, currentItm.j) != 'x' && 
            list.getPosition(currentItm.i+1, currentItm.j) != '*') {

            list.setPosition(currentItm.i, currentItm.j, '*');
            newObject.i = currentItm.i+1;
            newObject.j = currentItm.j;
            stack.push(newObject);

            // Changing current position.
            currentItm.i += 1;
        }
        else if (!list.outOfBounds(currentItm.i-1, currentItm.j) &&
            list.getPosition(currentItm.i-1, currentItm.j) != '0' && 
            list.getPosition(currentItm.i-1, currentItm.j) != 'x' && 
            list.getPosition(currentItm.i-1, currentItm.j) != '*') {

            list.setPosition(currentItm.i, currentItm.j, '*');
            newObject.i = currentItm.i-1;
            newObject.j = currentItm.j;
            stack.push(newObject);

            // Changing current position.
            currentItm.i -= 1;
        }
        else if (!list.outOfBounds(currentItm.i, currentItm.j+1) && 
            list.getPosition(currentItm.i, currentItm.j+1) != '0' && 
            list.getPosition(currentItm.i, currentItm.j+1) != 'x' && 
            list.getPosition(currentItm.i, currentItm.j+1) != '*') {

            list.setPosition(currentItm.i, currentItm.j, '*');
            newObject.i = currentItm.i;
            newObject.j = currentItm.j+1;
            stack.push(newObject);

            // Changing current position.
            currentItm.j += 1;
        }
        else if (!list.outOfBounds(currentItm.i, currentItm.j-1) && 
            list.getPosition(currentItm.i, currentItm.j-1) != '0' && 
            list.getPosition(currentItm.i, currentItm.j-1) != 'x' && 
            list.getPosition(currentItm.i, currentItm.j-1) != '*') {

            list.setPosition(currentItm.i, currentItm.j, '*');
            newObject.i = currentItm.i;
            newObject.j = currentItm.j-1;
            stack.push(newObject);

            // Changing current position.
            currentItm.j -= 1;
        }

        while (list.checkEnd(currentItm.i, currentItm.j) && 
            !stack.isEmpty()) {

            Coords poppedItem = stack.pop();
        
            // Setting position to 'x' after popping it from the stack.
            list.setPosition(poppedItem.i, poppedItem.j, 'x');

            if (!stack.isEmpty()) {
                Coords temp = stack.peek();
                currentItm.i = temp.i;
                currentItm.j = temp.j;
            }
            area += 1;
        }
    }

    // Checking if area is just one object; then adding area.
    if (list.checkEnd(i, j) && 
        stack.getLength() == 1 && 
        list.getPosition(i, j) != '0' && 
        list.getPosition(i, j) != 'x') {

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
int calcArea(int i, int j, Matrix& list) {
    
    // Initializing the area variable.
    int area;
    
    // Don't run the program if i or j are negative or above the max number of rows/cols.
    if (i < 0 || j < 0 || 
        i > list.getRows()-1 || 
        j > list.getCols()-1) {

        area = 0;
    }
    // Checking if object is nonzero.
    else if (list.getPosition(i, j) != '0' && 
        list.getPosition(i, j) != 'x') {

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

/*
    This function (iterativeSolution) does the following:
    Purpose: Iterating through all the characters in the Matrix object, then calling the calcAreaStk() function on each.
*/
void iterativeSolution(Matrix& list) {
    
    // Getting the number of max rows/cols from the Matrix class.
    int rows = list.getRows();
    int cols = list.getCols();

    // Initializing several variables.
    int area = 0;
    vector<int> areas;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {

            // Checking that the object is non-zero before calling the calcAreaStk() function.
            if (list.getPosition(i, j) != '0' || 
                list.getPosition(i, j) != 'x') {
                
                area = calcAreaStk(i, j, list);
            }

            // Adding the area found to a vector if not 0.
            if (area != 0) {
                areas.push_back(area);
            }
        }
    }

    // Printing out the objects and their areas.
    cout << endl;
    for (int i = 0; i < areas.size(); i++) {
        cout << "Object " << i+1 << ": " << areas.at(i) << " squares" << endl;
    }
    if (areas.size() == 0) {
        cout << "No objects have been found!" << endl;
    }
}

/*
    This function (recursiveSolution) does the following:
    Purpose: Iterating through all the characters in the Matrix object, then calling the calcArea() function on each.
*/
void recursiveSolution(Matrix& list) {

    // Getting the number of max rows/cols from the Matrix class.
    int rows = list.getRows();
    int cols = list.getCols();

    // Initializing several variables.
    int area = 0;
    vector<int> areas;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            area = calcArea(i, j, list);
            // Adding the area found to a vector if not 0.
            if (area != 0) {
                areas.push_back(area);
            }
        }
    }

    // Printing out the objects and their areas.
    cout << endl;
    for (int i = 0; i < areas.size(); i++) {
        cout << "Object " << i+1 << ": " << areas.at(i) << " squares" << endl;
    }
    if (areas.size() == 0) {
        cout << "No objects have been found!" << endl;
    }
}

/*
    This function (readInputFile) does the following:
    Purpose: Reads the filename that the user inputs and calls the Matrix list readList() on the file.
*/
Matrix readInputFile() {

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

    return list;
}