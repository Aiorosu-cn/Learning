#ifndef TV_H_
#define TV_H_

class Tv
{
private:
    /* data */
    int state;  //on or off
    int volume; //assumed to be digitized 
    int maxchannel;  //maximum number of channels
    int channel;    //current channel setting
    int mode;   //boradcast or cable广播天线还是有线
    int input;  //TV or DVD 是TV输入还是 DVD输入， 
public:
    friend class Remote; //Remote can access Tv private parts
    enum {Off, On};
    enum {MinVal, MaxVal = 20};
    enum {Antenna, Cable};
    enum {TV, DVD};

    Tv(int s = Off, int mc = 125): state(s), volume(5), maxchannel(mc), channel(2), mode(Cable), input(TV){} //默认是TV模式，有线连接，音量为5，关闭状态，
    void onoff() {state = (state == On)? Off : On;} //三元表达式，巧妙利用枚举和布尔进行转换，如果是on则变成off
    bool ison() const {return state == On;}
    bool volup();
    bool voldown();
    void chanup();
    void chandown();
    void set_mode() {mode = (mode == Antenna)? Cable : Antenna;}
    void set_input() {input = ( input == TV)? DVD : TV;}
    void settings() const ; //display all settings
};

class Remote    //有元类，可以直接访问TV，为什么不是继承？继承你创建一个遥控器就要创建一个TV类，而遥控器并不一定只控制TV，在方法上输入输出并不是继承关系，
{private:
    int mode;      //控制TV还是DVD
public:
    Remote(int m = Tv::TV) : mode(m){}  //默认构造函数是传入一个TV对象，并强制转换为int类型，在定义前使用成员初始化列表，也就是传入了一个tv的mode值
    bool volup(Tv & t) {return t.volup();}  //remote使用tv对象引用为参数，表明遥控器必须针对特定的电视机
    bool voldown(Tv & t) {return t.voldown();} 
    void onoff( Tv & t){t.onoff();}
    void chanup(Tv & t) {t.chanup();}
    void chandown(Tv &t) {t.chandown();}
    void set_chan(Tv &t, int c) {t.channel = c;}
    void set_mode(Tv &t) {t.set_mode();}
    void set_input(Tv &t) {t.set_input();}
};



#endif
