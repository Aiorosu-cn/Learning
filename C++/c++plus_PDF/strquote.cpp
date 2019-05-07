//strquote.cpp -- different designs
#include <iostream>
#include <string>
using namespace std;
string version1(const string & s1, const string & s2);
const string & version2(string & s1, const string & s2);	//hass side effect 
const string & version3(string & s1 , const string & s2);	//bad design

int main(){
	string input;
	string copy;
	string result;

	cout << "Enter a string: ";
	getline(cin , input);
	copy = input;
	cout << "Your string as entered : " << input << endl;
	result = version1(input , "***");
	cout << "Your string as enhanced : " << result << endl;
	cout << "Your original  string : " << input << endl;

	result = version2(input , "###");
	cout << "Your string as enhanced : " << result << endl;
	cout << "Your original  string : " << input << endl;

	cout << "Resetting original string .\n";
	result = version3(input , "@@@");
	cout << "Your string as enhanced : " << result << endl;
	cout << "Your original  string : " << input << endl;

}

string version1(const string & s1, const string & s2){
	string temp;

	temp = s2 + s1 + s2;
	return temp;
}
const string & version2(string & s1, const string & s2){
	s1 = s2 + s1 + s2;
	//返回引用对于函数方法是安全的
	return s1;
}
const string & version3(string & s1 , const string & s2){
	string temp;

	temp = s2 + s1 + s2;
	//返回局部变量的引用是不安全的
	return temp;
}