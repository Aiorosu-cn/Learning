//queue.h --interface for a queue
#ifndef QUEUE_H_
#define QUEUE_H_
//this queue will contain customer items

class Customer
{
	private:
		long arrive;	//arrival time for customer
		int processtime;	//processing time for customer
	public :
		Customer(){arrive = processtime = 0;}
		void set( long when);
		long when () const { return arrive;}
		int ptime() const{ return processtime; }
};

typedef Customer Item;


class Queue
{
private:
	//class scope definitions
	//Node is a nested structure definition local to this c
	struct Node{ Item item ; struct Node * next ;};
	enum{Q_SIZE = 10};
	//private class members
	Node * front;
	Node * rear;
	int items;
	const int qsize;
public:
	Queue(int qs = Q_SIZE);
	~Queue();
	bool isempty() const;
	bool isfull() const;
	int queuecount() const;
	bool enqueue( const Item & item);
	bool dequeue(Item & item);

};
#endif

