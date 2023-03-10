[TOC]

直线的绘制

一种是沿着宽度找对应高度,

一种是沿着高度找对应宽度

绘制时起始要在像素中心,需要 + 0.5

浮点数计算,并且累计有误差

```cpp
void DrawLine(int x1, int y1, int x2, int y2, const COLOR32& color)
{
	//用斜率判断,情况考虑太多麻烦
    if(x1 == x2)//竖线
    {
        int ymin,ymax;
        ymin = min(y1,y2);
        ymax = max(y1,y2);
        for(int y = ymin; y < ymax ;++y)
        {
            memcpy(&mBufferArray[y][x1],&color,sizeof(COLOR32));
        }
    }
    else if(y1 == y2)
    {
         int xmin,xmax;
        xmin = min(y1,y2);
        xmax = max(y1,y2);
        for(int x = xmin; x < ymax ;++x)
        {
            memcpy(&mBufferArray[y1][x],&color,sizeof(COLOR32));
        }
    }
    
    //剩余的情况如果使用斜率来进行计算,从三角函数理解比较麻烦,4个象限都要考虑判断,不如直接用绝对值判断
    int dy = y1 - y2;
    int dx = x1 - x2;
    
    //同时计算绝对值
    int d_ax = abs(dx);
    int d_ay = abs(dy);    
    //根据绝对值的大小确定遍历的欢喜
    if(d_ax > d_ay)//按照x方向遍历
    {
        //数学上表示斜率,对我们来讲可以看成对应方向像素变换1个单位产生在另一个方向的增量
        float k = float(dy)/dx;
        int xmin,xmax;
        float y;
        if(x1 < x2)
        {
            xmin = x1;
            xmax = x2;
            y = float (y1);
		}
        else
        {
            xmin = x2;
            xmax = x1;
            y = float (y2):
        }
        
        for(int x = xmin; x < xmax; ++x)
        {
            memcpy(&mbufferArray[int(y)][x],&color,sizeof(COLOR32));
            y+=k;
        }
    }
    
}
```

但是有问题,会有一段是平的,线条会呈现明显阶梯状

因为思考的出发点不同,应该考虑像素点的中心为初始位置

优点:乘除法变成加法

缺点:浮点数会有误差,浮点数加法没有整数加法快