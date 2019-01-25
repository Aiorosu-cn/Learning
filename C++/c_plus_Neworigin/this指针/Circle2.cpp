#include "Circle.h"
Circle::Circle( float _r, float _x ,float _y )
{
	radius = _r;
	x = _x;
	y = _y;
}

Circle& Circle::setRadius( float r )
{
	radius  = r ;
	return *this;
}

Circle& Circle::setX (float x )
{
	this->x = x ;
	return *this;
}

Circle& Circle::setY( float x )
{
	this->y = y ;
	return *this;
}

void Circle::print()const
{
	cout << x << "  " << y << "  " << radius << endl;
}