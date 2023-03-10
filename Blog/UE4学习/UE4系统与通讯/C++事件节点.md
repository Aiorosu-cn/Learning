原文链接：https://blog.csdn.net/walsyker/article/details/113832252

[TOC]

# 事件

事件和委托类似,对于事件来讲,其实和委托用法一样

事件相比较委托,仅限在声明的地方使用

委托更加自由,可以不限于声明委托的地方使用

# 事件声明

事件的声明和 组播委托声明 方式几乎相同，唯一的区别是它们使用事件特有的宏变体。

- 第一个参数是类的名字
- 第二个参数是事件的名字

```cpp
DECLARE_EVENT( OwningType, EventName ) 创建一个事件。

DECLARE_EVENT_OneParam( OwningType, EventName, Param1Type ) 创建带一个参数的事件。

DECLARE_EVENT_TwoParams( OwningType, EventName, Param1Type, Param2Type ) 创建带两个参数的事件。

DECLARE_EVENT_Params( OwningType, EventName, Param1Type, Param2Type, …) 创建带 N 个参数的事件。

```

注：DECLARE_EVENT 宏的首个参数是"拥有"此事件的类，因此可调用 Broadcast() 函数。

# 事件绑定

事件绑定与 组播委托绑定 方式相同。

利用Add函数绑定函数



# 事件执行

事件允许**附带多个函数委托**，然后调用事件的 Broadcast() 函数将它们**一次性全部执行**。事件签名**不允许使用返回值**。对于事件而言，只有定义事件的类才能调用 Broadcast() 函数。