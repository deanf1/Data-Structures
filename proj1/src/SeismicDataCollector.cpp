/******************************************************************************
 ** File:    SeismicDataCollector.cpp
 ** Project: CMSC 341 Project 1, Spring 2015
 ** Author:  Dean Fleming
 ** Date:    2/9/15
 ** Section: 02
 ** E-mail:  deanf1@umbc.edu
 **
 ** This is the source file for the seismic data collector object.
 ** The SeismicDataCollector class reads in a .csv file, interprets the data
 ** into a dynamic array, and then writes the data out.
 **
 *****************************************************************************/

#include "SeismicDataCollector.h"

// readFile
// Reads the file and makes sure all data is outputted.
void SeismicDataCollector::readFile(string fileName)
{
	// string versions of all data
	// ORDER OF CATEGORIES FROM FILE:
	// time,latitude,longitude,depth,mag,magType,nst,gap,dmin,rms,net,id,
	// updated,place,type
	string 	time, s_latitude, s_longitude, s_depth, s_mag, s_magType, s_dmin, 
			place, place2, s_type;
	
	// initializes data arrays
	SeismicEvent *acoustic_noise = NULL;
	SeismicEvent *anthropogenic_event = NULL;
	SeismicEvent *earthquake = NULL;
	SeismicEvent *explosion = NULL;
	SeismicEvent *mining_explosion = NULL;
	SeismicEvent *quarry_blast = NULL;
	maxSize = 100;
	acoustic_noise = new SeismicEvent[maxSize];
	anthropogenic_event = new SeismicEvent[maxSize];
	earthquake = new SeismicEvent[maxSize];
	explosion = new SeismicEvent[maxSize];
	mining_explosion = new SeismicEvent[maxSize];
	quarry_blast = new SeismicEvent[maxSize];
	
	// initializes data array sizes
	int	aN_size = 0, aE_size = 0, ea_size = 0, ex_size = 0, mE_size = 0, 
		qB_size = 0;
		
	// opens the output files
	outfileAN.open("resultsAcousticNoise.txt");
	outfileAE.open("resultsAnthropogenicEvent.txt");
	outfileEa.open("resultsEarthquake.txt");
	outfileEx.open("resultsExplosion.txt");
	outfileME.open("resultsMiningExplosion.txt");
	outfileQB.open("resultsQuarryBlast.txt");
	
	// puts a line on the top of the output files for aesthetic purposes
	outfileAN << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
	outfileAE << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
	outfileEa << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
	outfileEx << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
	outfileME << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
	outfileQB << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
	
	getline(infile, time);					// skips the first line of input file
	while (getline(infile, time, ','))		// gets time and loop through file
	{					
		getline(infile, s_latitude, ',');
		getline(infile, s_longitude, ',');
		getline(infile, s_depth, ',');
		getline(infile, s_mag, ',');
		getline(infile, s_magType, ',');
		getline(infile, s_dmin, ',');		// skip over "nst"
		getline(infile, s_dmin, ',');		// skip over "gap"
		getline(infile, s_dmin, ',');
		getline(infile, place, ',');		// skip over "rms"
		getline(infile, place, ',');		// skip over "net"
		getline(infile, place, ',');		// skip over "id"
		getline(infile, place, ',');		// skip over "updated"
		getline(infile, place, ',');
		getline(infile, place2, ',');		// gets the second part of place
		place.append(",");					// appends the lost comma to place
		place.append(place2);				// appends both place parts
		getline(infile, s_type, '\n');
		
		// converts some data to float type
		float latitude = atof(s_latitude.c_str());
		float longitude = atof(s_longitude.c_str());
		float depth = atof(s_depth.c_str());
		float mag = atof(s_mag.c_str());
		float dmin = atof(s_dmin.c_str());

		// converts the string of magType into a magType
		SeismicEvent::magType thisMagType;
		if (s_magType == "md") { thisMagType = SeismicEvent::md; }
		else if (s_magType == "ml") { thisMagType = SeismicEvent::ml; }
		else if (s_magType == "mb_lg") { thisMagType = SeismicEvent::mb_lg; }
		
		// makes arrays bigger if they have to be
		/*if (aN_size == maxSize) { increaseArraySize(&acoustic_noise); }
		else if (aN_size == maxSize) { increaseArraySize(&anthropogenic_event); }
		else if (ea_size == maxSize) { increaseArraySize(&earthquake); }
		else if (ex_size == maxSize) { increaseArraySize(&explosion); }
		else if (mE_size == maxSize) { increaseArraySize(&mining_explosion); }
		else if (qB_size == maxSize) { increaseArraySize(&quarry_blast); }*/
		
		// creates object based on type, puts in the array and calls to print
		if (s_type == "acoustic noise\r")
		{
			AcousticNoise aN;
			aN.setTime(time);
			aN.setLatitude(latitude);
			aN.setLongitude(longitude);
			aN.setMag(mag);
			aN.setMagType(thisMagType);
			aN.setDmin(dmin);
			aN.setPlace(place);
			aN.setType(SeismicEvent::acoustic_noise);
			acoustic_noise[aN_size++] = aN;
			writeResultingData(aN);
		}
		else if (s_type == "anthropogenic event\r")
		{
			AnthropogenicEvent aE;
			aE.setTime(time);
			aE.setLatitude(latitude);
			aE.setLongitude(longitude);
			aE.setMag(mag);
			aE.setDmin(dmin);
			aE.setPlace(place);
			aE.setType(SeismicEvent::anthropogenic_event);
			anthropogenic_event[aE_size++] = aE;
			writeResultingData(aE);
		}
		else if (s_type == "earthquake\r")
		{
			Earthquake ea;
			ea.setTime(time);
			ea.setLatitude(latitude);
			ea.setLongitude(longitude);
			ea.setDepth(depth);
			ea.setMag(mag);
			ea.setMagType(thisMagType);
			ea.setDmin(dmin);
			ea.setPlace(place);
			ea.setType(SeismicEvent::earthquake);
			earthquake[ea_size++] = ea;
			writeResultingData(ea);
		}
		else if (s_type == "explosion\r")
		{
			Explosion ex;
			ex.setTime(time);
			ex.setLatitude(latitude);
			ex.setLongitude(longitude);
			ex.setMag(mag);
			ex.setDmin(dmin);
			ex.setPlace(place);
			ex.setType(SeismicEvent::explosion);
			explosion[ex_size++] = ex;
			writeResultingData(ex);
		}
		else if (s_type == "mining explosion\r")
		{
			MiningExplosion mE;
			mE.setTime(time);
			mE.setLatitude(latitude);
			mE.setLongitude(longitude);
			mE.setMag(mag);
			mE.setDmin(dmin);
			mE.setPlace(place);
			mE.setType(SeismicEvent::mining_explosion);
			mining_explosion[mE_size++] = mE;
			writeResultingData(mE);
		}
		else if (s_type == "quarry blast\r")
		{
			QuarryBlast qB;
			qB.setTime(time);
			qB.setLatitude(latitude);
			qB.setLongitude(longitude);
			qB.setMag(mag);
			qB.setDmin(dmin);
			qB.setPlace(place);
			qB.setType(SeismicEvent::quarry_blast);
			quarry_blast[qB_size++] = qB;
			writeResultingData(qB);
		}
	}
	
	// closes all files
	infile.close();
	outfileAN.close();
	outfileAE.close();
	outfileEa.close();
	outfileEx.close();
	outfileME.close();
	outfileQB.close();
	
	// deletes and resets all arrays used
	delete[] acoustic_noise;
	delete[] anthropogenic_event;
	delete[] earthquake;
	delete[] explosion;
	delete[] mining_explosion;
	delete[] quarry_blast;
	acoustic_noise = NULL;
	anthropogenic_event = NULL;
	earthquake = NULL;
	explosion = NULL;
	mining_explosion = NULL;
	quarry_blast = NULL;
}

void increaseArraySize(SeismicEvent *&s)
{
	cout << "test";
}

// getFileName
// Gets the file name
string SeismicDataCollector::getFileName()
{
	return filename;
}

// setFileName
// Sets the file name
bool SeismicDataCollector::setFileName(string fileName)
{
	filename = fileName;
	infile.open(filename.c_str(), ios_base::in);
	
	if (infile.fail())
	{
		cout << "File Error" << endl;
		return false;
	}
	
	return true;
}

// writeResultingData
// Writes the data to their respective files
void SeismicDataCollector::writeResultingData(SeismicEvent s)
{
	if (s.getType() == SeismicEvent::acoustic_noise)
	{
		AcousticNoise &aN = static_cast<AcousticNoise&>(s);
		outfileAN << aN;
	}
	else if (s.getType() == SeismicEvent::anthropogenic_event)
	{
		AnthropogenicEvent &aE = static_cast<AnthropogenicEvent&>(s);
		outfileAE << aE;
	}
	else if (s.getType() == SeismicEvent::earthquake)
	{
		Earthquake &ea = static_cast<Earthquake&>(s);
		outfileEa << ea;
	}
	else if (s.getType() == SeismicEvent::explosion) 			
	{
		Explosion &ex = static_cast<Explosion&>(s);
		outfileEx << ex; 
	}
	else if (s.getType() == SeismicEvent::mining_explosion)		
	{
		MiningExplosion &mE = static_cast<MiningExplosion&>(s);
		outfileME << mE;
	}
	else if (s.getType() == SeismicEvent::quarry_blast) 		
	{
		QuarryBlast &qB = static_cast<QuarryBlast&>(s);
		outfileQB << qB;
	}
}