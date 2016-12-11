/******************************************************************************
 ** File:    Driver.cpp
 ** Project: CMSC 341 Project 5, Spring 2015
 ** Author:  Dean Fleming
 ** Date:    4/23/15
 ** Section: 02
 ** E-mail:  deanf1@umbc.edu
 **
 ** This is the driver file for the hashing to compare documents project.
 **
 *****************************************************************************/

#include <cstring>
#include <dirent.h>

#include "TextFile.h"

using namespace std;

// prints name and section
void printGreeting()
{
	cout << "Dean Fleming, Section 02" << endl;
}

int main(int argc, char *argv[])
{
	printGreeting();
	
    DIR *dir;
    dirent *pdir;

    dir = opendir(argv[1]);
	
	// exits the program if directory not found
	if (dir == NULL)
	{
		cout << "Error: Directory not found" << endl;
		exit(true);
	}
	
	vector<TextFile> files;
	files.reserve(101);			// assuming not over 101 files
	
	ofstream outfile;
	outfile.open("results.txt");
	
	// gets all the files from the directory and processes them
    while ((pdir = readdir(dir)))
	{
		// excludes the "." and ".." directories
		if (strcmp(pdir->d_name, ".") != 0 && strcmp(pdir->d_name, "..") != 0)
		{
			// creates the full file path
			string path = argv[1];
			path += "/";
			path += pdir->d_name;
		
			// processes the file and saves it for later
			TextFile newFile(pdir->d_name, path);
			newFile.hashFile();
			files.push_back(newFile);
		}
    }
	
	closedir(dir);
	
	// finds all of the Jaccard similarities
	float maxJaccard = -1.0;
	int maxJaccardFileIndex1;
	int maxJaccardFileIndex2;
	for (unsigned int i = 0; i < files.size(); i++)
	{
		for (unsigned int j = i; j < files.size(); j++)
		{
			
			// finds the intersection and union and does the calculation
			int interSize = (files[i].getHash()).sizeOfIntersection(files[j].getHash());
			int unionSize = (files[i].getHash()).sizeOfUnion(files[j].getHash());
			float jaccard = (float) interSize / unionSize;
			
			// prints the Jaccard similarity
			outfile <<  "J(\"" << files[i].getFilename() << "\", \"" << 
						files[j].getFilename() << "\") = " << jaccard << endl;
			
			// keeps track of the maximum Jaccard similarity (most similar unique files)
			if (jaccard > maxJaccard && i != j)
			{
				maxJaccard = jaccard;
				maxJaccardFileIndex1 = i;
				maxJaccardFileIndex2 = j;
			}
		}
	}
	
	// outputs the most similar unique files
	outfile << endl;
	outfile <<  "Most similar: \"" << files[maxJaccardFileIndex1].getFilename() << 
				"\", \"" << files[maxJaccardFileIndex2].getFilename() << "\"" << endl;
	
	outfile.close();
}