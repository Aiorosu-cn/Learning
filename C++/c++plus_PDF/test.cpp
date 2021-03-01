<<<<<<< HEAD
class Queue
{
private:
	struct Node{ Item item; struct Node * next;}	//这里只是定义了这个结构，而不是一个成员数据，这称为嵌套结构
	enum{ Q_SIZE = 10};
	Node * front ;
	Node * rear;
	int items;
	const int qsize;
public:

}

class one
{
	private:
		double i;
	public:
		one(double n):i(n){};
		one(){};
		virtual void show(){cout << i;};
};

class onepluse:public one
{
	private:
		double i;
	public:
		virtual void show(){cout << i+0.01;};
		onepluse(double n):i(n){};
};

int main()
{
	one * test[2];
	double num;
	int ty;
	for ( int i = 0 ; i < 2; i++)
	{
		cout << " input 1 use class one ,and input 2 use class oneplus! \n" << endl; 
		cin >>  ty;
		if ( ty == 1)
		{
			cout << "please input number  : ";
			cin >>  num ;
			test[i] = &one(num);
		}
		else if (ty == 2)
		{
			
			cout << "please input number  : ";
			cin >>  num ;
			test[i] = &onepluse(num);
		}
	}
	cout << "\n" << endl;
	for (int i = 0; i < 2; i++)
	{
		test[i]->show();
	}
}






