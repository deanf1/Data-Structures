/******************************************************************************
 ** File:    TextFile.cpp
 ** Project: CMSC 341 Project 5, Spring 2015
 ** Author:  Dean Fleming
 ** Date:    4/23/15
 ** Section: 02
 ** E-mail:  deanf1@umbc.edu
 **
 ** This is the source file for a text file hash data structure.
 ** A TextFile contains both the filename and filepath of a file and a hash 
 ** table of all the words within that file.
 **
 *****************************************************************************/

#include "TextFile.h"

// constructor
TextFile::TextFile(string filename, string filepath)
{
	this->filename = filename;
	this->filepath = filepath;
}

// takes all the words from the file and puts them in a hash table
void TextFile::hashFile()
{
	// opens input file
	ifstream infile;
	infile.open(filepath.c_str(), ios_base::in);
	if (infile.fail())
	{
		cout << "Error: File not found" << endl;
		exit(true);
	}
	
	// loops through whole file and finds every word
	string currentLine;
	while (getline(infile, currentLine))
	{
		stringstream ss(currentLine);
		string currentWord;
		
		while (ss >> currentWord)
		{	
			// removes all punctuation
			string newCurrentWord;
			remove_copy_if(	currentWord.begin(), currentWord.end(),            
							back_inserter(newCurrentWord),
							ptr_fun<int, int>(::ispunct));
							
			// converts words to lower case
			transform(	newCurrentWord.begin(), newCurrentWord.end(), 
						newCurrentWord.begin(), ::tolower);
			
			// puts the word in the hash table
			hash.insert(newCurrentWord);
		}
	}
	
	infile.close();
}