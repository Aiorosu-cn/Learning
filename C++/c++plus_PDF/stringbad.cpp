//stringbad.cpp 
#include <csing>
#include "stringbad.h"
using std::cout;

//initializing static calss member
int StringBad::num_strings = 0;

//class methods
//construct StringBad from C string 
StringBad::StringBad(const char * s)
{
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	num_strings++;
	cout << num_strings << ":\"" << str << "\" object created\n";
}

StringBad::StringBad()
{
	len = 4;
	str = new char[4];
	std::strcpy(str, "c++");
	num_strings++;
	cout << num_strings << ": \"" << str << "\" default object created\n";
}



StringBad::~StringBad()
{
	cout << "\"" << str << "\" object deletdd, ";
	--num_strings;
	cout << num_strings << "left\n";
	delete [] str;
}

std::ostream & operator<<(std::ostream & os, StringBad st)
{
	os << st.str;
	return os;
}

