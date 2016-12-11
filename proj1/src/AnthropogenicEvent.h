/******************************************************************************
 ** File:    AnthropogenicEvent.h
 ** Project: CMSC 341 Project 1, Spring 2015
 ** Author:  Dean Fleming
 ** Date:    2/9/15
 ** Section: 02
 ** E-mail:  deanf1@umbc.edu
 **
 ** This is the header file for the anthropogenic event object.
 ** The AnthropogenicEvent class represents a type of SeismicEvent.
 **
 *****************************************************************************/
 
#ifndef ANTHROPOGENICEVENT_H
#define ANTHROPOGENICEVENT_H

#include "SeismicEvent.h"

using namespace std;

class AnthropogenicEvent : public SeismicEvent
{
	// output operator overload
	friend ostream &operator << (ostream &output, AnthropogenicEvent &event);
};

#endif