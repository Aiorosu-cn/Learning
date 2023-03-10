[TOC]

# RGB结构

```cpp
#define RGB(r,g,b) ((COLORREF)(((BYTE)(r)|((WORD)((BYTE)(g))<<8))|(((DWORD)(BYTE)(b))<<16)))

COLORREF = unsigned long;
BYTE =  unsigned char;//1个字节
WORD = unsigned short;//2个字节16个位
DWORD = unsigned long;//在windows是4个字节
```

分析数据我们知道(这里是二进制)

传入的时候,是按照默认整数型传入的

数据在执行位运算的时候,会自动转换成4字节的整数类型.

> 00000000,00000000,00000000,rrrrrrrr
>
> |
>
> 00000000,00000000,00000000,gggggggg <<8
>
> |
>
> 00000000,00000000,00000000,bbbbbbbb << 16
>
> 结果就是
>
> 00000000,00000000,00000000,rrrrrrrr
>
> |
>
> 00000000,00000000,gggggggg,00000000
>
> |
>
> 00000000,bbbbbbbb,00000000,00000000,

这里我们可以看出,windows的RGB(r,g,b).其实内存中的保存是 0,b,g,r的数据结构,其实下面有一个隐式的转换让数据砍掉

```cpp
stColor32 
{
	union
	{
		unsigned char cc[4];
		int color32;
		struct
		{
			unsigned char a,b,g,r;
		};
	};
}COLOR32;
//我们的数据结构是 aaaaaaaarrrrrrrrggggggggbbbbbbbb;要达到和windows的RGB相同的数据样式
//我们需要让 a = r | g,让
```

我们输入时RGB格式,但是我们解析是按照COLOR32解析

他是1个int值,我们是4个char

```cpp
stColor32(int color)
	{
		a = (unsigned char)color;
		r = (unsigned char)color;
		g = (unsigned char)color;
		b = (unsigned char)0;
		a = a | r;
		r = g;
		g = 0;
		b = 0;
	}
```

```cpp
unsigned char color[4] = {r,g,b,a};
return 
```

