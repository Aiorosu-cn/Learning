[TOC]



# 函数对象

首先再看下函数指针

下列代码定义了一个指向返回值类型为int，参数为两个int的**函数指针变量**

```CPP
//返回值类型(*函数指针变量)([参数列表],...);//定义的函数指针变量的写法
int(*add)(int,int)=nullptr;
```
如果给他加上typedef，有了类型以后方便我们写回调函数的阅读性
```cpp
typedef 返回值类型(*函数指针类型)([参数列表],...);//定义的函数指针变量类型的写法
```

> using 也是C++11以后代替 typedef的， 
>
> using aaa = int;
>
> 前面是你定义的新名字，后面是原来的名字，要用using要先定义一个变量出来，用这个变量来获取他的类型
>
> ```cpp
> //decltype 获取传入的数据的变量类型，再用using定义了函数指针类型
> int(*padd)(int, int) = nullptr;
> using MyAdd = decltype(padd);
> MyAdd p = add;
> std::cout << p(123, 456) << std::endl;
> ```



函数对象是c++11以后推出的,函数对象:function,是一个模板类容器,可以存储函数指针变量，一共包括以下类型：

- 函数指针
  - 全局普通或者静态函数的指针
  - 类的普通成员函数指针
  - 类的静态成员函数指针
- 仿函数
- lambda表达式

好处在不同的类型函数可以汇总成一种写法

# 函数对象的用法

## 存储普通函数,约等于给不同的函数再命名

function存储类的普通[**区别于静态函数**]成员函数

必须保证的原则:类的普通成员函数,一定只有类对象实例才可以调用;

所以如果要用function存储累的普通成员函数,也必须依赖于具体的类对象实例;

由于累的普通成员函数是有隐藏参数this指针,所以在存储的时候也需要指明该参数的类型

```cpp
test t;
std::function<void(test*)> pf4 = &test::Print1; //存储的类的普通无参类型成员函数
```



```#include <functional>```函数对象的头文件

定义方式

```cpp
std::function <返回值类型([参数列表],...)> 函数对象变量;
//比如
std::function<bool(const int&, const int&)> pf1 = cmp1();//存储的仿函数对象
std::function<bool(const int&, const int&)> pf2 = cmp2; //存储的全局的普通函数
//函数指针也能存
bool(*pcmp)(const int&, const int&) = cmp2;
std::function<bool(const int&, const int&)> pf0 = pcmp;
std::function<bool(const int&, const int&)> pf0 = test::cmp2; //存储的类的静态成员函数
	//调用测试
	printf("普通类型测试--------------------\n");
	pf0(1, 2);
	pf1(1, 2);
	pf2(1, 2);
	pf3(1, 2);
```



示例:

```cpp
bool cmp2(const int&a, const int& b)
{
    printtf("")
    return a <b;
}

class test
{
public:
	void print1()
    {
        //__FUNCTION__是C++已经定义的宏,用于表示调用了该宏的函数的名字
        printf("类中的普通无参成员函数",__FUNCTION__);
    }
    void print1(int a)
    {
        //__FUNCTION__是C++已经定义的宏,用于表示调用该宏的函数的名字
        printf("类中的普通有参成员函数",__FUNCTION__);
    }
    
}

//然后依次用函数对象来存储这些函数
```



## 存储类的普通无参类型成员函数

必须保证的原则：类的普通成员函数，**一定只有类对象实例**才可以调用
所以如果要用function存储类的普通成员函数，也必须依赖于具体的类对象实例
由于类的普通成员函数是有隐藏参数this指针，所以在存储的时候也需要指明该参数的类型

```cpp
test t;
std::function<void(test*)> pf4 = &test::Print1;//存储的类的普通无参类型成员函数
std::function<void(test*, int)> pf5 = &test::Print2;
std::function<int(test*, int, int)> pf6 = &test::Print3;
printf("\n类成员函数测试--------------------\n");
//调用测试
pf4(&t);
pf5(&t,0);
pf6(&t,0,0);
```



## 绑定类成员函数std::bind()

把类的成员函数绑定为和类无关的形式

函数是类成员函数不能直接赋值给原始的函数指针

stTextInfo最后一个参数填写的是原始的函数指针成员变量

std::bind(&类名::函数名,要绑定的类对象,std::placeholder::_n[...],);

```cpp
std::function<void()> pf7 = std::bind(&test::print1,t);
std::function<void(int)> pf8 = std::bind(&test::print2,t, std::placeholders::_1);
std::function<void(int,int)> pf9 = std::bind(&test::print3,t,std::placeholders::_1,std::placeholders::_2);

//像普通函数一样调用类的成员函数,和仿函数不一样,没有重载()运算符
pf7();
pf8(0);
pf9(0,0);
```

还可以改变函数的调用形式

```cpp
std::function<void(int)> pf10 = std::bind(&test::print3,t, std::placeholders::_1,10086);
std::function<void(int)> pf11 = std::bind(&test::print3,t, 10088,std::placeholders::_1);

	pf10(0);
	pf11(0);
```

这样在类里面,就可以提供这个方法

```cpp

std::function<int(int, int)> ;
```

## 如何判断绑定是否有效

```cpp
std::function<int(int, int)> pf13 = nullptr;
if(pf13.operator bool())//如果为真,表示有存储有效的值
```







# 仿函数

像函数一样,本质上是类重载了括号运算符,让类对象的调用看起来像调用函数一样

```cpp
class Cmp1
{
 public:
    bool operator()(int a, int b)	//重载了括号运算符
    {
     	return a <b ;
	}
}

//调用
int a1,a2;
Cmp1 c;
if(c(a1,a2))	//像不像调用一个函数
{
    ...;
}
```

## 仿函数的应用

list的sort和算法头文件中的std::sort,这两个函数都支持:函数指针,仿函数和 lambda表达式

```cpp
std::list<int>a = {1,3,54,56,6,7,7};
a.sort(Cmp1());//这里面是个构造函数,创建一个对象
```

# lambda 表达式

又叫**匿名函数**,**闭包**等等,本质上来讲是包装了仿函数对象的语法糖

语法糖就是用起来写法很舒服,但他使用的另外的东西

作用是可以在函数中写类似函数的东西;

格式：

捕获列表    |参数列表|操作符|返回参数类型|函数体|

`[caputrue](params)opt->{body;}`
捕获列表
参数列表
Opt 操作符
->ret 返回参数类型

捕获列表

>[] 不从外部获取任何变量
>
>[&] 外部捕获引用
>
>[=] 外部捕获副本,以=捕获的变量默认不能直接修改,这个和函数不一样,但是可以通过Opt 的可变操作符修饰
>
>[=,&var,...]
>
>在类中写=或者&或者this,,this默认被捕获

**lambda的真实本质是仿函数的模板类**

这样比一样精简了很多,不用专门写一个函数

```cpp
a.sort([](const int&a, const int&b){return a >b;});
```





# using和 decltype配合使用

如果要使用using, 要先定义一个变量出来,然后才能获取他的类型