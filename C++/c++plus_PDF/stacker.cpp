//stacker.cpp -- testing teh stack class
#include <iostream>
#include <cctype> 
#include "stack.h"
int main()
{
	using namespace std;
	Stack st; //creat an empty stack
	char ch;
	unsigned long po;
	cout << "please eenter 'A' to add a purchase order, \n" << "'P' to process a PO, or Q to quit.\n";
	while (cin>>ch && toupper(ch) !='Q')
	{
		while (cin.get() != '\n')
			continue;
		if (!isalpha(ch))
		{
			cout << '\a'; //ring bell
			continue;
		}
		switch(ch)
		{
			case 'A':
			case 'a':
				cout << "enter a po number to add: ";
				cin >> po;
				if (st.isfull())
					cout << "stack altead full\n";
				else
					st.push(po);
				break;
			case 'p':
			case 'P':
				if(st.isempty())
					cout << "stack already empty\n";
				else{
					st.pop(po);
					cout << "po #" << po << " popped\n";
				}
				break;
		}
		cout << "please enter A to add a purchase order,\n"
		<< "p to process a PO ,or Q to quit.\n";
	}
	cout << "bye\n";
	return 0;
}