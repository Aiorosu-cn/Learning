//filefunc.cpp -- function with ostream & parameter
//使用ostream 引用参数的函数，参数为父类，可以接受父类或子类（派生类）的对象
#include <iostream>
#include <fstream>
//cstdlib为数学函数库，提供
#include <cstdlib>
using namespace std;
//定义函数，行参为输出的对象，物镜焦距，目镜焦距，输出的数据的量
void file_it(ostream & os , double fo ,const double fe[] ,int n);
const int LIMIT = 5;
int main(){
	ofstream fout;
	const char * fn = "ep-data.txt";
	fout.open(fn);
	if (!fout.is_open()){
		cout << "can't open " << fn << ".bye.\n";
		exit(EXIT_FAILURE);
	}
	double objective;
	//输入你的物镜焦距
	cout << "enter the focal length of your telescope objective in mm: ";
	cin >> objective;
	double eps[LIMIT];
	//输入你的目镜焦距,以毫米作单位，5个目镜
	cout << "enter the focal lengths , in mm , of " << LIMIT << " eyepieces: \n";
	for (int i = 0 ; i < LIMIT ; i++){
		cout << "eyepieces #" << i+1 << ": ";
		cin >> eps[i];
	}
	file_it(fout , objective , eps ,LIMIT);
	file_it(cout , objective , eps ,LIMIT);
	cout << "Done \n";
	return 0;
}
//os是你的输出方式，他可以是cout ，也可以是fout，
void file_it(ostream & os , double fo ,const double fe[] , int n)
{
	//创建一个fmtflage数据类型的对象initial，fmtflage是存储格式信息的数据类型
	ios_base::fmtflags initial;
	//setf可以设置各种格式化的状态，这里将初始的格式信息保存在initial中，并且设置为定点小数表示法
	initial = os.setf(ios_base::fixed);
	//设置定点小数的位数为0
	os.precision(0);
	os << "focal length of objective: " << fo << "  mm \n";
	//设置定点小数位数为1，先设置显示小数点
	os.setf(ios::showpoint);
	os.precision(1);
	//设置下一次输出操作使用的字段宽度，之再显示下一个值有效，然后将恢复到默认设置为0,类似于制表符的作用
	os.width(12);
	os << "f.1. eyepiece";
	os.width(15);
	os << "magnification" << endl;
	for (int i = 0 ; i < n ; i++){
		os.width(12);
		os << fe[i];
		os.width(15);
		os << int (fo/fe[i] + 0.5) << endl;
	
	}
	//重新初始化格式状态
	os.setf(initial);
}





