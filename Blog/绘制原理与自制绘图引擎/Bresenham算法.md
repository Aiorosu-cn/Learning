[TOC]

我们每个点和下一个点的关系,要么是和他平的,要么偏一个

思想是:我来判断,沿着x走时,y是变还是不变

好的地方在于通过特殊方法消掉0.5

有两种方法

> xi,yi,表示直线第i个像素坐标
>
> xi+1,yi+1表示坐标轴的第i+1个像素坐标
>
> 我们把理论上的线和xi+1的交点y记为y,和 y1的距离叫做d1,和y2的距离叫做d2
>
> 对比d1和d2,d1大x[i+1]对应y1,d2大就走y2
>
> 算d1 -d2
>
> 直线方程  y = kx + b 
>
> d1 = y - yi = kx[i+1] + b - yi
>
> d2 = y[i+1] - yi = y[i+1] - k[xi+1] - b
>
> **已知y[i+1] = yi + 1**,那么
>
> d1 - d2  =  kx[i+1] + b - yi - y[i+1] + kx[i+1] + b
>
> =  2kx[i+1] - 2yi + 2b - 1
>
> 已知 k = dy / dx,
>
> 两边同时乘以 dx,**消掉k**
>
> dx(d1 - d2) = 2 dy x[i+1] - 2 yi dx + 2 b dx - dx 
>
> **x[i+1] = xi +1**
>
> dx(d1 - d2) = 2 dy x[i+1] - 2 yi dx + 2 b dx - dx 
>
> 后面的部分是一个常量,用C表示
>
> C=  2 b dx - dx 
>
> 可以简化为
>
> dx(d1 - d2) = 2dyx[i+1] - 2dx yi + c
>
> 令 ei = dx( d1 - d2) = 2dyx[i+1] - 2dx yi + c
>
> e[i+1]= 2 dy x[i+1] - 2dx y[i+1] + C
>
> e[i+1] - e[i] = 2 dy(x[i+1] - x[i]) - 2 dx(y[i+1] - yi)
>
> e[i+1] = e[i] + 2 dy(x[i+1] - x[i]) - 2 dx(y[i+1] - yi)
>
> 已知  x[i+1] - xi = 1
>
> e[i+1] = e[i] + 2dy - 2dx(y[i+1] - yi)
>
> 当选择右方像素的时候
>
> e[i+1] = ei +2dy
>
> 当选择右上方的时候
>
> e[i+1] = ei + 2dy - 2dx



```cpp
void DrawLine_Bresenham(int x1, int y1, int x2 ,int y2, const COLOR32& color)
{
   //裁剪
	if (!_ClipLine(x1,y1,x2,y2))
	{
		return;
	}

	int dx = abs(x2 - x1);
	int dy = abs(y2 - y1);
	bool bInterchange = false;
	int e, signx, signy, temp;
	
     //各个象限都要适配,只需要搞变换的时候x是增加还是减小
	signx = (x2 > x1) ? 1 : (x2 < x1) ? -1 : 0;//判断x方向的遍历的话到底是增加还是减少或者不变
	signy = (y2 > y1) ? 1 : (y2 < y1) ? -1 : 0;//判断y方向的遍历的话到底是增加还是减少或者不变
	
    //有了上面以后,下面让他始终保持小的往大的变化
	if (dy > dx)
	{
		temp = dx;
		dx = dy;
		dy = temp;
		bInterchange = true;
	}
	e = -dx;
	int x = x1, y = y1;

	if (!bInterchange)//没有交换xy，所以按照x方向移动
	{
		for (int i = 0; i < dx; ++i)
		{
			mBufferArray[y][x] = color;
			x += signx;//按照x方向遍历，每次都改变x
			e += 2 * dy;
			if (e >= 0)
			{
				y += signy;//看情况改变y
				e -= 2 * dx;
			}
		}
	}
	else
	{
		for (int i = 0; i < dx; ++i)//已经交换了xy，这里是按照y遍历
		{
			mBufferArray[y][x] = color;
			y += signy;//按照y方向遍历每次都改变y
			e += 2 * dy;
			if (e >= 0)
			{
				x += signx;//看情况改变x
				e -= 2 * dx;
			}
		}
	}
    
    
    
    
   
}
```

