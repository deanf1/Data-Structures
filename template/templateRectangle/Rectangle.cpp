#ifndef RECTANGLE_CPP
#define RECTANGLE_CPP

#include "Rectangle.h"

#include <iostream>
using namespace std;

template <class T>
Rectangle<T>::Rectangle(T l, T w) 
{
  length = l;
  width = w;
}

template <class T>
Rectangle<T>::Rectangle(const Rectangle &r)
{
  length = r.length; 
  width = r.width;
}

template <class T>
T Rectangle<T>::getLength() { return length; }

template <class T>
T Rectangle<T>::getWidth() { return width; }

template <class T>
T Rectangle<T>::getArea() { return (length * width); }

template <class T>
T Rectangle<T>::getPerimeter() 
{
  return ((2 * length) + (2 * width));
}

template <class T>
T Rectangle<T>::getDiagonal()
{
  return (length * width / 2);
}

template <class T>
void Rectangle<T>::setLength(T l) { length = l; }

template <class T>
void Rectangle<T>::setWidth(T w) { width = w; }

template <class T>
bool Rectangle<T>::isSquare() { return (length == width); }

#endif
