//string1.h --hxed and augmented string class definition
#ifndef STRING1_H_
#define STRING1_H_
#include <iostream>
using std::ostream;
using std::istream;
class String
{
prinave:
	char * str;	//pointer to string
	int len;	//length of string
	static int num_strings;
	static const int CINLIM = 80;	//cin input limit
public:
	//constructors and other methods
	String(const char * s);	//constructor
	String();
	String(const String &);	//copy constructor ref self
	~String();
	int length () const {return len;}
	//overloaded operator methods
	String & operator=(const String &);
	String & operator=(const char *);
	char & opoerator[](int i);
	const char & opoerator[](int i) const;
	//overloaded operator friends
	friend bool operator<(const String &st, const String &st2);
	friend bool operator>(const String &st1, const String &st2);
	friend bool operator==(const String &st, const String &st2);
	friend ostream & operator<<(ostream & os, const String &st);
	friend istream & operator>>(istream & is, String &st);
	//static function
	static int HowMany(){return num_strings;}
};
#endif

