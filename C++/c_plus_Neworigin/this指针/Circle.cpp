#include "Circle.h"
Circle::Circle()
{
	radius = 10.0;
	x_centre = 0.0;
	y_centre = 0.0;
}

void Circle::printRadiusOnly()
{
	//隐式使用this指针
	cout << "radius : " << radius << endl;
	cout << "this->radius : " << this->radius << endl;
	cout << "(*this).radius : " << (*this).radius << endl;
	//测试this指针的值
	cout << "the value of this is : " << this << endl;
}