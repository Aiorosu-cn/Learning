//显示具体化模板练习
#include <iostream>
template<class T>void Swap(T &a ,T &b);

struct job
{
	char name[40];
	double salary;
	int floor;
};

template<>void Swap<job>(job &a ,job &b);
template<>void Swap(job &a ,job &b);
void Swap(job & , job &);

using namespace std;


int main()
{
	int a = 10;
	int b = 10;
	Swap(a,b);
	
	job sue;
	job sidney;
	Swap(sue,sidney);	
}


template<class T>void Swap(T &a ,T &b)
{
	cout << "使用模板"<< endl;
}

template<>void Swap<job>(job &a ,job &b)
{
	cout << "使用显式具体化"<< endl;
}

void Swap(job & , job &)
{
	cout << "使用函数" << endl;
}


