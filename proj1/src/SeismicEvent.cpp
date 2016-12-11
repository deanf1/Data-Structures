/******************************************************************************
 ** File:    SeismicEvent.cpp
 ** Project: CMSC 341 Project 1, Spring 2015
 ** Author:  Dean Fleming
 ** Date:    2/9/15
 ** Section: 02
 ** E-mail:  deanf1@umbc.edu
 **
 ** This is the source file for the seismic event object.
 ** The SeismicEvent class represents a general seismic event and has many 
 ** subclasses.
 **
 *****************************************************************************/

#include "SeismicEvent.h"

// mutators
void SeismicEvent::setTime(string newTime) { time = newTime; }
void SeismicEvent::setLatitude(float newLatitude) { latitude = newLatitude; }
void SeismicEvent::setLongitude(float newLongitude) { longitude = newLongitude; }
void SeismicEvent::setMag(float newMag) { mag = newMag; }
void SeismicEvent::setMagType(magType newMagType) { m_magType = newMagType; }
void SeismicEvent::setDmin(float newDmin) { dmin = newDmin; }
void SeismicEvent::setPlace(string newPlace) { place = newPlace; }
void SeismicEvent::setType(type newType) { m_type = newType; }

// accessors
string SeismicEvent::getTime() { return time; }
float SeismicEvent::getLatitude() { return latitude; }
float SeismicEvent::getLongitude() { return longitude; }
float SeismicEvent::getMag() { return mag; }
SeismicEvent::magType SeismicEvent::getMagType() { return m_magType; }
float SeismicEvent::getDmin() { return dmin; }
string SeismicEvent::getPlace() { return place; }
SeismicEvent::type SeismicEvent::getType() { return m_type; }

// getMagTypeAsString
// "Converts" a magType into a string
string SeismicEvent::getMagTypeAsString()
{
	switch(m_magType)
	{
		case 0:	return "md";
		case 1:	return "ml";
		case 2:	return "mb_lg";
	}
	return "No magType";
}

// getTypeAsString
// "Converts" a type into a string
string SeismicEvent::getTypeAsString()
{
	switch(m_type)
	{
		case 0:	return "acoustic_noise";
		case 1:	return "anthropogenic_event";
		case 2:	return "earthquake";
		case 3:	return "explosion";
		case 4:	return "mining_explosion";
		case 5:	return "quarry_blast";
	}
	return "No type";
}

// output operator overload
ostream &operator << (ostream &output, SeismicEvent &event)
{
	output << "time -> " << event.getTime() << endl;
	output << "latitude -> " << event.getLatitude() << endl;
	output << "longitude -> " << event.getLongitude() << endl;
	output << "mag -> " << event.getMag() << endl;
	output << "magType -> " << event.getMagTypeAsString() << endl;
	output << "place -> " << event.getPlace() << endl;
	output << "type -> " << event.getTypeAsString() << endl;
	output << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
	
	return output;
}