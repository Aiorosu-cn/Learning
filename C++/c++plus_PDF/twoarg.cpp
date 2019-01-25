#include<iostream>
using namespace std;
void n_chars(char,int);

int main()
{
	int times;
	char ch;

	cout << "enter a character: ";
	cin >> ch;
	while (ch != 'q')
	{
		cout <<"enter a integer: ";
		cin >> times;
		n_chars(ch,times);
		cout << "\nenter another character or press the q-key to quit: ";
		cin >> ch;
	}
	cout << "the value of times is "<< times << ".\n";
	cout << "bye\n";
	return 0;
}

void n_chars(char c,int n)
{
	while (n-- > 0 ) //continue until n reaches 0
		cout << c;
}
