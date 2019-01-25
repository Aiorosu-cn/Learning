#include <iostream>
#include "Circle.h"
#include "Circle.cpp"
int main()
{
	Circle c;
	c.printRadiusOnly();
	cout << "the address of objece c is :" << &c << endl;

	Circle c2;
	c2.printRadiusOnly();
}
