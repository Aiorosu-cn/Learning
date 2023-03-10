[TOC]

[std::ref()和& - 简书 (jianshu.com)](https://www.jianshu.com/p/277675675593)

# 线程中不能使用引用

```cpp
#include <iostream>
#include <utility>
#include <thread>
#include <chrono>
#include <functional>
#include <atomic>

void f1(int n)
{
    for (int i = 0; i < 5; ++i) {
        std::cout << "Thread " << n << " executing\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

void f2(int& n)
{
    for (int i = 0; i < 5; ++i) {
        std::cout << "Thread 2 executing\n";
        ++n;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

int main()
{
    int n = 0;
    std::thread t1; // t1 is not a thread
    std::thread t2(f1, n + 1); // pass by value
    std::thread t3(f2, std::ref(n)); // pass by reference <---------------------------
    std::thread t4(std::move(t3)); // t4 is now running f2(). t3 is no longer a thread
    t2.join();
    t4.join();
    std::cout << "Final value of n is " << n << '\n';
}
```

标记中的这句，感觉使用了引用

`std::ref()`返回的不是对象的引用，返回的是什么？查一下手册可以发现：函数模板 `ref` 与 `cref` 是生成 [std::reference_wrapper](https://links.jianshu.com/go?to=https%3A%2F%2Fzh.cppreference.com%2Fw%2Fcpp%2Futility%2Ffunctional%2Freference_wrapper) 类型对象的帮助函数，它们用[模板实参推导](https://links.jianshu.com/go?to=https%3A%2F%2Fzh.cppreference.com%2Fw%2Fcpp%2Flanguage%2Ftemplate_argument_deduction)确定结果的模板实参。所以`std::ref()`返回的实际上是一个`reference_wrapper`而不是`T&`，可以从一个指向不能拷贝的类型的对象的引用生成一个可拷贝的对象。 `std::reference_wrapper` 的实例是对象（它们可被复制或存储于容器），但它们能隐式转换成 T& ，故能以之为以引用接收底层类型的函数的参数。

**`std::reference_wrapper` 用于按引用传递对象给 [std::bind](https://links.jianshu.com/go?to=https%3A%2F%2Fzh.cppreference.com%2Fw%2Fcpp%2Futility%2Ffunctional%2Fbind) 或 [std::thread](https://links.jianshu.com/go?to=https%3A%2F%2Fzh.cppreference.com%2Fw%2Fcpp%2Fthread%2Fthread) 的构造函数**