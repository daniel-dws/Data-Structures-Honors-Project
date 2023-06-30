#ifndef MATRIX_H
#define MATRIX_H

#include <string>
using std::string;

/*
    Implementation file for the Matrix class.
    
    Written by: Daniel Wong
    Debugged by: Ben Hung
*/

class Matrix {
    private:
        // dynamic memory allocation, no reading in chars
        char **list = nullptr;

        // Initializing the number of rows and columns.
        int rows;
        int cols;

    public:
        // Defining and declaring the default and overloaded constructors.
        Matrix() { rows = 0; cols = 0; }
        Matrix(int rows, int cols);

        // Declaring the destructor for the Matrix class.
        ~Matrix();

        // Setter function for position.
        void setPosition(int i, int j, char val) { list[i][j] = val; }

        // Getter functions for position, rows, and cols.
        char getPosition(int i, int j) { return list[i][j]; }
        int getRows() { return rows; }
        int getCols() { return cols; }
        

        // Defining the outOfBounds() function that checks whether coordinates are not in the scope of the list.
        bool outOfBounds(int i, int j) {
            return (i < 0 || i >= rows || j < 0 || j >= cols);
        }

        // Defining other public member functions of the Matrix class.
        void readList(string fileName);
        bool checkEnd(int i, int j);
};


#endif