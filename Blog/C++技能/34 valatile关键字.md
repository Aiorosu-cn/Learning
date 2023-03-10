[TOC]

[C++ volatile 关键字 · v1otusc.github.io](https://v1otusc.github.io/2021/05/20/C++_Volatile_关键字/)

# 为什么使用volatile

这是 BS 在 “The C++ Programming Language” 对 volatile 修饰词的说明：

> A volatile specifier is a hint to a compiler that an object may change its value in ways not specified by the language so that aggressive optimizations must be avoided.
>
> volatile 说明符是对编译器的提示，表明对象可能会以语言未指定的方式更改其值，因此必须避免激进的优化

```cpp
volatile int i = 10; //使用关键字
int a = i;
int b = i;
```

上面的代码，编译器发现两次从 i读数据的代码之间的代码没有对 i 进行过操作，它会自动把上次读的数据（例如从 a 中读到的数据）放在 b 中。而不是重新从 i 里面读。如果 i是一个寄存器变量或者表示一个端口数据就容易出错，所以说 volatile 可以保证对特殊地址的稳定访问。

更多的可能是多线程并发访问共享变量时，一个线程改变了变量的值，怎样让改变后的值对其它线程 visible。一般说来，volatile 用在如下的几个地方：

- 中断服务程序中修改的供其它程序检测的变量需要加 volatile；
- 多线程间被几个任务共享的变量；
- 状态寄存器一类的并行设备硬件寄存器，因为每次对它的读写都可能有不同的意义。





# volatile指针