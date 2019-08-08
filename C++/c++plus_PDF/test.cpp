class Queue
{
private:
	struct Node{ Item item; struct Node * next;}	//这里只是定义了这个结构，而不是一个成员数据，这称为嵌套结构
	enum{ Q_SIZE = 10};
	Node * front ;
	Node * rear;
	int items;
	const int qsize;
public：
}

Queue::Queue(int qs):qsize(qs)
{
	front = rear = NULL;
	items = 0;
	qsize = qs;
}


class Classy
{
	int mem1 = 10;		//in-class initialization
	const int mem2 = 20;	//in-class initialization
}

Classy::Classy(): mem1(10), mem2(20){}

bool Queue::enqueue(const Item & item)
{
	if (iffull())
		return false;
	Node * add = new Node;	//creat node 
//on failure, new throws std::bad_alloc exception
	add->item = item;
	add->next = NULL;
	items++;
	if (front ==NULL)
		front = add;
	else
		rear->next = add;
	rear = add;
	return true;
}

bool Queue::dequeue(Item & item)
{
	if(front == NULL)
		return false;
	item = front->item;
	items--;
	Node * temp = front;
	front = front ->next;
	delete temp;
	f(items == 0)
		rear = NULL;
	return true;
}

