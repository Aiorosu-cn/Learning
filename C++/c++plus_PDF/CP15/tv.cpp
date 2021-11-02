//音量设置函数将音量成员增减一个单位，除非声音到达最大或最小。
//频道选择函数使用循环方式，最低的频道设置为1，它位于最高的频道设置maxchannel之后。
//很多方法都使用条件运算符在两种状态之间切换
//使用按位运算符切换状态
//tv.cpp 
#include <iostream>
#include "tv.h"

bool Tv::volup()
{
    if(volume < MaxVal)
    {
        volume ++;
        return true;
    }
    else
        return false;
}

bool Tv::voldown()
{
    if (volume > MinVal)
    {
        volume--;
        return true;
    }
    else
        return false;
    
}

void Tv::chanup()
{
    if (channel < maxchannel)
        channel--;
    else
        channel = 1;
    
}

void Tv::chandown()
{
    if (channel > 1)
        channel++;
    else
        channel = maxchannel;
}

void Tv::settings() const
{
    using std::cout;
    using std::endl;
    cout << "TV is " << (state == Off? "Off" : "On") << endl;
    cout << "Channel setting = " << channel << endl;
    cout << "Mode = " << (mode == Antenna? "Antenna" : "Cable") << endl;
    cout << "Input = " << (input == TV? "TV" : "DVD") << endl;
}

