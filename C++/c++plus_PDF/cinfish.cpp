#include <iostream>
using namespace	std;

int main(){
	double fish[5];
	cout << "please enter the weights of your fish.\n";
	cout << "you may enter up to " << 5 << "fish <q to terminate>.\n";
	cout << "fish #1:	";
	int i = 0
	while (i < 5 && cin >> fish[i]){
		if( i <5 ){
			cout << "fish #" << i+1 <<";";	
		}
		i++;
	}
	double total = 0.0;
	for (int j = 0 ; j< i ; j++){
		total += fish[j];
	}
	if (i == 0){
		cout << "NO FISH";
	}else{
		cout << total / i << endl;
	}
	system("pause");
	return 0;
}