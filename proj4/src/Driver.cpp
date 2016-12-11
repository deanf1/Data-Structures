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
	files.reserve(100);
	
	ofstream outfile;
	outfile.open("results.txt");
	outfile << "test" << endl;
	// gets all the files from the directory and processes them
    while ((pdir = readdir(dir)))
	{
		if (strcmp(pdir->d_name, ".") != 0 && strcmp(pdir->d_name, "..") != 0)
		{
			// creates the full file path
			string path = argv[1];
			path += "/";
			path += pdir->d_name;
		
			// processes the file and saves it for later
			TextFile newFile(path);
			newFile.hashFile();
			newFile.getHash().printHash();
			files.push_back(newFile);
			//newFile->deleteTextFile();
		}
    }
	
	closedir(dir);
	
	/*for (unsigned int i = 0; i < files.size(); i++)
	{
		for (int j = 0; j < 26; j++)
		{
			for (unsigned int k = 0; k < files[i].hash[j].size(); k++)
			{
				cout << files[i].hash[j][k] << endl;
			}
		}
		cout << endl;
	}*/
	
	outfile.close();
}