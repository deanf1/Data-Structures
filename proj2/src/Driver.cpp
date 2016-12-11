/******************************************************************************
 ** File:    Driver.cpp
 ** Project: CMSC 341 Project 2, Spring 2015
 ** Author:  Dean Fleming
 ** Date:    2/24/15
 ** Section: 02
 ** E-mail:  deanf1@umbc.edu
 **
 ** This is the driver file for the calculator project.
 **
 *****************************************************************************/

#include "Calculate.h"

void printGreeting()
{
	cout << "Dean Fleming, Section 02" << endl;
}

int main(int argc, char *argv[])
{
	printGreeting();
	
	string filename = argv[1];
	
	Calculate calc(filename);
	calc.readFile();
	calc.calculateEquations();
	calc.writeResults();
}