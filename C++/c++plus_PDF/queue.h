class Queue
{
private:
	struct Node{ Ttem item ; struct Node * next};
	enum{Q_SIZE = 10};
	Node * front;
	Node * rear;
	int items;
	const int qsize;
public:
	Queue(int qs = Q_SIZE):
	~Queue();
	bool isempty() const;
	bool isfull() const;
	int queuecount() const;
	bool enqueue( const Item & item);
	bool dequeue(Item & item);

}