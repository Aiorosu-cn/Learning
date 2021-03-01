//stack.h --class definition for the stack ADT
#ifndef STACK_H_
#define STACK_H_

typedef unsigned long Item;

class Stack
{
private:
	//static const int MAX = 10;
	enum {MAX = 10};
	Item items[MAX];
	int top;
public:
	Stack();
	bool isempty() const; //the function will not change invoking object and can't call noconst function
	bool isfull() const;	//the function will not change invoking object and can't call noconst function
	//push() returns false if satack already is full,true otherwise
	bool push(const Item & item); //aviod change reference
	//pop() returns false if stack already is empty, true otherwise
	bool pop(Item & item);
};
#endif
