#include "Rectangle.h"

#include <iostream>
using namespace std;

Rectangle::Rectangle(int l, int w) 
{
  length = l;
  width = w;
}

Rectangle::Rectangle(const Rectangle &r)
{
  length = r.length; 
  width = r.width;
}

int Rectangle::getLength() { return length; }

int Rectangle::getWidth() { return width; }

int Rectangle::getArea() { return (length * width); }

int Rectangle::getPerimeter() 
{
  return ((2 * length) + (2 * width));
}

double Rectangle::getDiagonal()
{
  return (length * width / 2);
}

void Rectangle::setLength(int l) { length = l; }

void Rectangle::setWidth(int w) { width = w; }

bool Rectangle::isSquare() { return (length == width); }

ostream& operator<<(std::ostream& out, const Rectangle r)
{
  out << "Length: " << r.length << endl;
  out << "Width:  " << r.width << endl;

  return out;
}
