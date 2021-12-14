//ston.cpp user -defined conversion 
//compile with stonewt.cpp
#include <iostream>
#include "Stonewt.h"
using std::cout;
void display(const Stonewt & st, int n);
int main()
{
	Stonewt incognito = 275;
	Stonewt wolfe ( 285.7);
	Stonewt taft(21, 8);

	cout << "the celebrity weighed ";
	incognito.show_stn();
	cout << "the detectiv weighed ";
	wolfe.show_stn();
	cout << "the president weighed ";
	taft.show_lbs();
	incognito = 276.8;
	taft = 325;
	cout << "after dinner, the celebrity weighed ";
	incognito.show_stn();
	cout << "after dinner, the president weighed ";
	taft.show_lbs();
	display(taft, 2);
	cout << "the wrestler weighed even more.\n";
	display (422, 2);
	cout << "no stone left unearned\n";
	return 0;
}

void display ( const Stonewt & st, int n)
{
	for( int i = 0 ; i < n; i++)
	{
		cout << "WOW! ";
		st.show_stn();
	}

}

