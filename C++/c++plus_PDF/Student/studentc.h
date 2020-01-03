//studentc.h --defing a student class using containment
#ifndef STUDENTC_H_
#define STUDENTC_H_

#include <iostream>
#include <string>
#include <valarray>

class Student
{
	private:
		typedef std::valarray<double> ArrayDb;
		std::string name;
		ArrayDB scores;
		//private method for scores output
		std::ostream & arr_out(std::ostream & os) const;
	public:
		Student():name ("Null Student"), scorse() {}
		explicit Student( const std::string &s):name(s), scores(){}
		explicit Student( const int n):name("Nully"), scores(n){}
		Student(const std::string &s , int n）：name(s),scorse(n){}
		Student(const std::stting &s, const ArrayDb &a ):name(s), scorse(a){}
		Student(const char* str, const double * pd, int n): name(str), scorse(pd,n){}
		~Student(){}
		double Average() const;
		const std::string & Name() const;
	//friends
		friend std::istream & operator>>(std::istream & is, Student & stu); //1 word
		friend std::istream & getline(std::istream & is, Student & stu); //1 line
		friend std::ostream & operator << (std::ostream & os, const Student & stu);

}；
#endif




