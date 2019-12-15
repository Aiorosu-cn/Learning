#include <iostream>
using namespace std;

class one
{
	public:
		one(){};
		virtual void show(int a){cout << "one int a " << endl;}
		virtual void show(double b){cout << "one double"<<endl;}
		virtual ~one(){}
};

class two:public one
{
	public:
		two(){};
		virtual void show(int a){cout << "two int a" << a ;}
};

int main()
{
	two b;
	b.show(2.13);
	return 0;
}


