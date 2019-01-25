#include <windows.h>    //windows系统头文件

//主函数
int WINAPI WinMain(HINSTANCE hInstance,     //当前实例句柄
                   HINSTANCE hPrcInstance,  //先前实例句柄
                   LPSTR lpCmdline,         //命令行的指针
                   int nShowCmd)            //显示的格式
{
    //实例句柄：用来标志在window系统中每一个程序的身份证
    //有时候一个程序是可以同时打开几个
    //用窗口结构体定义一个具体的窗口出来
    //1.设计窗口
    WNDCLASSEX window;      //window就是我们需要的一个窗口
    //sizeof是一个专门计算内存大小的运算符
    window.cbSize           = sizeof(WNDCLASSEX);                       //窗口在内存中需要的内存大小
    window.cbClsExtra       =0;                                         //程序的附加内存,现在基本没有什么用
    window.cbWndExtra       =0;                                         //窗口的附加内存，现在基本没有什么用
    window.hbrBackground    =(HBRUSH)GetStockObject(WHITE_BRUSH);       //背景的画刷,GetStockObject检索预定义的备用笔和备用刷子
    window.hInstance        =hInstance;                                 //当前实例句柄
    window.style            =CH_HREDROW|CS_VREDRAW;                 //窗口的样式，通过水平和垂直两个方向来改变窗口的大小
    window.lpszClassName    =L"for our dream";                      //类名称
    window.hCursor          =NULL;                                  //鼠标的样式，自己定义
    window.hIcon            =NULL;                                  //像标，就是我们的图标
    window.lpszMenuName     =NULL;                                  //菜单
    window.lpfnWndProc      =WndProc;                               //窗口的过程函数,
    //2.注册窗口
    RegisterClassEx(&window);

    //3.创建窗口
    CreateWindow(L"for our dream",L"超级窗口",WS_OVERLAPPEDWINDOW);

    //4.显示窗口，更新窗口
    ShowWindow();
    UpdateWindow();

    return 0;
}
