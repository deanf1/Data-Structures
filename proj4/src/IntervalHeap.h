/******************************************************************************
 ** File:    IntervalHeap.h
 ** Project: CMSC 341 Project 4, Spring 2015
 ** Author:  Dean Fleming
 ** Date:    4/1/15
 ** Section: 02
 ** E-mail:  deanf1@umbc.edu
 **
 ** This is the header file for an interval heap data structure.
 ** An interval heap is a double-ended priority queue that permits us to
 ** delete from either the min or max end.
 **
 ** Some of this code was taken from Blackboard and was not written by me.
 **
 *****************************************************************************/

#ifndef INTERVAL_HEAP_H
#define INTERVAL_HEAP_H

#include <cstdlib>
#include <iostream>

using namespace std;

class LeftRightElements 
{
	public:
		int left;
		int right;
};

class IntervalHeap
{
	private:
		int currentSize;			// total # of elements in the interval heap
		LeftRightElements *heap;	// array to maintain heap structure
		int min;					// provided with make run command
		int max;					// provided with make run command
		int inputSize;				// provided with make run command
		int seed;					// provided with make run command

	public:
		IntervalHeap(int min, int max, int size, int seed);
		~IntervalHeap();
		int getMin();
		int getMax();
		int getSize();
		void insertRandomNumbers();
		void insert(int element);
		void insertAsMinHeap(int n);
		void insertAsMaxHeap(int n);
		void swapLeftAndRightElements(int index);
		void deleteMinMaxIteratively(ostream &out = cout);
		void deleteMin();
		void deleteMax();
		void checkForNeededSwaps();
		void printIntervalHeap(ostream &out = cout);
};

#endif