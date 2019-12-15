#include <iostream>
#include "tabtenn0.h"

int main(void ){
	using std::cout;
	TableTennisPlayer play1("chuck", "blizzard", true);
	TableTennisPlayer play2("trar", "boomdesa", false);
	play1.Name();
	if (play1.HasTable())
		cout << ": has a table.\n";
	else
		cout << ": hasn't a table. \n";
	play2.Name();
	if (play2.HasTable())
		cout << ": has a table.\n";
	else
		cout << ": hasn't a table. \n";

	return 0;
	

}