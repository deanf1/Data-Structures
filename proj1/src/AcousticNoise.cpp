/******************************************************************************
 ** File:    AcousticNoise.cpp
 ** Project: CMSC 341 Project 1, Spring 2015
 ** Author:  Dean Fleming
 ** Date:    2/9/15
 ** Section: 02
 ** E-mail:  deanf1@umbc.edu
 **
 ** This is the source file for the acoustic noise object.
 ** The AcousticNoise class represents a type of SeismicEvent.
 **
 *****************************************************************************/

#include "AcousticNoise.h"

ostream &operator << (ostream &output, AcousticNoise &event)
{
	// calls the superclass operator overload 
	SeismicEvent *event2 = &event;
	output << *event2;
	return output;
}