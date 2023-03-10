[TOC]

# 通过换元,消掉0.5和 dx造成的浮点数

[原贴](https://blog.csdn.net/SX2101111/article/details/123722418)

该算法相较于其他直线绘制算法摆脱了直线方程式的使用，通过换元的思想实现整数加法的迭代。

一.Bresenham算法

前提条件k∈[0,1]，直线在x方向上每次增量为\Delta x=1，在y方向上每次的增量为\Delta y=k。通过一个变量d将y方向上的累计增量记录下来，当d大于1时，标记点m进1，并对变量d进行-1操作使得d的范围永远保持在[0,1]之间。并根据d的范围确定最终的y值，当d\leq 0.5时，则y保持不变；当d>0.5时，y加1。

上述已经能够完成y值的判定，但是存在两个问题：k可能为浮点数、d每次需要同0.5这一浮点数比较大小。由于计算机计算整数的效率比浮点数速度快，因此要对上式进行优化改进，主要通过两步换元。

1.令e=d-0.5

    d_{0}=0                                           \rightarrow e_{0}=-0.5
    
    d_{i+1}=d_{i}+k                               \rightarrowe_{i+1}=e_{i}+k
    
    d=d-1 (d>1)                         \rightarrowe=e-1(e>0.5)
    
    m_{0}=y_{0}                                         \rightarrowm_{0}=y_{0} 
    
    m_{i+1}=m_{i}+1(d>1)                 \rightarrowm_{i+1}=m_{i}+1(e>0.5)             
    
    y_{i+1}=\left\{\begin{matrix} m_{i}+1 &(d>0.5) \\ m_{i}& (d\leqslant 0.5) \end{matrix}\right.              y_{i+1}=\left\{\begin{matrix} m_{i}+1 &(e>0) \\ m_{i}& (e\leqslant 0) \end{matrix}\right.

此次换元将d同0.5浮点数的判断转变成了e与0的判断。但是出现了新的问题e_{0}的初值为浮点数、e要同0.5比较来决定是否-1，以及一开始遗留的k可能为浮点数的问题

2.令t=2e\Delta x（△x>0）

     e_{0}=-0.5                                    \rightarrowt_{0}=-\Delta x
    
     e_{i+1}=e_{i}+k                               \rightarrowt_{i+1}=t_{i}+2\Delta y
    
     e=e-1(e>0.5)                      \rightarrowt=t-2\Delta x(t>\Delta x)
    
     m_{0}=y_{0}                                        \rightarrowm_{0}=y_{0} 
    
     m_{i+1}=m_{i}+1(e>0.5)             \rightarrowm_{i+1}=m_{i}+1(t>\Delta x)      
    
     y_{i+1}=\left\{\begin{matrix} m_{i}+1 &(e>0) \\ m_{i}& (e\leqslant 0) \end{matrix}\right.               y_{i+1}=\left\{\begin{matrix} m_{i}+1 &(t>0) \\ m_{i}& (t\leqslant 0) \end{matrix}\right.

 该换元的思想主要有两方面，一是乘2操作以消除0.5，二是将斜率k分解为△x和△y以便调整参数取整。此时Bresenham算法中已做到只对整数进行运算，完全消去了浮点数。

二.例题推导

A(0,0)、B(10,8)、斜率k=0.8，取△x=5、△y=4
t	-5	3	1	-1	-3	5	3	1	-1	-3	5
m	0	0	1	2	3	3	4	5	6	7	7
y	0	1	2	2	3	4	5	6	6	7	8

三.直线算法总结

DDA：先求出斜率k，每进给△x=1，y方向加k，int(y+0.5)向下取整得出目标y值。缺点：k可能为浮点值，0.5为浮点值，涉及到浮点加法。

中点画线法：先求A、B值取整，不断迭代d点，根据d点值确定y值。

Bresenham：将k分解取整，m点为标记点，t决定是否+1确定y值。

这三类算法中，综合比较中点画线法具备整数加法运算同时控制数仅有1个，因此运算效率上最优。从直线画线法得到的启发：数值迭代思想、浮点数分解为整数思想
————————————————
版权声明：本文为CSDN博主「着风少年」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/SX2101111/article/details/123722418





>
>
>要判断 d 是否大于0.5,就需要判断dy 是否大于2dx