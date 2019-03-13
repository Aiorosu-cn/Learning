//inline.cpp -- 使用内联函数
#include<iostream>
//一个内联函数的定义,注意分号的位置
inline double square(double x){return x * x;}

int main(){
	using namespace std;
	double a,b;
	double c = 13.0;

	a=square(5.0);
	b = square(4.5 + 7.5 ) ;
	cout << a << '\n' << b<< '\n'<< c;
	system("pause");
}