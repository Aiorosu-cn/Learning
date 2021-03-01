#include <iostream>
const int ARSIZE = 8 ;
int sum_arr(int arr[] , int n);

int main(){
	using namespace std;
	int cookies[ARSIZE] = {1,2,4,8,16,32,64,128};
	cout << cookies << " = cookies \n";
	cout << sizeof cookies << " = sizeof cookies \n";
	int sum = sum_arr(cookies , ARSIZE);
	cout << "total cookies eaten :  " << sum << endl;
	sum = sum_arr(cookies , 3);
	cout << "firse three eater ate " << sum << "cookies \n";
	sum = sum_arr(&cookies[4], 4);
	cout << "last four eater ate " << sum << "cookies\n";
}


int sum_arr(int arr[] , int n){
	using namespace std;
	int total = 0 ;
	cout << arr << " = arr ; ";
	cout << sizeof (arr) << " = sizeof arr\n";
	for (int i =0 ; i < n ;i++)
		total = total + arr[i];
	return total;
}