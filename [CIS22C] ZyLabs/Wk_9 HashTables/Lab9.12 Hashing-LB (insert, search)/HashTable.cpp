// Implementation file for the Hash class
// Written By: A. Student
// Changed by: Daniel Wong

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
        if (hashAry[bucket].getOccupied() != 1) { //check if bucket contains value
            hashAry[bucket] = itemIn;
            hashAry[bucket].setOccupied(1);
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
*~**/

bool HashTable::remove(Student &itemOut)
{
    return false;
}

/*~*~*~*
   hash search - linear probe
   search for key
   if found:
      - copy data to itemOut
      - copy number of collisions for this key to noCol
      - returns true
   if not found, returns false
*~**/
bool HashTable::search(Student &itemOut, int &noCol, string key)
{
   /* write your code here */
    int bucket = _hash(key);
    int buckets_probed = 0;

    while (hashAry[bucket].getOccupied() != 0 && buckets_probed < hashSize) {
        //Insert item in next empty bucket
        if (hashAry[bucket].getItem().getName() == key) {
            itemOut = hashAry[bucket].getItem();
            noCol = buckets_probed;
            return true;
        }

        //Increment Bucket Index
        bucket = (bucket + 1) % hashSize;

        //Increment number of buckets probed
        ++buckets_probed;
    }

    return false;
}
