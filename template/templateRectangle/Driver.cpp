#include "Rectangle.h"

#include <iostream>
using namespace std;

int main()
{
	Rectangle<int> *ints = new Rectangle<int>(3, 4);
	Rectangle<double> *doubs = new Rectangle<double>(3.5, 4.75);
	cout << *ints;
	cout << *doubs;
}