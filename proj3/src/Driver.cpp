/******************************************************************************
 ** File:    Driver.cpp
 ** Project: CMSC 341 Project 3, Spring 2015
 ** Author:  Dean Fleming
 ** Date:    3/15/15
 ** Section: 02
 ** E-mail:  deanf1@umbc.edu
 **
 ** This is the driver file for the random binary search tree project.
 **
 *****************************************************************************/

#include "BinarySearchTree.h"
#include "RandomizedBinarySearchTree.h"

#include <fstream>
#include <sstream>
#include <vector>

void printGreeting()
{
	cout << "Dean Fleming, Section 02" << endl;
}

int main(int argc, char *argv[])
{
	printGreeting();
	
	// gets the command line arguments
	string filename = argv[1];
	string sHeight = argv[2];
	int height = atoi(sHeight.c_str());
	
	// opens and validates the input file
	ifstream infile;
	infile.open(filename.c_str(), ios_base::in);
	if (infile.fail())
	{
		cout << "Error: File not found" << endl;
		exit(1);
	}
	
	// validates the height command line argument
	if (height < 0)
	{
		cout << "Error: L must be an int greater than or equal to 0" << endl;
		exit(1);
	}
	
	// opens the output file
	ofstream outfile;
	outfile.open("results.txt");
	
	// gets numbers to insert from file
	vector<int> numbers;
	string currentLine;
	
	while (getline(infile, currentLine))
	{
		stringstream ss(currentLine);
		string sCurrentNum;
		
		while (ss >> sCurrentNum)
		{
			int currentNum = atoi(sCurrentNum.c_str());
			numbers.push_back(currentNum);
		}
	}
	
	// inserts all the numbers into the trees
	BinarySearchTree<int> normTree;
	RandomizedBinarySearchTree<int> randTree;
	
	for (unsigned int i = 0; i < numbers.size(); i++)
	{
		normTree.insert(numbers[i]);
		randTree.insert(numbers[i]);
	}
	
	// prints the heights of the trees
	outfile << "Height of normal BST is " << normTree.height() << endl;
	outfile << "Height of randomized BST is " << randTree.height() << endl;
	
	// prints the level orders of the trees
	normTree.printLevelOrder(height, outfile);
	randTree.printLevelOrder(height, outfile);
	
	// closes the files
	infile.close();
	outfile.close();
}