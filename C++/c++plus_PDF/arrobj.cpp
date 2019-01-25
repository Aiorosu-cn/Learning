#include<iostream>
#include<array>
#include<string>
using namespace std;

array<string,4> sname={"spring","summer","fall","winter"};
//function to modify array object
void fill(array<double , 4> *p);
//function to show array object
void show(array<double ,4> da); 
int main()
{
	array<double,4> cost;
	fill(&cost);
	show(cost);

}

void fill(array<double , season> *p)
{
	for(int i = 0 ; i< 4;i++)
	{
		cout<< "enter"<<sname[i]<<" cost : ";
		cin >>(*p)[i];
	}
}
//function to show array object
void show(array<double ,season> da)
{
	
}
