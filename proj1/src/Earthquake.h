/******************************************************************************
 ** File:    Earthquake.h
 ** Project: CMSC 341 Project 1, Spring 2015
 ** Author:  Dean Fleming
 ** Date:    2/9/15
 ** Section: 02
 ** E-mail:  deanf1@umbc.edu
 **
 ** This is the header file for the earthquake object.
 ** The Earthquake class represents a type of SeismicEvent. It has some more
 ** members and functions than a normal SeismicEvent.
 **
 *****************************************************************************/
 
#ifndef EARTHQUAKE_H
#define EARTHQUAKE_H

#include "SeismicEvent.h"

using namespace std;

class Earthquake : public SeismicEvent
{
	public:
	
		//---------------------------------------------------------------------
		// Name:			setDepth
		// Precondition:	None
		// Postcondition:	The depth is set.
		//---------------------------------------------------------------------
		void setDepth(float newDepth);
		
		//---------------------------------------------------------------------
		// Name:			getDepth
		// Precondition:	None
		// Postcondition:	The depth is returned.
		//---------------------------------------------------------------------
		float getDepth();
		
	private:
	
		// depth data member
		float depth;
		
	// output operator overload
	friend ostream &operator << (ostream &output, Earthquake &event);
};

#endif
