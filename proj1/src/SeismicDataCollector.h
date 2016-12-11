/******************************************************************************
 ** File:    SeismicDataCollector.h
 ** Project: CMSC 341 Project 1, Spring 2015
 ** Author:  Dean Fleming
 ** Date:    2/9/15
 ** Section: 02
 ** E-mail:  deanf1@umbc.edu
 **
 ** This is the header file for the seismic data collector object.
 ** The SeismicDataCollector class reads in a .csv file, interprets the data
 ** into a dynamic array, and then writes the data out.
 **
 *****************************************************************************/
 
#ifndef SEISMICDATACOLLECTOR_H
#define SEISMICDATACOLLECTOR_H

#include <fstream>
#include <stdlib.h>

#include "AcousticNoise.h"
#include "AnthropogenicEvent.h"
#include "Earthquake.h"
#include "Explosion.h"
#include "MiningExplosion.h"
#include "QuarryBlast.h"

using namespace std;
 
class SeismicDataCollector
{
	public:
		
		//---------------------------------------------------------------------
		// Name:			readFile
		// Precondition:	None
		// Postcondition:	The file has been parsed and data outputted.
		//---------------------------------------------------------------------
		void readFile(string fileName);
		
		//---------------------------------------------------------------------
		// Name:			getFileName
		// Precondition:	None
		// Postcondition:	The file name is returned.
		//---------------------------------------------------------------------
		string getFileName();
		
		//---------------------------------------------------------------------
		// Name:			setFileName
		// Precondition:	None
		// Postcondition:	The file is set and checked that no errors exist.
		//---------------------------------------------------------------------
		bool setFileName(string fileName);
		
		//---------------------------------------------------------------------
		// Name:			writeResultingData
		// Precondition:	A SeismicEvent object has been made and is ready.
		// Postcondition:	The data is outputted.
		//---------------------------------------------------------------------
		void writeResultingData(SeismicEvent s);
		
		void increaseArraySize(SeismicEvent *&s);
		
	private:
		
		// max size of array data member
		int maxSize;
		
		// dynamic array data members
		SeismicEvent acoustic_noise[];
		SeismicEvent anthropogenic_event[];
		SeismicEvent earthquake[];
		SeismicEvent explosion[];
		SeismicEvent mining_explosion[];
		SeismicEvent quarry_blast[];
		
		// file name data member
		string filename;
		
		// input and output file data members
		ifstream infile;
		ofstream outfileAN;
		ofstream outfileAE;
		ofstream outfileEa;
		ofstream outfileEx;
		ofstream outfileME;
		ofstream outfileQB;
};

#endif