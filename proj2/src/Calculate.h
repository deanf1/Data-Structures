/******************************************************************************
 ** File:    Calculate.h
 ** Project: CMSC 341 Project 2, Spring 2015
 ** Author:  Dean Fleming
 ** Date:    2/24/15
 ** Section: 02
 ** E-mail:  deanf1@umbc.edu
 **
 ** This is the header file for the calculator object.
 ** The Calculate class represents a calculator that calculates equations
 ** with many operator types and does it with a prioritized order.
 **
 *****************************************************************************/
 
#ifndef CALCULATE_H
#define CALCULATE_H

#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Calculate
{
	public:
	
		//---------------------------------------------------------------------
		// Name:			Calculate
		// Precondition:	None
		// Postcondition:	A new Calculate object is constructed.
		//---------------------------------------------------------------------
		Calculate(string filename);
		
		//---------------------------------------------------------------------
		// Name:			readFile
		// Precondition:	None
		// Postcondition:	The file is opened and read or quits on file error.
		//---------------------------------------------------------------------
		void readFile();
		
		//---------------------------------------------------------------------
		// Name:			calculateEquation
		// Precondition:	The input file has been validated and opened.
		// Postcondition:	The equations are calculated and written to file.
		//---------------------------------------------------------------------
		void calculateEquations();
		
		//---------------------------------------------------------------------
		// Name:			writeResults
		// Precondition:	The data is ready to be printed to a file.
		// Postcondition:	The data is written to the output file.
		//---------------------------------------------------------------------
		void writeResults();
		
	private:
	
		string inFilename;		// input filename
		ifstream infile;		// input file
		ofstream outfile;		// output file
		
		stack<string> op;		// stack for the operator symbols
		stack<int> priority;	// stack for the operator priority values
		stack<double> value;	// stack for the values of the equation
		
		map<string, int> inputPriority;	// priority for if symbol gets pushed
		map<string, int> stackPriority;	// priority given to symbol after push
		
		vector<string> answers;	// the answers of all the equations
		
		bool errorFound;		// an exit flag for if input is invalid
		
		//---------------------------------------------------------------------
		// Name:			push
		// Precondition:	None
		// Postcondition:	Symbol pushed onto stack or popAndProcess called.
		//---------------------------------------------------------------------
		void push(string currentChar);
		
		//---------------------------------------------------------------------
		// Name:			popAndProcess
		// Precondition:	None
		// Postcondition:	A section of the equation is calculated.
		//---------------------------------------------------------------------
		void popAndProcess();
};

#endif