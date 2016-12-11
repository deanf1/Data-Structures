#include "Car.h"

Car()
{
	type = ""; make = ""; model = ""; speed = 0;
}

Car(string t, string ma, string mo, size_t s)
{
	type = t;
	make = ma;
	model = mo;
	speed = s;
}