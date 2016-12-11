/******************************************************************************
 ** File:    Calculate.cpp
 ** Project: CMSC 341 Project 2, Spring 2015
 ** Author:  Dean Fleming
 ** Date:    2/24/15
 ** Section: 02
 ** E-mail:  deanf1@umbc.edu
 **
 ** This is the source file for the calculator object.
 ** The Calculate class represents a calculator that calculates equations
 ** with many operator types and does it with a prioritized order.
 **
 *****************************************************************************/

#include "Calculate.h"

// Calculate
// Constructs a new Calculate object
Calculate::Calculate(string filename)
{
	// sets filename
	inFilename = filename;
	
	// pushes the stop symbols onto the stacks
	op.push("$");
	priority.push(-1);
	
	// fills the maps with priority keys and values
	inputPriority["+"] = 1;
	inputPriority["-"] = 1;
	inputPriority["*"] = 2;
	inputPriority["/"] = 2;
	inputPriority["%"] = 2;
	inputPriority["^"] = 5;
	inputPriority["("] = 6;
	
	stackPriority["+"] = 1;
	stackPriority["-"] = 1;
	stackPriority["*"] = 2;
	stackPriority["/"] = 2;
	stackPriority["%"] = 2;
	stackPriority["^"] = 4;
	stackPriority["("] = 0;
	stackPriority["$"] = -1;
	
	// defaults the capacity of the answer vector to 100
	answers.reserve(100);
	
	errorFound = false;
}

// readFile
// Opens the input file and makes sure it is valid, and opens output file
void Calculate::readFile()
{
	infile.open(inFilename.c_str(), ios_base::in);
	
	if (infile.fail())
	{
		cout << "File Not Found" << endl;
		exit(1);
	}
	
	// also opens the output file
	outfile.open("results.txt");
}

// calculateEquations
// Calculates all the equations and passes them to be written to file
void Calculate::calculateEquations()
{
	string currentLine;	// holds what line it is currently on
	string currentChar;	// holds what character it is currently on
	
	// loops through each line of the file
	while (!infile.eof())
	{
		getline(infile, currentLine, '\r');
		stringstream ss(currentLine);
		
		// loops through each character in the line
		while (getline(ss, currentChar, ' ') && !errorFound)
		{
			// resizes the answers vector if its full
			if (answers.size() == answers.capacity())
			{
				answers.reserve(answers.size() + 100);
			}
			
			// strips off an extraneous newline character
			if (currentChar.find("\n") == 0)
			{
				currentChar = currentChar.substr(1);
			}
			
			// checks for operators
			if (currentChar == "+" || currentChar == "-" ||
				currentChar == "*" || currentChar == "/" || 
				currentChar == "%" || currentChar == "^" || 
				currentChar == "(")
			{
				push(currentChar);
			}
			
			// checks for ")"
			else if (currentChar == ")")
			{
				// loops until left parenthesis is found
				while (op.top() != "(" && !errorFound)
				{
					popAndProcess();
				}
				
				// pops the left parenthesis
				if (!errorFound)
				{
					op.pop();
					priority.pop();
				}
				
				// checks for an error in a case like "1 ( 2 + 3 )"
				if (op.top() == "$" && value.size() > 1)
				{
					answers.push_back("invalid");
					errorFound = true;
				}
			}
			
			// checks for numerals
			else
			{
				value.push(atof(currentChar.c_str()));
			}
		}
		
		// calculates whatever is left over
		while (op.top() != "$" && !errorFound)
		{
			popAndProcess();
		}
		
		// saves the answer and pops it off the stack
		if (!errorFound)
		{
			stringstream ssAnswer;
			ssAnswer << value.top();
			value.pop();
			answers.push_back(ssAnswer.str());
		}
		
		// resets the stacks if an error was found
		else
		{
			for (unsigned int i = 0; i < op.size(); i++)
			{
				op.pop();
			}
			for (unsigned int i = 0; i < priority.size(); i++)
			{
				priority.pop();
			}
			for (unsigned int i = 0; i < value.size(); i++)
			{ 
				value.pop();
			}
			
			op.push("$");
			priority.push(-1);
			
			errorFound = false;
		}
	}
	
	infile.close();
}

// push
// Pushes the symbol onto the stack or calls popAndProcess
void Calculate::push(string currentChar)
{
	// gets the input priority from the map
	int inPriority = inputPriority.find(currentChar)->second;
	
	// puts the operator on the stacks if it is greater
	if (inPriority > priority.top())
	{
		op.push(currentChar);
		priority.push(stackPriority.find(currentChar)->second);
	}
	
	// otherwise, it pops and processes and then checks again
	else
	{
		popAndProcess();
		push(currentChar);
	}
}

// popAndProcess
// Calculates a section of the equation
void Calculate::popAndProcess()
{
	// checks for an error that causes a segmentation fault
	if (value.size() < 2)
	{
		answers.push_back("invalid");
		errorFound = true;
		return;
	}
	
	// pops all the values off the stacks
	double secondNum = value.top();
	value.pop();
	double firstNum = value.top();
	value.pop();
	string oper = op.top();
	op.pop();
	priority.pop();
	
	// checks for errors where operator or parentheses are wrong
	if (oper == "(" || oper == "$" || oper == ")")
	{
		answers.push_back("invalid");
		errorFound = true;
		return;
	}
	
	// calculates based on the operator and pushes it onto the stack
	double answer;
	if 		(oper == "+")	{ answer = firstNum + secondNum; }
	else if	(oper == "-")	{ answer = firstNum - secondNum; }
	else if	(oper == "*")	{ answer = firstNum * secondNum; }
	else if	(oper == "/")	{ answer = firstNum / secondNum; }
	else if	(oper == "%")	{ answer = fmod(firstNum, secondNum); }
	else if	(oper == "^")	{ answer = pow(firstNum, secondNum); }
	value.push(answer);
}

// writeResults
// Writes the data to the output file
void Calculate::writeResults()
{
	for (unsigned int i = 0; i < answers.size(); i++)
	{
		outfile << answers[i] << endl;
	}
	
	outfile.close();
}