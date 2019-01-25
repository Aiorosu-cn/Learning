#include <iostream>
#include "Circle2.h" 
#include "Circle2.cpp"
using namespace std;
int main(){
	Circle c ;
	c.print();

	c.setRadius( 10.0).setX(7.0).setY(8.0);
	c.print();
	return 0;
}