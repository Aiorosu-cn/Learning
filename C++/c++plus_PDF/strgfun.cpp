#include<iostream>
using namespace std;
unsigned int c_in_str(const char * str , char ch);

int main(){
	char mmm[15] = "minimun";
	//show system srequire preceding char with static to
	//inable array initialization
	char * wail = "ululate";
	unsigned int ms = c_in _str(mmm,'m');
}

unsigned int c_in_str(const char * str , char ch){
	unsigned int count = 0;
	while(*str){
		if(*str == ch)
			count ++;
		str++;	.	//mover pointer to next char
	}
	return count;
}