// Implementation file for the Hash class
// Written By: A. Student
// Reviewed & Modified by: <Write your name here>

#include <string>

#include "HashTable.h"

using namespace std;

/*~*~*~*
  A simple hash function 
 *~**/
int HashTable::_hash(string key) const
{
    int sum = 0;
    for (int i = 0; key[i]; i++)
        sum += key[i];
    return sum % hashSize;
};

/*~*~*~*
  hash insert - linear probe
     - returns false if the hash table is full
     - returns true if itemIn is inserted into the hash table
*~**/
bool HashTable::insert(const Student &itemIn)
{
    if ( count == hashSize)
        return false;
    /* write your code here */
   
    return true;
}

/*~*~*~*
   hash delete - linear probe
   - looks for key in hash table
   - if found:
       - copies its data to itemOut 
       - replaces data in the hash node with an "empty" record
       - returns true
   - if not found - returns false
*~**/
bool HashTable::remove(Student &itemOut, string key)
{
    /* Write your code here */
    
    return false;
}

/*~*~*~*
   hash search - linear probe
   if found: 
      - copy data to itemOut
      - returns the number of collisions for this key 
   if not found, returns -1
*~**/
int HashTable::search(Student &itemOut, string key) const
{
   /* write your code here */
     
    return -1;
}
