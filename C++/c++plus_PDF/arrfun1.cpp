#include <iostream>

const int ARSIZE = 8;
int sum_arr(int arr[] , int n);

int main(){
	using namespace std;
	int cookies[ARSIZE]= {1,2,4,8,16,32,64,128};
	int sum = sum_arr(cookies , ARSIZE);

	cout << "total cookies eaten : " << sum << endl;
}

int sum_arr(int arr[] , int n){
	int total = 0 ;
	for (int i = 0 ; i<n ; i++)
		total = total + arr[i];
	return total;
}