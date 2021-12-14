//重载模板
#include <iostream>
//注意template模板的写法可以横着写一行
template <class T>void Swap(T &a , T &b);

template <class T>void Swap(T *a ,T *b, int n);

void Show(int a[]);
const int Lim =8;
int main()
{
	using namespace std;
	int i = 10 ,j = 20;
	cout << "i , j =" << i << " ," << j<< "\n";
	//后面省略
	
}
//重载模板的实现
template <class T>void Swap(T &a , T &b)
{
	T temp;
	temp = a ;
	a = b ;
	b = temp;	
}

template <class T>void Swap(T a[] ,T b[], int n)
{
	T temp;
	for (int i = 0; i < n ;i++)
	{
		temp = a[i];
		a[i] = b[i];
		b[i] = temp;
	}
}
