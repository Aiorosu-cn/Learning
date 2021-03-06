//stonewt1.cp --stonewt methode 
#include <iostream>
using std::cout;
#include "stonewt.h"

//construct stonewt object from double value
Stonewt::Stonewt(double lbs)
{
	stone = int (lbs) / Lbs_per_stn;
	pds_left = int (lbs) % Lbs_per_stn + lbs - int(lbs);
	pounds = lbs;
}

//construct Stonewt object form stone, double values 
Stonewt::Stonewt(int stn, double lbs)
{
	stone = stn;
	pds_left = lbs;
	pounds = stn * Lbs_per_stn + lbs;
}

Stonewt::Stonewt()
{
	stone = pounds = pds_left = 0;
}

Stonewt::~Stonewt()
{
}
//show weight in stones
void Stonewt::show_stn() const
{
	cout << stone << " stone, " << pds_left << " poundes\n";
}

void Stonewt::show_lbs() const
{
	cout << pounds << " pounds\n";
}

Stonewt::operator int() const
{
	return int (pounds + 0.5);
}

Stonewt::operator double() const
{
	return pounds;
}
