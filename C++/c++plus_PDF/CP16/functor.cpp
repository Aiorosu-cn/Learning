//使用函数符(函数对象)思想,创建不同类的通用方法
#include<iostream>
#include<list>
#include<iterator>
#include<algorithm>

template<class T> class TooBig
{
	private:
		T cutoff;
	public:
		TooBig(const T& t):cutoff(t){}
		//一个谓词,看样子只需要一个参数,参数是类对象
		bool operator()(const T &v){return v > cutoff;}//可以使用 TooBig(int) 查看是否大于 某个值; 
};

void outint(int n){std::cout << n << " ";}

int main()
{
	using std::list;
	using std::cout;
	using std::endl;
	TooBig<int> f100(100);//cutoff == 100,意思limit == int 100;
	int vals[10] = {50,100,90,180,60,210,415,88,188,201};
	list<int> yadayada(vals, vals + 10); //range constructor ,创建一个名为 yadayada 的序列,并将其初始化为 vals 到 vals +10 的内容;
	list<int> etcetera(vals, vals + 10);
	cout << "Original lists:\n";
	for_each(yadayada.begin(), yadayada.end(),outint);
	cout << endl;
	for_each(etcetera.begin(), etcetera.end(),outint);
	cout << endl;
	yadayada.remove_if(f100);//使用一个已有名字的函数对象
	etcetera.remove_if(TooBig<int>(200)); //构造一个函数对象
	cout << "Trimmed lists:\n";
	
	for_each(yadayada.begin(), yadayada.end(),outint);
	cout << endl;
	for_each(etcetera.begin(), etcetera.end(),outint);
	cout << endl;
	return 0;		
}

