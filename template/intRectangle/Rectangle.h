#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
using namespace std;

class Rectangle
{
 private:
  int length;
  int width;
 public:
  Rectangle(int length, int width);
  Rectangle(const Rectangle &r);
  int getLength();
  int getWidth();
  int getArea();
  int getPerimeter();
  double getDiagonal();
  void setLength(int l);
  void setWidth(int w);
  bool isSquare();
  friend ostream& operator<< (ostream& out, const Rectangle r);
};

#endif
