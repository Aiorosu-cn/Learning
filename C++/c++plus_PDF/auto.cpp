//autoscp.cpp ---自动变量作用域
#include <iostream>
#include <stdio.h>
void oil(int x);
int main()
{
	using namespace std;
	
	int texas = 31;
	int year = 2011;
	cout << "In main() , texas = " << texas << ", &texas = ";
	cout << &texas << endl;
	printf ("In main() ,texas = %d , &texas = %p " , texas , &texas);
	
}
