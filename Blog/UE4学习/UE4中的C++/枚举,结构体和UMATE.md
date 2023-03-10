[TOC]

# 枚举类型

- 枚举可以使用C++原生枚举类型
- 原生枚举,推荐使用C++类型,如果使用C类型枚举,简易用`namespace`包含一下,减少C类型枚举的不利

- 原生枚举需要用UENUM宏搭配BlueprintType才能给蓝图使用

```cpp
UENUM(BlueprintType)
    enum class ECurrentState:unit 8//意思枚举范围在unit 8 大小,即0-255范围
    {
        Idle UMETA(DisplayName = "空闲"),
    }
```

## 给蓝图使用枚举

```cpp
UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "XXX")
    ECurrentState MyECurrentState1 UMETA(DisName = "zzz");
UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "XXX")
    TEnumAsByte<ECurrentState> MyECurrentState2 UMETA(DisName = "YYY");
```



## 枚举常量值转换成字符串

因为通过配置文件配置枚举时,需要把枚举常量值和字符串做互相的转换

- 需要一个枚举

- 需要的枚举名字;
- 如果没找到是无效的;
- 如果找到了,通过指针获取名字并转换

```cpp
FindObject<UEnum>(ANY_PACKAGE, * Name, true)
```



# 结构体

- 如果要给蓝图使用,需要搭配BlueprintType
- 结构体值允许暴露部分属性
  - 属性需要UPROPERTY,和 UEC++类似
  - 如果UPROPERTY为空,蓝图图表无法访问,但是针对UE的反射,智能指针垃圾回收等可见
  - 如果没有UPROPERTY修饰,只能C++用;
- 名字要以F开头

```cpp
USTRUCT(BlueprintType)
    struct FMyStruct
    {
        GENERATOR_BODY()
        UPROPERTY()
            int32 MyIntValue;
    }
```



# UMETA

- UMETA扩展宏用于给成员定义别名
- 如果使用了中文需要将编码保存为UTF-8;

```cpp
UMATE(DisplayName = "别名");
```



