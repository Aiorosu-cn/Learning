#include<iostream>
#include<string>
using namespace std;

void display(const string sa[],int n);

int main(){
	string list[5];
	cout << "enter your 5 favoite :\n";
	for(int i = 0 ; i< 5 ;i++){
		cout << i + 1 << ": ";
		getline(cin,list[i]);
		cout << list[i] << endl;
	}
	cout << "you list : \n";
	display(list,5);
}

void display(const string sa[],int n){
	for (int i = 0 ; i< n ; i++)
		cout << i+1 << ": " << sa[i] << endl;
}
