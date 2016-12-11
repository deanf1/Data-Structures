/******************************************************************************
 ** File:    QuarryBlast.h
 ** Project: CMSC 341 Project 1, Spring 2015
 ** Author:  Dean Fleming
 ** Date:    2/9/15
 ** Section: 02
 ** E-mail:  deanf1@umbc.edu
 **
 ** This is the header file for the quarry blast object.
 ** The QuarryBlast class represents a type of SeismicEvent.
 **
 *****************************************************************************/
 
#ifndef QUARRYBLAST_H
#define QUARRYBLAST_H

#include "SeismicEvent.h"

using namespace std;

class QuarryBlast : public SeismicEvent
{
	// output operator overload
	friend ostream &operator << (ostream &output, QuarryBlast &event);
};

#endif