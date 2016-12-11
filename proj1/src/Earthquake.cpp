/******************************************************************************
 ** File:    Earthquake.cpp
 ** Project: CMSC 341 Project 1, Spring 2015
 ** Author:  Dean Fleming
 ** Date:    2/9/15
 ** Section: 02
 ** E-mail:  deanf1@umbc.edu
 **
 ** This is the source file for the earthquake object.
 ** The Earthquake class represents a type of SeismicEvent. It has some more
 ** members and functions than a normal SeismicEvent.
 **
 *****************************************************************************/

#include "Earthquake.h"

// setDepth
// Sets the depth
void Earthquake::setDepth(float newDepth) { depth = newDepth; }

// getDepth
// Returns the depth
float Earthquake::getDepth() { return depth; }

// output operator overload
ostream &operator << (ostream &output, Earthquake &event)
{
	output << "time -> " << event.getTime() << endl;
	output << "latitude -> " << event.getLatitude() << endl;
	output << "longitude -> " << event.getLongitude() << endl;
	output << "depth -> " << event.getDepth() << endl;
	output << "mag -> " << event.getMag() << endl;
	output << "magType -> " << event.getMagTypeAsString() << endl;
	output << "place -> " << event.getPlace() << endl;
	output << "type -> " << event.getTypeAsString() << endl;
	output << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
	
	return output;
}