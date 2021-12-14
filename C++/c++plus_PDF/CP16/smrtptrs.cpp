#include<iostream>
#include <string>
#include <memory> //智能指针预编译头文件
using namespace std;

class Report
{
private:
	string str;
public:
	Report(const string s) : str(s){cout << "Object created!\n";}
	~Report(){cout <<"Object deleted!\n";}
	void comment() const{cout << str<< "\n";}
};

int main()
{
	/*
	{

		auto_ptr<Report> ps(new Report("using auto_ptr"));
		ps->comment(); //use-> to invoke a member function
	}
	*/
	{
		shared_ptr<Report> ps(new Report("using shared_ptr"));
		ps->comment(); 
	}
	{
		unique_ptr<Report> ps(new Report("using unique_ptr"));
		ps->comment();
	}
	return 0;
}
