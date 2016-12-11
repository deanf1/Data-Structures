/******************************************************************************
 ** File:    IntervalHeap.cpp
 ** Project: CMSC 341 Project 4, Spring 2015
 ** Author:  Dean Fleming
 ** Date:    4/1/15
 ** Section: 02
 ** E-mail:  deanf1@umbc.edu
 **
 ** This is the source file for an interval heap data structure.
 ** An interval heap is a double-ended priority queue that permits us to
 ** delete from either the min or max end.
 **
 ** The function headers and their comment descriptions were taken from 
 ** Blackboard and were not written by me.
 **
 *****************************************************************************/
 
#include "IntervalHeap.h"

// Constructor
IntervalHeap::IntervalHeap(int aMin, int aMax, int aInputSize, int aSeed)
{
	currentSize = 0;
	min = aMin;
	max = aMax;
	inputSize = aInputSize;
	seed = aSeed;
	
	// sets the size of the heap to the input size plus 50%
	heap = new LeftRightElements[inputSize + (inputSize / 2)];
	
	// sets an empty value for index 0 since heaps start at index 1
	heap[0] = LeftRightElements();
	
	// sets the random number generator seed
	srand(seed);
}

// Destructor
IntervalHeap::~IntervalHeap()
{
	delete[] heap;
	heap = NULL;
}

// returns min from interval heap
int IntervalHeap::getMin()
{
	return heap[1].left;
}

// returns max from interval heap
int IntervalHeap::getMax()
{
	return heap[1].right;
}

// returns total number of elements in the interval heap 
int IntervalHeap::getSize()
{
	int size = 0;
	for (int i = 1; i <= currentSize; i++)
	{
		if (heap[i].left)
		{
			size++;
		}
		if (heap[i].right)
		{
			size++;
		}
	}
	return size;
}

// method that generates random numbers and inserts them in the interval heap
void IntervalHeap::insertRandomNumbers()
{
	for (int i = 0; i < inputSize; i++)
	{
		int random = (rand() % (max - min)) + min;
		insert(random);
	}
}

// method that inserts an element into the interval heap
void IntervalHeap::insert(int n)
{
	
	// if there are odd number of elements
	if ((getSize() % 2) == 1)
	{
		if (n < heap[currentSize].left)
		{
			swapLeftAndRightElements(currentSize);
			--currentSize;	// correcting for when insert tries to add one
			insertAsMinHeap(n);
		}	
		else
		{
			--currentSize;	// correcting for when insert tries to add one
			insertAsMaxHeap(n);
		}
	}
	
	// if there are even number of elements
	else
	{
		// if there are an odd number of nodes
		if ((currentSize % 2) == 1)
		{
			if (n <= heap[(currentSize + 1) / 2].left)
			{
				insertAsMinHeap(n);
			}
			else
			{
				insertAsMaxHeap(n);
				swapLeftAndRightElements(currentSize);
			}
		}
		
		// if there is an even number of nodes
		else
		{
			if (n <= heap[currentSize / 2].left)
			{
				insertAsMinHeap(n);
			}
			else
			{
				insertAsMaxHeap(n);
				swapLeftAndRightElements(currentSize);
			}
		}
	}
}

// inserts a value in the left elements as if it were a min heap
void IntervalHeap::insertAsMinHeap(int n)
{
	int hole = ++currentSize;
	for ( ; hole > 1 && n < heap[hole / 2].left; hole /= 2)
	{
		heap[hole].left = heap[hole / 2].left;
	}
	heap[hole].left = n;
}

// inserts a value in the right elements as if it were a max heap
void IntervalHeap::insertAsMaxHeap(int n)
{
	int hole = ++currentSize;
	for ( ; hole > 1 && n > heap[hole / 2].right; hole /= 2)
	{
		heap[hole].right = heap[hole / 2].right;
	}
	heap[hole].right = n;
}

// swaps the left and right elements of a node in the heap
void IntervalHeap::swapLeftAndRightElements(int index)
{
	int temp = heap[index].left;
	heap[index].left = heap[index].right;
	heap[index].right = temp;
}

// method that deletes min and max iteratively until just one element is left
void IntervalHeap::deleteMinMaxIteratively(ostream &out)
{
	int numOfTimes = getSize() - 1;
	for (int i = 0; i < numOfTimes; i++)
	{
		out << "After deleting min element " << getMin() << ":" << endl << endl;
		deleteMin();
		printIntervalHeap(out);
		
		--numOfTimes;
		
		if (getSize() > 1)
		{
			out << "After deleting max element " << getMax() << ":" << endl << endl;
			deleteMax();
			printIntervalHeap(out);
		}
	}
}

// method that deletes min from the interval heap
void IntervalHeap::deleteMin()
{
	
	// moves last element to root
	if ((getSize() % 2) == 0)
	{
		heap[1].left = heap[currentSize].right;
		heap[currentSize].right = 0;
	}
	else
	{	
		heap[1].left = heap[currentSize].left;
		heap[currentSize].left = 0;
		--currentSize;
	}
	
	int child;
	int hole = 1;
    int tmp = heap[hole].left;

    for( ; hole * 2 <= currentSize; hole = child)
    {
        child = hole * 2;
        if (child < currentSize && heap[child + 1].left < heap[child].left)
		{
			child++;
		}
        if (heap[child].left < tmp)
        {
			heap[hole].left = heap[child].left;
		}
        else
		{
			break;
		}
    }
	
	heap[hole].left = tmp;
	
	checkForNeededSwaps();
}

// method that deletes max from the interval heap
void IntervalHeap::deleteMax()
{
	
	// moves last element to root
	if ((getSize() % 2) == 0)
	{
		heap[1].right = heap[currentSize].right;
		heap[currentSize].right = 0;
	}
	else
	{	
		heap[1].right = heap[currentSize].left;
		heap[currentSize].left = 0;
		--currentSize;
	}
	
    int child;
	int hole = 1;
    int tmp = heap[hole].right;

    for( ; hole * 2 <= currentSize; hole = child)
    {
        child = hole * 2;
        if (child < currentSize && heap[child + 1].right > heap[child].right)
		{
			child++;
		}
        if (heap[child].right > tmp)
        {
			heap[hole].right = heap[child].right;
		}	
        else
		{
			break;
		}
    }
	
    heap[hole].right = tmp;
	
	checkForNeededSwaps();
}

// goes through the entire heap and checks if any values violate left < right
void IntervalHeap::checkForNeededSwaps()
{
	for (int i = 1; i <= currentSize; i++)
	{
		if (heap[i].left > heap[i].right && (heap[i].right != 0))
		{
			swapLeftAndRightElements(i);
		}
	}
}

// print level order interval heap to results.txt file
void IntervalHeap::printIntervalHeap(ostream &out)
{
	for (int i = 1; i <= currentSize; i++)
	{
		if (!heap[i].right)
		{
			out << heap[i].left << endl;
		}
		else
		{
			out << heap[i].left << "," << heap[i].right << endl;
		}
	}
	out << endl;
}