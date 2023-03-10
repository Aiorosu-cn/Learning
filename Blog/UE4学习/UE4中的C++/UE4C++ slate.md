[TOC]

# slate

UMG中,的UI可以接收多个布局;

创建widget类型,会添加S开头;

# slate需要添加模块

添加slate 和 slateCore模块







# 构造带参的slate对象



Slate_Begin_ARGS()是默认的无参,要设置有参的,需要用到

Slate_ARGUMENT();



## 设置属性

UI的标题,

```cpp
```

## 子物体 ChildSlot

使用SNaw或者SAssignNew();

- SNaw,创建对象但是不给控制权,不会得到额外的控件变量
- SAssignNew(),两个参数,一个对象和创建的对象存在哪个变量

