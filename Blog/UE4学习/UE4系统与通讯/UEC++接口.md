

[TOC]

# C++中其他调用蓝图函数的方法

## 使用BlueprintImplementableEvent修饰C++函数

- 仅在C++中声明,但是不能实现其定义
- 如果要实现定义,需要在蓝图中重写;

```cpp
UFUNCTION(BlueprintImplementableEvent)
    void OnConnect();
```



## 使用BlueprintNativeEvent

- 在C++中可以声明和定义函数
- 如果蓝图中重写了该函数,那么调用的时候不会选择调用C++中的定义,也就是蓝图中的函数会覆盖C++的定义
- 实现的时候要注意定义格式为`原生的名字_Implementation`;

```cpp
原生的名字_Implementation;
UFUNCTION(BlueprintNativeEvent, Category = "SampleTCPClient")
	void OnDisConnect();//被服务器踢掉
```

