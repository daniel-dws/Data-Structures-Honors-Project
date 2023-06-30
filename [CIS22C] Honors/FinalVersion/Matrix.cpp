#include "Matrix.h"
#include <string>
using std::string;
#include <iomanip>
#include <fstream>
#include <iostream>

// Defining the overloaded constructor for the Matrix class.
Matrix::Matrix(int rows, int cols) {

    // Setting the private variables rows and cols equal to the parameters passed in.
    this->rows = rows;
    this->cols = cols;
    
    // Dynamically allocating the list.
    list = new char*[rows];
    for (int i = 0; i < rows; i++) {
        list[i] = new char[cols];
    }
}

// Defining the destructor for the Matrix class.
Matrix::~Matrix() {
    for (int i = 0; i < rows; i++) {
        delete[] list[i];
    }
    delete[] list;
}

// Defining the readList() function of the Matrix class, which reads objects into the dynamically allocated list.
void Matrix::readList(string fileName) {

    std::ifstream inputFile;
    inputFile.open(fileName.c_str());

    // Validating the file.
    if(inputFile.fail()){
        std::cout << "Error opening " << fileName << " for reading." << std::endl;
        exit(EXIT_FAILURE);
    }

    // Skip first line of file, as that's already been read.
    string dump;
    getline(inputFile, dump);

    // Reading the objects to the list.
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            inputFile >> list[i][j];
        }
    }
}

// Defining the checkEnd() function to check if surrounding areas are empty.
bool Matrix::checkEnd(int i, int j) {
    if (!outOfBounds(i, j) && (list[i][j] == '0' || list[i][j] == 'x')) {
        return true;
    }
    if (!outOfBounds(i+1, j) && list[i+1][j] != '0' && list[i+1][j] != 'x' && list[i+1][j] != '*') {
        return false;
    }
    if (!outOfBounds(i-1, j) && list[i-1][j] != '0' && list[i-1][j] != 'x' && list[i-1][j] != '*') {
        return false;
    }
    if (!outOfBounds(i, j+1) && list[i][j+1] != '0' && list[i][j+1] != 'x' && list[i][j+1] != '*') {
        return false;
    }
    if (!outOfBounds(i, j-1) && list[i][j-1] != '0' && list[i][j-1] != 'x' && list[i][j-1] != '*') {
        return false;
    }
    return true;
}