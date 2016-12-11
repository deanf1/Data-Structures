/******************************************************************************
 ** File:    TextFile.h
 ** Project: CMSC 341 Project 5, Spring 2015
 ** Author:  Dean Fleming
 ** Date:    4/23/15
 ** Section: 02
 ** E-mail:  deanf1@umbc.edu
 **
 ** This is the header file for a text file hash data structure.
 ** A TextFile contains both the filename of a file and a hash table of all 
 ** the words within that file.
 **
 *****************************************************************************/

#ifndef TEXTFILE_H
#define TEXTFILE_H

#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>

#include "QuadraticProbing.h"

using namespace std;

class TextFile
{
	public:
	
		TextFile(string filename, string filepath);
		void hashFile();
		string getFilename() { return filename; }
		HashTable<string> getHash() { return hash; }
		
	private:
	
		string filename;
		string filepath;
		HashTable<string> hash;
};

#endif