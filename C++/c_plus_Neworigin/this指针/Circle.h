#ifndef Circle_h
#define Circle_h

#include <iostream>
using namespace std;
class Circle
{
public:
	Circle();
	void printRadiusOnly();
private:
	float radius;
	float x_centre;
	float y_centre;
};
#endif/*Circle_h*/