#ifndef MATRIX_H
#define MATRIX_H

#include <string>
using std::string;
#include <iomanip>
#include <fstream>


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
        // Defining the default and overloaded constructors.
        Matrix() { rows = 0; cols = 0; }
        Matrix(int rows, int cols) {

            // Setting the private variables rows and cols equal to the parameters passed in.
            this->rows = rows;
            this->cols = cols;
            
            // Dynamically allocating the list.
            list = new char*[rows];
            for (int i = 0; i < rows; i++) {
                list[i] = new char[cols];
            }
        }
        
        // Defining the readList() function of the Matrix class, which reads objects into the dynamically allocated list.
        void readList(string fileName) {

            ifstream inputFile;
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

        // Setter function for position.
        void setPosition(int i, int j, char val) { list[i][j] = val; }

        // Getter functions for position, rows, and cols.
        char getPosition(int i, int j) { return list[i][j]; }
        int getRows() { return rows; }
        int getCols() { return cols; }

        // Function to print the list, for debugging purposes.
        void printList() {
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    cout << list[i][j];
                }
                cout << endl;
            }
        }

};

#endif