// Specification file for the Hash class
// Written By: A. Student
// Changed by: Daniel Wong

#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include "HashNode.h"

template<class ItemType>
class HashTable
{
private:
	HashNode<ItemType>* hashAry;
	int hashSize;
    int count;
	
public:
	HashTable() { count = 0; hashSize = 53; hashAry = new HashNode<ItemType>[hashSize]; }
	HashTable(int n)	{ count = 0; hashSize = n;	hashAry = new HashNode<ItemType>[hashSize]; }
	~HashTable(){ delete [] hashAry; }

	int getCount() const	{ return count; }
    int getSize() const { return hashSize; }
    double getLoadFactor() const {return 100.0 * count / hashSize; }
    bool isEmpty() const	{ return count == 0; }
    bool isFull()  const	{ return count == hashSize; }
    
    bool insert(const ItemType &itemIn, int h(const ItemType &key, int size) );
    bool remove(ItemType &itemOut, const ItemType &key, int h(const ItemType &key, int size));
    int  search(ItemType &itemOut, const ItemType &key, int h(const ItemType &key, int size)) const;
};

/*~*~*~*
   Insert an item into the hash table
   It does not reject duplicates
*~**/
template<class ItemType>
bool HashTable<ItemType>::insert( const ItemType &itemIn, int h(const ItemType &key, int size) )
{
    if ( count == hashSize)
        return false;
    
    /* write your code here */
     int buckets_probed = 0;
     int bucket = h(itemIn, hashSize); //hash code for buckets

     while (buckets_probed < hashSize) {
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
   Removes the item with the matching key from the hash table
   if found:
     - copies data in the hash node to itemOut
     - replaces data in the hash node with an empty record (occupied = -1: deleted!)
     - returns true
   if not found:
     - returns false
*~**/
template<class ItemType>
bool HashTable<ItemType>::remove( ItemType &itemOut, const ItemType &key, int h(const ItemType &key, int size))
{
    /* Write your code here */
    int bucket = h(key, hashSize);
    int buckets_probed = 0;
    ItemType tempStudent;
    
    while (buckets_probed < hashSize) {
        //Check if bucket is occupied and if bucket already contains same name
        if (hashAry[bucket].getOccupied() != 0 && hashAry[bucket].getItem().getName() == key.getName()) {
            itemOut = hashAry[bucket].getItem();
            hashAry[bucket].setItem(tempStudent);
            hashAry[bucket].setOccupied(0); //Set EmptyAfterRemoval
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
template<class ItemType>
int HashTable<ItemType>::search(ItemType &itemOut, const ItemType &key, int h(const ItemType &key, int size)) const
{
    /* write your code here */
     int bucket = h(key, hashSize);
     int buckets_probed = 0;

     while (buckets_probed < hashSize) {
         //Insert item in next empty bucket
         if (hashAry[bucket].getOccupied() != 0  && hashAry[bucket].getItem().getName() == key.getName()) {
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

#endif // HASHTABLE_H_
