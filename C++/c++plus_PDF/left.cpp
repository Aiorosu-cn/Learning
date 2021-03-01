//创建默认参数的函数
#include <iostream>
#include <cstring>
const int ArSize = 80;
char * left(const char * str ,int n = 1);
int main()
{
	using namespace std;
	char sample[ArSize];
	cout << "enter a string: \n";
	cin.get(sample , ArSize);
	char * ps = left(sample , 4);
	cout << ps << endl;
	delete [] ps;
	ps = left(sample);
	cout << ps << endl;
	delete []ps ;
}
//函数的目的在于复制输入字符串的前n个字符
char * left(const char * str , int n)
{
	//如果输入的数字为负，返回空字符串
	if( n < 0 )
		n = 0;
	int len = strlen(str);
	n = (n < len)?n:len;
	char * p = new char[n+1];
	int i;
	//当输入的n大于原本的str时。这里str[i]被转换为表达式，也是结束条件之一。c语言中，0为false，非0为true。因为这里 i < n 永远为真，
	for (i = 0 ; i < n && str[i] ; i++)
		p[i] = str[i];
	while (i <=n)
		p[i++] = '\0';
	return p;
}
