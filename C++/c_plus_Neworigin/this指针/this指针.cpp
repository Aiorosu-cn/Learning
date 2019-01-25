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
	cout << "the value of <this> is : " << this << endl;
}


int main()
{
	Circle c;
	c.printRadiusOnly();
	cout << "the address of objece c is :" << &c << endl;

}
