#ifndef STCKTP1_H_
#define STCKTP1_H_

template <class Type>
class Stack
{
    private:
        enum{SIZE = 10} //default size
        int stacksize; 
        Type * items;   //holds stack items
        int top;        //index for top stack item
    public:
        explicit Stack(int ss = SIZE);
        Stack(const Stack & st);
        ~Stack(){delete [] intems;}
        bool isempty() {return toop ==0;}
        bool full(){return top == stacksize;}
        bool push(const Type & item);   //pop top into item
        Stack & operator= (const Stack & st);
};

template <class Type>
Stack<Type>::Stack (int ss): stacksize(ss), top(0)
{
    items - new Type [stacksize];
}

template<class Type>
Stack<Type>::Stack(const Stack &st)
{
    stacksize = st.stacksize;
    top = st.top;
    items = new Type [stacksize];
    for (int i = 0; i < top; i++)
    items[i] = st.items[i];

}
