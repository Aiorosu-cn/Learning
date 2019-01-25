#ifndef _test_Circle_
#define _test_Circle_

#include <iostream>
using namespace std;

class Circle
{
public:
	Circle(float radius=0.0 , float x = 0.0 , float y = 0.0 );
	Circle& setRadius( float r );
	Circle& setX( float x );
	Circle& setY( float y );
	void print()const;

private:
	float radius;
	float x;
	float y;
};

#endif