/* *~*~*
  Specification file for the Customer class
  Written By: A. Student
  Changed by: Daniel Wong
  IDE: xCode
  *~**/

#ifndef CUSTOMER_H_
#define CUSTOMER_H_

using std::string;

class  Customer; // Forward Declaration

// Function Prototypes for friend functions
/* Write your code here */
int calcSerial(const Customer& customer);
int compareSerial(const Customer&, const Customer &);

class Customer
{
private:
    int year;
    int mileage;
    int seq;
     string name;
    
public:
   /* Write your code here */
    Customer();
    Customer(int, int, int, string);
    
    //Define setters
    void setYear(int yr) {year = yr;}
    void setMileage(int ml) {mileage = ml;}
    void setSeq(int sq) {seq = sq;}
    void setName(string nm) {name = nm;}
    
    //Define getters
    int getYear() {return year;}
    int getMileage() {return mileage;}
    int getSeq() {return seq;}
    string getName() {return name;}
    
    //Define overloaded operators
    
    
    //Define friend functions
    friend int calcSerial(const Customer& customer);
    friend int compareSerial(const Customer &, const Customer &);

};

#endif
