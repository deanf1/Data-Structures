/******************************************************************************
 ** File:    MiningExplosion.h
 ** Project: CMSC 341 Project 1, Spring 2015
 ** Author:  Dean Fleming
 ** Date:    2/9/15
 ** Section: 02
 ** E-mail:  deanf1@umbc.edu
 **
 ** This is the header file for the mining explosion object.
 ** The MiningExplosion class represents a type of SeismicEvent.
 **
 *****************************************************************************/
 
#ifndef MININGEXPLOSION_H
#define MININGEXPLOSION_H

#include "SeismicEvent.h"

using namespace std;

class MiningExplosion : public SeismicEvent
{
	// output operator overload
	friend ostream &operator << (ostream &output, MiningExplosion &event);
};

#endif