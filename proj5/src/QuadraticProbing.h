/******************************************************************************
 ** File:    QuadraticProbing.h
 ** Project: CMSC 341 Project 5, Spring 2015
 ** Author:  Dean Fleming
 ** Date:    4/23/15
 ** Section: 02
 ** E-mail:  deanf1@umbc.edu
 **
 ** This is the header file for a hash table data structure.
 ** All of this code is from Blackboard, except for these methods I wrote:
 ** 	- printHash
 ** 	- sizeOfIntersection
 ** 	- sizeOfUnion
 ** 	- quickSort
 **
 *****************************************************************************/
 
#ifndef QUADRATIC_PROBING_H
#define QUADRATIC_PROBING_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int nextPrime( int n );

// QuadraticProbing Hash table class
//
// CONSTRUCTION: an approximate initial size or default of 101
//
// ******************PUBLIC OPERATIONS*********************
// bool insert( x )       --> Insert x
// bool remove( x )       --> Remove x
// bool contains( x )     --> Return true if x is present
// void makeEmpty( )      --> Remove all items
// int hash( string str ) --> Global method to hash strings

template <typename HashedObj>
class HashTable
{
  public:
  
	enum EntryType { ACTIVE, EMPTY, DELETED };
	
	struct HashEntry
    {
        HashedObj element;
        EntryType info;

        HashEntry( const HashedObj & e = HashedObj( ), EntryType i = EMPTY )
          : element( e ), info( i ) { }
    };
	
    explicit HashTable( int size = 101 ) : array( nextPrime( size ) )
      { makeEmpty( ); }

    bool contains( const HashedObj & x ) const
    {
        return isActive( findPos( x ) );
    }

    void makeEmpty( )
    {
        currentSize = 0;
        for( unsigned int i = 0; i < array.size( ); i++ )
            array[ i ].info = EMPTY;
    }

    bool insert( const HashedObj & x )
    {
            // Insert x as active
        int currentPos = findPos( x );
        if( isActive( currentPos ) )
            return false;

        array[ currentPos ] = HashEntry( x, ACTIVE );

            // Rehash; see Section 5.5
        if( ++currentSize > array.size( ) / 2 )
            rehash( );

        return true;
    }

    bool remove( const HashedObj & x )
    {
        int currentPos = findPos( x );
        if( !isActive( currentPos ) )
            return false;

        array[ currentPos ].info = DELETED;
        return true;
    }
	
	// prints out the whole hash table
	void printHash(ostream &out = cout)
	{
		out << "Size: " << array.size() << endl;
		for (unsigned int i = 0; i < array.size(); i++)
		{
			out << array[i].element << endl;
		}
		out << endl;
	}
	
	// finds the number of elements in the intersection of this hash table and another
	int sizeOfIntersection(HashTable<HashedObj> otherTable)
	{
		vector<HashedObj> interVec;
		
		// sorts and compacts the hash tables
		vector<HashedObj> sortedArray = quickSort();
		vector<HashedObj> otherSortedArray = otherTable.quickSort();
		
		// finds the intersection set (based on the how STL implementation works)
		unsigned int i = 0; unsigned int j = 0;
		while (i != sortedArray.size() && j != otherSortedArray.size())
		{
			if (sortedArray[i] < otherSortedArray[j])
			{
				i++;
			}
			else if (otherSortedArray[j] < sortedArray[i])
			{
				j++;
			}
			else
			{
				interVec.push_back(sortedArray[i]);
				
				i++; j++;
			}
		}
		
		return interVec.size();
	}
	
	// finds the number of elements in the union of this hash table and another
	int sizeOfUnion(HashTable<HashedObj> otherTable)
	{
		vector<HashedObj> unionVec;
		
		// sorts and compacts the hash tables
		vector<HashedObj> sortedArray = quickSort();
		vector<HashedObj> otherSortedArray = otherTable.quickSort();
		
		// finds the union set (based on how the STL implementation works)
		unsigned int i = 0; unsigned int j = 0;
		while (true)
		{
			if (i == sortedArray.size())
			{
				for (unsigned int k = j; k < otherSortedArray.size(); k++)
				{
					unionVec.push_back(otherSortedArray[k]);
				}
				break;
			}
			if (j == otherSortedArray.size())
			{
				for (unsigned int k = i; k < otherSortedArray.size(); k++)
				{
					unionVec.push_back(sortedArray[k]);
				}
				break;
			}
			
			if (sortedArray[i] < otherSortedArray[j])
			{
				unionVec.push_back(sortedArray[i]);
				
				i++;
			}
			else if (otherSortedArray[j] < sortedArray[i])
			{
				unionVec.push_back(otherSortedArray[j]);
				
				j++;
			}
			else
			{
				unionVec.push_back(sortedArray[i]);
				
				i++; j++;
			}
		}
		
		return unionVec.size();
	}
	
	// bootstrap for quick sort 
	// Also compress the hash table (vector<HashEntry) to vector<HashedObj> 
	// and removes blanks
	vector<HashedObj> quickSort()
	{
		quickSort(0, array.size() - 1);
		
		// compacts the hash to just active elements
		vector<HashedObj> newVec;
		for (unsigned int i = 0; i < array.size(); i++)
		{
			if (array[i].info == ACTIVE)
			{
				newVec.push_back(array[i].element);
			}
		}
		
		return newVec;
	}
	
	// does a quick sort on the hash table
	void quickSort(int left, int right)
	{
      int i = left, j = right;
      HashEntry tmp;
      HashedObj pivot = array[(left + right) / 2].element;
 
      while (i <= j) {
            while (array[i].element < pivot)
                  i++;
            while (array[j].element > pivot)
                  j--;
            if (i <= j) {
                  tmp = array[i];
                  array[i] = array[j];
                  array[j] = tmp;
                  i++;
                  j--;
            }
      };
 
      if (left < j)
            quickSort(left, j);
      if (i < right)
            quickSort(i, right);
	}

  private:
    
    vector<HashEntry> array;
    unsigned int currentSize;

    bool isActive( int currentPos ) const
      { return array[ currentPos ].info == ACTIVE; }

    int findPos( const HashedObj & x ) const
    {
        int offset = 1;
        unsigned int currentPos = myhash( x );

          // Assuming table is half-empty, and table length is prime,
          // this loop terminates
        while( array[ currentPos ].info != EMPTY &&
                array[ currentPos ].element != x )
        {
            currentPos += offset;  // Compute ith probe
            offset += 2;
            if( currentPos >= array.size( ) )
                currentPos -= array.size( );
        }

        return currentPos;
    }

    void rehash( )
    {
        vector<HashEntry> oldArray = array;

            // Create new double-sized, empty table
        array.resize( nextPrime( 2 * oldArray.size( ) ) );
        for( unsigned int j = 0; j < array.size( ); j++ )
            array[ j ].info = EMPTY;

            // Copy table over
        currentSize = 0;
        for( unsigned int i = 0; i < oldArray.size( ); i++ )
            if( oldArray[ i ].info == ACTIVE )
                insert( oldArray[ i ].element );
    }
    int myhash( const HashedObj & x ) const
    {
        int hashVal = hash( x );

        hashVal %= array.size( );
        if( hashVal < 0 )
            hashVal += array.size( );

        return hashVal;
    }
};

int hash( const string & key );
int hash( int key );

#endif
