//输入10个数字，计算和
//如果遇到输入错误，要提示输入错误，并能继续输入
//如果遇到字符exit,可以退出输入 
#include <iostream>
using namespace std;
void ex_1();

int main(){
	cout << "测试cin.get方法";
	int num;
	cin.get(num);
	cout << num;		//测试cin.get()方法
	system("pause");
	
}

//遇到输入错误，提示输入错误，并能继续输入
void ex_1(){
	int num[10];
	for(int i = 0 ;i< 10 ;i++){
		while (!cin.get(num)){
			cout << "please enter right number";
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "please enter right number";
		}
	}

}

void ex_2(){

}
