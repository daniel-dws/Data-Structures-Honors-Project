/*
  Heaps - ADT

  This program will read data about overbooked customers,
  find their priority and serial numbers, build a heap, then display
  customers in priority sequence
 
  Written By: A. Student
  Changed By: Daniel Wong
  IDE: xCode
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cctype>
#include <sstream>
#include "Customer.h"
#include "Heap.h"

using namespace std;

/* Write your code here */
//Declarations
void buildHeap(const string &filename, Heap<Customer> &);

int main()
{
    // Get input file name
    string inputFileName;
    cout << "Input file name: ";
    getline(cin, inputFileName);
    cout << endl;
    
    /* Write your code here */
    Heap<Customer> heap;
    
    buildHeap(inputFileName, heap);

    return 0;
}

/* Write your code here */
void buildHeap(const string& filename, Heap<Customer> & heap)
{
    //File open
    ifstream inputFile(filename);
    
    if (!inputFile)
    {
        cout << "Error opening the input file: \"" << filename << "\"" << endl;
        exit(EXIT_FAILURE);
    }
    
    //Store Data
    Customer tempCustomer;
    string line;
    int seq = 0, served = 0, rejected = 0;
    
    while (getline(inputFile, line))
    {
        //Declare
        char action;
        int year, mileage;
        string name;
        
        stringstream temp(line);
        temp >> action;
        
        if (action == 'A')
        {
            temp >> year;
            temp >> mileage;
            
            temp.ignore();
            getline(temp, name, ':');
            temp.ignore();
            
            seq++;
            Customer aCustomer(year, mileage, seq, name);
            heap.insertHeap(aCustomer, compareSerial);
        }
        
        if (action == 'S')
        {
            heap.deleteHeap(tempCustomer, compareSerial);
            
            int serial = calcSerial(tempCustomer);
            served++;
            
            cout << tempCustomer.getYear() << " ";
            cout << tempCustomer.getMileage() << " ";
            cout << "(" << serial << ") ";
            cout << "[" << tempCustomer.getName() << "]" << endl;
        }
     }
    
    cout << "Served overbooked customers: " << served << endl;
    cout << endl;
    
    while (!heap.isEmpty())
    {
        heap.deleteHeap(tempCustomer, compareSerial);
        
        int serial = calcSerial(tempCustomer);
        rejected++;
        
        cout << tempCustomer.getYear() << " ";
        cout << tempCustomer.getMileage() << " ";
        cout << "(" << serial << ") ";
        cout << "[" << tempCustomer.getName() << "]" << endl;
    }
    
    cout << "Rejected overbooked customers: " << rejected << endl;
    
    inputFile.close();
}

