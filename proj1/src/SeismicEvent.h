/******************************************************************************
 ** File:    SeismicEvent.h
 ** Project: CMSC 341 Project 1, Spring 2015
 ** Author:  Dean Fleming
 ** Date:    2/9/15
 ** Section: 02
 ** E-mail:  deanf1@umbc.edu
 **
 ** This is the header file for the seismic event object.
 ** The SeismicEvent class represents a general seismic event and has many 
 ** subclasses.
 **
 *****************************************************************************/
 
#ifndef SEISMICEVENT_H
#define SEISMICEVENT_H

#include <string>
#include <iostream>

using namespace std;
 
class SeismicEvent
{
	public:
		
		// enumerated data type declarations
		enum magType { md, ml, mb_lg };
		enum type 
		{
			acoustic_noise, 
			anthropogenic_event,
			earthquake,
			explosion,
			mining_explosion,
			quarry_blast
		};
		
		//---------------------------------------------------------------------
		// Name:			Various Mutators
		// Precondition:	None
		// Postcondition:	The data members are set.
		//---------------------------------------------------------------------
		void setTime(string newTime);
		void setLatitude(float newLatitude);
		void setLongitude(float newLongitude);
		void setMag(float newMag);
		void setMagType(magType newMagType);
		void setDmin(float newDmin);
		void setPlace(string newPlace);
		void setType(type newType);
		
		//---------------------------------------------------------------------
		// Name:			Various Accessors
		// Precondition:	None
		// Postcondition:	The data members are returned.
		//---------------------------------------------------------------------
		string getTime();
		float getLatitude();
		float getLongitude();
		float getMag();
		magType getMagType();
		float getDmin();
		string getPlace();
		type getType();
		
		//---------------------------------------------------------------------
		// Name:			getMagTypeAsString and getTypeAsString
		// Precondition:	None
		// Postcondition:	magType and type are represented as a string.
		//---------------------------------------------------------------------
		string getMagTypeAsString();
		string getTypeAsString();
		
	protected:
	
		// data members
		string time;
		float latitude;
		float longitude;
		float mag;
		magType m_magType;
		float dmin;
		string place;
		type m_type;
		
	// output operator overload
	friend ostream &operator << (ostream &output, SeismicEvent &event);
};

#endif