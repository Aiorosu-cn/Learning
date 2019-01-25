#include <iostream>
#include <fstream>
#include <cstdlib>
const int SIZE = 60;
int main(){
	using namespace std;
	char filename[SIZE];
	ifstream inFile;
	cout << "enter name of data file: ";
	cin.getline(filename, SIZE);
	inFile.open(filename);
	if (!inFile.is_open()){
		cout << "could not open the file " << filename  << endl;
		cout << "program terminating.\n";
		exit(EXIT_FAILURE);
	}
	double value;
	double sum = 0.0;
	int count = 0;

	inFile >> value;
	while (inFile.good()){
		++count;
		sum += value;
		inFile >> value;
	}
	if (inFile.eof())
		cout << "end of file reached.\n";
	else if(inFile.fail())
		cout << "input terminated by data mismatch.\n";
	else
		cout <<"inut terminated for unknow reason.\n";
	if (count == 0 )
		cout << "no data processed.\n";
	else{
		cout << "items read: " << count << endl;
		cout << "sum: " << sum << endl;
		cout << "average : " << sum/count << endl;
	}
	inFile.close();
	return 0;
}

