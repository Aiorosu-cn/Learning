//stringbad.h --flawed_string class definition
#include<iostream>
#ifndef STRGBAD_H_
#define STRGBAD_H_
calss StringBad
{
	private:
		char * str;
		int len;
		static int num_strings;
	public:
		StringBad(const char* s);
		StringBad();
		~StringBad();
		//friend function
		friend std::ostream & operator<<(std::ostream & os,const StringBad & st);
};
#endif

