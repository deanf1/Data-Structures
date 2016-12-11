/******************************************************************************
 ** File:    AcousticNoise.h
 ** Project: CMSC 341 Project 1, Spring 2015
 ** Author:  Dean Fleming
 ** Date:    2/9/15
 ** Section: 02
 ** E-mail:  deanf1@umbc.edu
 **
 ** This is the header file for the acoustic noise object.
 ** The AcousticNoise class represents a type of SeismicEvent.
 **
 *****************************************************************************/
 
#ifndef ACOUSTICNOISE_H
#define ACOUSTICNOISE_H

#include "SeismicEvent.h"

using namespace std;

class AcousticNoise : public SeismicEvent
{
	// output operator overload
	friend ostream &operator << (ostream &output, AcousticNoise &event);
};

#endif