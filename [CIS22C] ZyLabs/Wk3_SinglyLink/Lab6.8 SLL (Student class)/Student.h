// Specification file for the Student class
// Written by: Daniel Wong
// Reviewed & Modified by: Daniel Wong
// IDE: ZyBooks

#ifndef STUDENT_H
#define STUDENT_H

//using namespace std;  //<==== This statement
// in a header file of a complex project could create
// namespace management problems for the entire project
// (such as name collisions).
// Do not write namespace using statements at the top level in a header file!

using std::string;

class Student
{
private:
/* Write your code here: gpa - a double, name - a string */
   double gpa;
   string name;
    
public:
    /* Write your code here: default and overloaded constructors  */
    Student() {name = ""; gpa = -1;} //Constructor
    Student(double g, string n)  {name = n; gpa = g;} //Overloaded Constructor
    
    
    // Setters and getters
    /* Write your code here: a setter and a getter for each data member of the class  */
    void setName(string n) {name = n;}
    void setGpa(double g) {gpa = g;}
    string getName() const {return name;}
    double getGpa() const {return gpa;}
    
};
#endif
