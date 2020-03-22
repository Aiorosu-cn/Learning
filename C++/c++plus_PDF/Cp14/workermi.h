#ifndef WORKERNI_H_
#define WORKERMI_H_

#include <string>

class Worker
{
private:
    std::string fullname;
    long id;
protected:
    virtual void Date() const;
    virtual void Get();
public:
    Worker(): fullname("no one"), id(0L){}
    Worker(const std::string &s, long n): fullname(s), id(n){}
    virtual ~Worker() = 0;
    virtual void Set() = 0;
    virtual void Show() const = 0;

};

class Waiter: virtual public Worker
{
private:
    int panache;
protected:
    virtual void Date() const;
    virtual void Get();
public:
    Waiter(): Worker(), panache(0){}
    Waiter(const std::string &s, long n, int p = 0): Worker(s,n), panche(p){}
    Waiter(const Worker & wk, int p = 0):Worker(wk), panche(p){}
    virtual ~Waiter();
    virtual void Set() ;
    virtual void Show() const ;

};


class Singer: virtual public Worker
{
protected:
    enum{other, alto, contralto, soprano, bass, bartone, tenor, Vtypes};
    virtual void Date() const;
    virtual void Get();
private:
    static char *pv[Vtypes]; //string equivs of voice types
    int voice;

public:
//如何通过int类型转换为枚举量
    Singer(): Worker(), voice(other){}
    Singer(const std::string &s, long n, int v = other): Worker(s,n), voice(v){}
    Singer(const Worker & wk, int v = other):Worker(wk), voice(v){}
    virtual ~Singer();
    virtual void Set() ;
    virtual void Show() const ;

};

class SingerWaiter: public Singer, publice Waiter
{
protected:
    virtual void Date() const;
    virtual void Get();
public:
    SingerWaiter(){}
    SingerWaiter(const std::string &s, long n, int p = 0 , int v = other): Worker(s,n), Waiter(s, n, p), Singer(s, n, v){}
    SingerWaiter(const Worker & wk, int p =0, int v = other):Worker(wk), Waiter(wk, p), Singer(wk, v){}
    SingerWaiter(const Waiter & wt, int v = other):Worker(wt),Waiter(wt), Singer(wt, v){}
    SingerWaiter(const Singer & sg, int p =0):Worker(sg), Waiter(sg, p), Singer(sg){}


    virtual ~SingerWaiter();
    virtual void Set() ;
    virtual void Show() const ;

};

