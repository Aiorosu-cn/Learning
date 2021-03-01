#include "tabtenn0.h"
#include <iostream>

TableTennisPlayer::TableTennisPlayer(const string & fn , const string & ln): firstname(fn), lastname(ln), hasTable(ht){}

void TableTennisPlayer::Name() const{
	std::cout << lastname << ", " << firstname;
}

