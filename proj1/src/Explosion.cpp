/******************************************************************************
 ** File:    Explosion.cpp
 ** Project: CMSC 341 Project 1, Spring 2015
 ** Author:  Dean Fleming
 ** Date:    2/9/15
 ** Section: 02
 ** E-mail:  deanf1@umbc.edu
 **
 ** This is the source file for the explosion object.
 ** The Explosion class represents a type of SeismicEvent.
 **
 *****************************************************************************/
 
#include "Explosion.h"

ostream &operator << (ostream &output, Explosion &event)
{
	// calls the superclass operator overload 
	SeismicEvent *event2 = &event;
	output << *event2;
	return output;
}