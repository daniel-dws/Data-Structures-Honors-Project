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

//Function Declarations
int calcArea(int i, int j, Matrix list);

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

    // Vector to keep track of number of areas as well as the number of objects in an area.
    vector<int> areas;
    
    // Iterating through all the characters in the Matrix object, then calling the calcArea() function on each.
    int area = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            area = calcArea(i, j, list);
            // Adding the area found to a vector if not 0.
            if (area != 0) {
                areas.push_back(area);
            }
        }
    }

    // Printing out the areas and objects.
    cout << endl;
    for (int i = 0; i < areas.size(); i++) {
        cout << "Object " << i << ": " << areas.at(i) << " squares." << endl;
    }

    return 0;
}

/*
    This function (calcArea) does the following:
    Purpose: Recursive function meant for calculating the area of a object.
    
    Function written by: Ben Hung
     Debugged by: Daniel Wong
*/
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