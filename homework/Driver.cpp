#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Hash
{
	public:
	
		int *hash;
		
		Hash()
		{
			hash = new int[29];
			
			for (int i = 0; i < 29; i++)
			{
				hash[i] = 0;
			}
		}
		
		~Hash()
		{
			delete[] hash;
			hash = NULL;
		}
		
		void insert(int n)
		{
			insert(n, (n % 29), 0);
		}
		
		void insert(int n, int index, int counter)
		{
			if (hash[index] != 0)
			{
				counter++;
				insert(n, (((n % 29) + (counter * counter)) % 29), counter);
			}
			else
			{
				hash[index] = n;
				cout << counter << endl;
			}
		}
		
		void printHash()
		{
			for (int i = 0; i < 29; i++)
			{
				cout << hash[i] << endl;
			}
		}
};

int main()
{
	string filename = "input.txt";
	
	// opens and validates the input file
	ifstream infile;
	infile.open(filename.c_str(), ios_base::in);
	if (infile.fail())
	{
		cout << "Error: File not found" << endl;
		exit(1);
	}
	
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
	
	Hash h;
	
	for (unsigned int i = 0; i < numbers.size(); i++)
	{
		h.insert(numbers[i]);
	}
	
	cout << endl;
	h.printHash();
	
	infile.close();
}