#include<iostream>
#include<iterator>
#include<vector>

int main()
{
	using namespace std;

	int casts[10] = { 6,7,2,9,4,11,8,7,10,5 };
	vector<int>dice[10];
	//��һ�����鸴�Ƶ�ʸ��;
	copy(casts, casts + 10, dece.begin());
	cout << "Let the dice be cast!\n";
	//����һ��ostream�����ĵ�����
	ostream_iterator<int, char> out_iter(cout, " ");
	//��ʸ���������Ƶ�ostream�ĵ�����
	copy(dice.begin(), dice.end(), out_iter);
	cout << endl;
	cout << "��ʽʹ�÷��� ������" << endl;
	copy(dice->rbegin(), dice->rend(), out_iter);
	cout << endl;
	cout << "��ʾ�������������\n";
	vector<int>::reverse_iterator ri;
	for (ri = dice.rbegin(); ri != dice.rend(); ++ri)
		cout << *ri << ' ';
	cout << endl;

}