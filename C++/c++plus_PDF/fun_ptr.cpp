//函数指针
//coding=utf-8
#include<iostream>
using namespace std;

double betsy(int);
double pam(int);

//第二部分时指针指向double函数
void estimate(int lines,double (*pr) (int));

int main(){
	int code;
	cout << "有多少行代码";
	while(!cin>>code){
		cin.clear();
		while(cin.get() != '\n'){
			continue;
		}
		cout << "请输入数字: ";
	}
	// cin >> code;
	cout << "这是betsy's estimate:\n";
	estimate(code,betsy);
	cout << "这是pam's estimate: \n";
	estimate(code,pam);
}

double betsy(int lns){
	return 0.05 * lns;
}

double pam(int lns){
	return 0.03 * lns + 0.0004 * lns * lns;
}

void estimate(int lins,double (*pr)(int)){
	cout << lins << "行将会花费";
	cout << (*pr)(lins) << "小时\n";
}