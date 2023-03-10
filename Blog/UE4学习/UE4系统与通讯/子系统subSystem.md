[TOC]

# 使用GameInstance的局限

每个项目当中,在项目设置中会有一个GameInstance;

GameInstance全局只有一个,我们写项目的时候,可能有各种不同的资源需要使用管理器,但管理器都用GameInstance是不行的.

# Subsystem基本概念

Subsysteme就是单例子系统,不用写构造和析构,有初始化和卸载的方法,可以用于各种资源的管理器

## 子系统类型

1. UEngineSubsystem;
2. UEditorEngineSubsystem; 
3. UGameInstanceSubsystem; 
4. UWorldSubsystem;
5. ULocalPlayerSubsystem;

前面两个是编辑器的

UWorldSubsystem是关卡的生命周期;

ULocalPlayerSubsystem是多人玩家中属于某个玩家的;

他们不同点在于生命周期不同;

子系统一划分就是不同生命周期的单例了,生命周期也归UE管理,我们重写主要就是初始化和反初始化函数

## 子系统的好处

- 自动实例化
- 托管生命周期

# 子系统的使用

子系统类只能在C++下创建

##  创建子系统

在UE里能用UE的数据类型就用UE的 

这三个是系统提供的可供重载的

```cpp
class SUBSYSTEMTEST_API UMusicExterGame: public Ugamexx
{
	GENERATEN_BODY()
	public:
	virtual bool ShouldCreateSubsystem(UObject* Outer) const override;
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

```
后面是可以自己写的函数

```cpp
public:
	UFUNCTION(BlueprintCallable,Category = "MusicExtern")
		bool IsBassInit();
	UFUNCTION(BlueprintCallable, Category = "MusicExtern")
		bool LoadMusic(const FString& musicpath);
	UFUNCTION(BlueprintCallable, Category = "MusicExtern")
		bool PlayMusic(const FString& musicpath,bool restart = true);
	UFUNCTION(BlueprintCallable, Category = "MusicExtern")
		bool StopMusic(const FString& musicpath);
	UFUNCTION(BlueprintCallable, Category = "MusicExtern")
		bool PauseMusic(const FString& musicpath);
private:
	bool isBassInit = false;
	TMap<FString,uint32> mMusic;
}
```

## 使用子系统
在蓝图中获取子系统