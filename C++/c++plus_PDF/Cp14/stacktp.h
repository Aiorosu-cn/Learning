//stacktp.h -- a stack template
#ifndef STACKTP_H_
#define STACKTP_H_
template <class T>
class Stack
{
	private:
		enum { MAX = 10 };
		Type items[MAX];
		int top;
	public:
		Stack();
		bool isempty();
		bool isfull();
		bool push(const T & item);
		bool pop(T & item);
};


