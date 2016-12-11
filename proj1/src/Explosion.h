/******************************************************************************
 ** File:    Explosion.h
 ** Project: CMSC 341 Project 1, Spring 2015
 ** Author:  Dean Fleming
 ** Date:    2/9/15
 ** Section: 02
 ** E-mail:  deanf1@umbc.edu
 **
 ** This is the header file for the explosion object.
 ** The Explosion class represents a type of SeismicEvent.
 **
 *****************************************************************************/
 
#ifndef EXPLOSION_H
#define EXPLOSION_H

#include "SeismicEvent.h"

using namespace std;

class Explosion : public SeismicEvent
{
	// output operator overload
	friend ostream &operator << (ostream &output, Explosion &event);
};

#endif