/******************************************************************************
 ** File:    Driver.cpp
 ** Project: CMSC 341 Project 1, Spring 2015
 ** Author:  Dean Fleming
 ** Date:    2/9/15
 ** Section: 02
 ** E-mail:  deanf1@umbc.edu
 **
 ** This is the driver file for the seismic data project.
 **
 *****************************************************************************/

#include "SeismicDataCollector.h"

void printGreeting()
{
	cout << "Dean Fleming, Section 02" << endl;
}

int main(int argc, char *argv[])
{
	printGreeting();
	SeismicDataCollector sdc;
	string fileName = argv[1];
	sdc.setFileName(fileName);
	sdc.readFile(fileName);
}