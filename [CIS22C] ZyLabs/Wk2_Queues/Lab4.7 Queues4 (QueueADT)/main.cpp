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

#include "QueueADT.h"

using namespace std;


int main()
{
    // Create the first queue (strings)
    //Objects are declared;
    Queue<string> studentNames;
    Queue<double> studentUnits;
    
    string item = "";
    double units = 0.0;

    // Write a loop to enter an unknown number of names, one per line.
    // The loop stops when you enter #.
    // As you are entering names, they are to be inserted into the first queue.
    //Push items
    while(getline(cin, item) && item != "#")
    {
        studentNames.push(item);
    }
    
    if (studentNames.isEmpty()) {
        cout << "Empty Queues!" << endl;
    }
    
    else {
        // Test the getLength function: - display the number of elements in the first queue
        cout << studentNames.getLength() << " "; //Student getLength

        // Create the second queue (doubles)
        // Test the getLength function: - display the number of elements in the second queue
                                     // (it should be 0!)
        cout << studentUnits.getLength() << endl; //Units getLength
        
        int queueLength = studentNames.getLength();
        // Write another loop to enter the number of units (double) into a parallel queue.
        for (int i = 0; i < queueLength; i++){
            cin >> units;
            studentUnits.push(units);
        }
            
        // Display the two queues in parallel.
        for (int i = 0; i < queueLength; i++) {
            string tempName;
            double tempUnits;
            
            tempName = studentNames.pop();
            tempUnits = studentUnits.pop();
            
            cout << tempName << " ";
            cout << tempUnits << endl;
            
            studentNames.push(tempName);
            studentUnits.push(tempUnits);
        }

        // On the next line display the front and rear elements in the first queue.
        cout << "Front of the queues: " << studentNames.peek() << " " << studentUnits.peek() << endl;
        cout << "Rear of the queues: "  << studentNames.peekRear() << " " << studentUnits.peekRear() << endl;
    }
    return 0;
}
