//use user's name as array's name
//int fill_array(double ar[] ,int limit)
#include<iostream>
const int Max = 5;
//function prototypes
int fill_array(double* ,int);
void show_array(const double ar[] ,int);
void revalue(double ,double ar[] ,int );

int main(){
	using namespace std;
	double properties[Max];

	int size = fill_array(properties, Max);
	show_array(properties , size);
	if(size > 0){
		cout << "enter revaluation factor: ";
		double factor;
		while (!(cin >> factor)){			//bad input
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "bad input ;please enter a number : ";
		}
		revalue(factor , properties ,size);
		show_array(properties , size);
	}
	cout << "Done.\n";
	cin.get();
	cin.get();
	return 0;
}

int fill_array(double ar[],int limit){
	using namespace std;
	double temp;
	int i;
	for(i = 0 ; i< limit ; i++)
	{
		cout << "enter value #" << (i+1)<< ": ";
		cin >> temp;
		if ( !cin){		//bad input
			cin.clear();   //清除EOF
			while(cin.get() != '\n')	//过滤掉多余的输入，只取输入的第一个字符
				continue;
			cout << "bad input ; input process terminated\n";
			break;
		}
		else if(temp < 0)
			break;
		ar[i]= temp;
	}
	return i;
}

//the following function can use,but not alter,
//the array whose address is ar
void show_array(const double ar[],int n){
	using namespace std;
	for (int i = 0 ; i< n ; i++){
		cout << "property #" << (i + 1) << ": $";
		cout << ar[i] << endl;
	}
}
//multiplies each element of ar[] by r
void revalue(double r, double ar[], int n){
	for (int i = 0 ; i < n ; i++)
		ar[i] *= r;
}
	
