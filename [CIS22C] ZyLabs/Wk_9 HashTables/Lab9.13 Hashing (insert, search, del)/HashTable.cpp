// Implementation file for the Hash class
// Written By: A. Student
// Reviewed & Modified by: Daniel Wong

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
    if (count == hashSize) //exits when all buckets are full
        return false;
   /* write your code here */
    int buckets_probed = 0;
    int bucket = _hash(itemIn.getName()); //hash code for buckets
    
    while (buckets_probed < hashSize) { //insert while buckets are not all full
        //Insert item in next empty bucket
        if (hashAry[bucket].getItem().getName() == itemIn.getName()) {
            return false;
        }
        else if (hashAry[bucket].getOccupied() != 1) { //check if bucket contains value
            hashAry[bucket] = itemIn;
            hashAry[bucket].setOccupied(1);
            hashAry[bucket].setNoCollisions(buckets_probed);
            count++;
            return true;
        }

        //Increment Bucket Index
        bucket = (bucket + 1) % hashSize; //increment to following bucket

        //Increment number of buckets probed
        ++buckets_probed;
    }
    return false;
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
    int bucket = _hash(key);
    int buckets_probed = 0;
    Student tempStudent;
    
    while (buckets_probed < hashSize) {
        if (hashAry[bucket].getOccupied() != 0 && hashAry[bucket].getItem().getName() == key) {
            itemOut = hashAry[bucket].getItem();
            hashAry[bucket].setItem(tempStudent);
            hashAry[bucket].setOccupied(0); //EmptyAfterRemoval
            hashAry[bucket].setNoCollisions(0);
            count--;
            return true;
        }

        //Increment Bucket Index
        bucket = (bucket + 1) % hashSize;

        //Increment number of buckets probed
        ++buckets_probed;
    }
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
     int bucket = _hash(key);
     int buckets_probed = 0;

     while (buckets_probed < hashSize) {
         //Insert item in next empty bucket
         if (hashAry[bucket].getOccupied() != 0  && hashAry[bucket].getItem().getName() == key) {
             int noCol = buckets_probed;
             itemOut = hashAry[bucket].getItem();
             return noCol;
         }

         //Increment Bucket Index
         bucket = (bucket + 1) % hashSize;

         //Increment number of buckets probed
         ++buckets_probed;
     }

    return -1;
}
