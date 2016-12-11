#ifndef CAR_H
#define CAR_H

#include <string>
#include <iostream>

using namespace std;

class Car
{
	public:
		Car();
		Car(string t, string ma, string mo, size_t s);
		
		void setType(string t) { type = t; }
		void setMake(string m) { make = m; }
		void setModel(string m) { model = m; }
		void setSpeed(size_t s) { speed = s; }
		
		string getType() { return type; }
		string getMake() { return make; }
		string getModel() { return model; }
		size_t getSpeed() { return speed; }
		
	private:
		string type;
		string make;
		string model;
		size_t speed;
}

#endif