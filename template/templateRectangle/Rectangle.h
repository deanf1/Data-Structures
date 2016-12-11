#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
using namespace std;

template <class T>
class Rectangle
{
 private:
  T length;
  T width;
 public:
  Rectangle(T length, T width);
  Rectangle(const Rectangle &r);
  T getLength();
  T getWidth();
  T getArea();
  T getPerimeter();
  T getDiagonal();
  void setLength(T l);
  void setWidth(T w);
  bool isSquare();
  friend ostream& operator<< (ostream &out, const Rectangle &r)
  {
	out << "Length: " << r.length << "\nWidth: " << r.width << endl;
	return out; 	
  }
};

#include "Rectangle.cpp"
#endif
