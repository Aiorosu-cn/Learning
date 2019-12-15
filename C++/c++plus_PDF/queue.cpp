//queue.cpp --Queue and Customer methods
#include "queue.h"
#include <cstdlib>

//Queue methods
Queue::Queue(int qs) : qsize(qs)
{
	front = rear = nullptr;
	items = 0;
}

Queue::~Queue()
{
	Node * temp;
	while (front != nullptr)
	{
		temp = front;	//save address of fronet item
		front = front -> next;	//reset pointer to nest item
		delete temp;
	}
}

bool Queue::isempty() const
{
	return items == 0;
}

bool Queue::isfull() const
{
	return items == qsize;
}

int Queue::queuecount () const 
{
	return items;
}

//Add item to queue
bool Queue::enqueue (const Item & item)
{
	if (isfull())
		return false;
	Node * add = new Node;	//creat node 
	//on failure , new throws std::bad_alloc exception
	add->item = item; //set node pointers
	add->next = nullptr;
	items++;
	if(front == nullptr)
		front = add;
	else
		rear->next = add;	 //else place at rear
	rear = add;
	return true;

}

//place front item into item variable and remove from queue
bool Queue::dequeue(Item & item)
{
	if (front == nullptr)
		return false;
	item = front->item;	//set item to first itme in queue
	items--;
	Node* temp = front ;
	front = front->next;
	delete temp;
	if(items == 0)
		rear = nullptr;
	return true;
}

//time set to a random value in the range 1-3
void Customer::set(long when)
{
	processtime = std::rand() % 3 + 1;
	arrive = when;
}

