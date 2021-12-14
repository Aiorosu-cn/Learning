#include<iostream>
#include<iterator>
#include<vector>

int main()
{
	using namespace std;

	int casts[10] = { 6,7,2,9,4,11,8,7,10,5 };
	vector<int>dice[10];
	//从一个数组复制到矢量;
	copy(casts, casts + 10, dece.begin());
	cout << "Let the dice be cast!\n";
	//创建一个ostream容器的迭代器
	ostream_iterator<int, char> out_iter(cout, " ");
	//从矢量容器复制到ostream的迭代器
	copy(dice.begin(), dice.end(), out_iter);
	cout << endl;
	cout << "隐式使用反向 迭代器" << endl;
	copy(dice->rbegin(), dice->rend(), out_iter);
	cout << endl;
	cout << "显示声明反向迭代器\n";
	vector<int>::reverse_iterator ri;
	for (ri = dice.rbegin(); ri != dice.rend(); ++ri)
		cout << *ri << ' ';
	cout << endl;

}