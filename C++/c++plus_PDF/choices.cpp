//choices.cpp -- choosing a template
#include <iostream>
//返回值较小那个
template<class T>
T lesser(T a, T b)
{
	return a < b ? a : b ;
}
//取a,b的绝对值，返回绝对值最小那个
int lesser (int a ,int b){
	a = a < 0 ? -a : a;
	b = b < 0 ? -b : b;
	return a < b ? a : b;
}

int main(){
	using namespace std;
	int m = 20;
	int n = -30;
	double x = 15.5;
	double y = 25.9;

	cout << lesser(m, n)<< endl;
	cout << lesser(x, y)<< endl;
	cout << lesser<>(m, n) << endl;，，
	cout << lesser<int>(x, y) << endl;
}
