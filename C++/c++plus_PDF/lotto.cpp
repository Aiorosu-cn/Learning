//count probability 
#include <iostream>
long double probability(unsigned number , unsigned picks);
int main(){
	using namespace std;
	double total , choices;
	cout << "enter the total number of choices on the game card and\n the number of picks allowed:\n";
	while((cin >> total >> choices ) && choices <= total){
		cout << "you have one chance in ";
		cout << probability ( total ,choices);
		cout << " of winning\n";
		cout << "next two number ( q to quit): ";

	}
	cout << "bye\n";
}

	//the following function calculates 
	long double probability (unsigned number ,unsigned picks){
		long double result = 1.0;
		long double n;
		unsigned p;

		for (n = number , p = picks ; p> 0 ; n-- ,p--)
			result = result * n / p;
		return result;
	}
