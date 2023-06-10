// Specification file for the Student class
// Modified by: Daniel Wong
// IDE: xCode

#ifndef STUDENT_H
#define STUDENT_H

using std::string;

class Student; // Forward Declaration

// Function Prototypes for friend functions
/* Write your code here */
int key_to_index(const Student &key, int size);

class Student
{
private:
    double gpa;
    string name;
    
public:
    Student() {name = ""; gpa = -1;}  // Constructor
    Student(string n, double g) {name = n; gpa = g;}  // Overloaded Constructor
    
    // Setters and getters
    void setName(string n) {name = n;}
    void setGpa(double g) {gpa = g;}
    string getName() const {return name;}
    double getGpa() const {return gpa;}
    
    // Overloaded operators
    /* Write your code here */
    bool operator == (const Student &right) {return (name == right.name);}  // Overloaded ==
    
    // friend functions
    /* Write your code here */
    friend int key_to_index();
};
#endif
