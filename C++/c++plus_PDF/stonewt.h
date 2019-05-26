//stonewt.h --definition for the stonewt class
#ifndef STONEWT_H_
#define STONEWT_H_
class Stonewt
{
	private:
		static const int Lbs_per_stn = 14;
		int stone;
		double pds_left;	//fractonal prounds
		double pounds;
	public:
		Stonewt(double lbs);	//	constructor for double pouds
		Stonewt(int stn, double lbs);	//constructor for stone, lbs
		Stonewt();	//default constructor
		~Stonewt();
		void show_lbs() const;	//show weight in pound format
		void show_stn() const;	//show weight in stone format
};
#endif

