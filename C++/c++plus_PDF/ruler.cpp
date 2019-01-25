//ruler.cpp --using recursior递归
#include <iostream>
using namespace std;

const int Len = 66;
const int Divs = 6;
//输入数组，开始位置，结束位置，分割等级，将输入的数组中间下标改为字符“|”
void subdivide(char ar[],int low, int high ,int level);
int main(){
//创建基本64个空格的基本ruler字符串
	char ruler[Len];
	int i;
	for (i = 1 ; i < Len -2 ;i++)
		ruler[i]=' ';
	//字符串结尾66为\0
	ruler[Len-1] = '\0';
	int max=Len -2;
	int min = 0;
	//字符串0和65是|
	ruler[min] = ruler[max] = '|';
	//打印第一行数据
	cout << ruler << endl;
	//打印其他行
	//i为行数，除了第一排外还需要打6排	
	for( i =1 ; i <= Divs ; i++)
	{
	//以ruler为蓝本，创建一个层级为i的字符串
		subdivide(ruler,min,max,i);
		cout << ruler << endl;
		for(int j = 1 ; j < Len -2 ; j++)
			ruler[j]=' ';	
	}
	return 0;
}

void subdivide(char ar[],int low ,int high ,int level)
{
//当I为0时，将不打印
	if(level == 0)
		return;
//当I不为0（层数未消耗完）时，字符串以中间为标记一分为二，
//并中以间标记为准创建二个字符
	int mid = (high + low )/2;
	ar[mid] = '|';
	subdivide(ar ,low ,mid , level -1);
	subdivide(ar ,mid ,high , level -1);

}
