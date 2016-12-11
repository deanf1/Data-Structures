/******************************************************************************
 ** File:    QuarryBlast.cpp
 ** Project: CMSC 341 Project 1, Spring 2015
 ** Author:  Dean Fleming
 ** Date:    2/9/15
 ** Section: 02
 ** E-mail:  deanf1@umbc.edu
 **
 ** This is the source file for the quarry blast object.
 ** The QuarryBlast class represents a type of SeismicEvent.
 **
 *****************************************************************************/
 
#include "QuarryBlast.h"

// output operator overload
ostream &operator << (ostream &output, QuarryBlast &event)
{
	output << "time -> " << event.getTime() << endl;
	output << "latitude -> " << event.getLatitude() << endl;
	output << "longitude -> " << event.getLongitude() << endl;
	output << "mag -> " << event.getMag() << endl;
	output << "place -> " << event.getPlace() << endl;
	output << "type -> " << event.getTypeAsString() << endl;
	output << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
	
	return output;
}