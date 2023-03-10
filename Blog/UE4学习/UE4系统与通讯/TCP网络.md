[TOC]

# 添加核心模块

添加`Shockets 和 NetWorking`,这个更接近平台原生的网络通讯,和蓝图内置网络差别很大.

```c#
public class UESampleTcpTest : ModuleRules
{
	public UESampleTcpTest(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { 
			"Core", 
			"CoreUObject", 
			"Engine", 
			"InputCore", 
			"HeadMountedDisplay",
			"Sockets",
			"NetWorking"
		});
	}
}
```



# 实现一个有网络功能的actor

UE的网络支持IPV4和IPV6;

连接服务器需要服务器的IP和端口

- 初始化
- 连接服务器(需要服务器的地址和端口)
  
- 断开连接
- 发送数据
- 检测连接状态
- 保持连接
- 连接成功后的反馈
- 被服务器踢下线

```cpp
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnRecvMsgDelegate,const FString&,recvMsg);
UCLASS()
class UESAMPLETCPTEST_API ASampleTCPActor : public AActor,public IRecvMsgInterface
{
	GENERATED_BODY()
    protected:
	class FSocket* socketfd;//UE4原生的套接字类型，用于网络通讯
	FString serverip;
	int32 serverport;
	bool isConnected;

	FOnRecvMsgDelegate _OnRecvMsgDelegate;
}
```

## 初始化

```cpp
//.h
UFUNCTION(BlueprintCallable, Category = "SampleTCPlient")
bool InitSocket();

//.cpp
bool ASampleTCPActor::InitSocket()
{
	//判断一下是否已经创建了
	if (socketfd != nullptr)
	{
		OffLine();//关闭可能的旧的服务器的连接
	}
	socketfd = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->
		CreateSocket(NAME_Stream, "SimpleTCPClient", false);

	return socketfd != nullptr;
}
```

## 连接服务器
- 连接服务器是一个耗时的过程,执行操作不会马上返回,可以写一个回调函数,连完后回调一下
- 具体方法可以写一个动态的委托,给一个参数,在连接服务器时把委托加进去
```cpp
bool ConnectServer(const FString& , int32 port, FOnRecvMsgDelegate onRevvMsgCallBack);

bool ASampleTCPActor::ConnectServer(const FString& ip, int32 port, FOnRecvMsgDelegate onRecvMsgCallBack)
{
	if (!InitSocket()){return false;}

	serverip = ip;
	serverport = port;

	FIPv4Address _ip;//创建了一个ipv4地址对象
	//将文本型ip地址解析为ipv4地址对象
	FIPv4Address::Parse(serverip,_ip);

	//创建一个FInternetAddr 网络地址信息(包含ip和端口)
	TSharedRef<FInternetAddr> addr = 
		ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();

	addr->SetIp(_ip.Value);
	addr->SetPort(serverport);

	//使用套接字使用当前地址信息进行连接
	isConnected = socketfd->Connect(*addr);
	if (isConnected)
	{
		//将套接字设置为非阻塞型的网络
		socketfd->SetNoDelay(true);
		socketfd->SetNonBlocking();
		//将回调进行赋值
		_OnRecvMsgDelegate = onRecvMsgCallBack;
		//连接成功了进行成功连接的回调
		OnConnect();
	}

	return isConnected;
}
```
## 断开连接
```cpp
//.h
void OffLine();

//.cpp
void ASampleTCPActor::OffLine()
{
	if (socketfd != nullptr)
	{
		socketfd->Close();
		isConnected = false;
	}

	ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->DestroySocket(socketfd);
	socketfd = nullptr;
	serverport = 0;
	serverip = "127.0.0.1";

	//直接调用我们刚刚BlueprintNativeEvent修饰的C++函数，只需要按照声明调用
	//如果蓝图重写了，就调用的是蓝图函数，如果没有重写调用就是C++中的函数
	OnDisConnect();
}
```
## 发送数据

方法有很多种,但基本原理就是发送字符

```cpp
//.h
bool SendMsg(const FString& msg);

//.cpp
std::string gb2312_to_utf8(std::string const& strGb2312)
{
	std::vector<wchar_t> buff(strGb2312.size());
#ifdef _MSC_VER
	std::locale loc("zh-CN");
#else
	std::locale loc("zh_CN.GB18030");
#endif

	wchar_t* pwszNext = nullptr;
	const char* pszNext = nullptr;
	mbstate_t state = {};
	int res = std::use_facet<std::codecvt<wchar_t, char, mbstate_t>>(loc).in(
		state,
		strGb2312.data(), strGb2312.data() + strGb2312.size(), pszNext,
		buff.data(), buff.data() + buff.size(), pwszNext);
	if (std::codecvt_base::ok == res)
	{
		std::wstring_convert<std::codecvt_utf8<wchar_t>> cutf8;
		return cutf8.to_bytes(std::wstring(buff.data(), pwszNext));
	}
	return "";
}

std::string utf8_to_gb2312(std::string const& strUtf8)
{
	std::wstring_convert<std::codecvt_utf8<wchar_t>> cutf8;
	std::wstring wTemp = cutf8.from_bytes(strUtf8);
#ifdef _MSC_VER
	std::locale loc("zh-CN");
#else
	std::locale loc("zh_CN.GB18030");
#endif

	const wchar_t* pwszNext = nullptr;
	char* pszNext = nullptr;
	mbstate_t state = {};
	std::vector<char> buff(wTemp.size() * 2);
	int res = std::use_facet<std::codecvt<wchar_t, char, mbstate_t>>(loc).out(
		state,
		wTemp.data(), wTemp.data() + wTemp.size(), pwszNext,
		buff.data(), buff.data() + buff.size(), pszNext);
	if (std::codecvt_base::ok == res)
	{
		return std::string(buff.data(), pszNext);
	}
	return "";
} 

bool ASampleTCPActor::SendMsg(const FString& msg)
{
	if (socketfd != nullptr && isConnected)
	{
		std::string cstr = TCHAR_TO_UTF8(*msg);
		std::string asci = utf8_to_gb2312(cstr);
		int32 sendBytes = 0;//实际发送数据的长度
		bool isok = socketfd->Send((const uint8*)asci.c_str(),asci.length(),sendBytes);
		return isok;
	}
	return false;
}



```
## 检测连接状态
```cpp
bool ASampleTCPActor::IsConnect()
{
	return isConnected;
}

```



## 连接成功后返回

BlueprintImplementableEvent在蓝图中定义

```cpp
//.h
UFUNCTION(BlueprintImplementableEvent, Category = "SampleTCPClient")
void OnConnect();//连接成功后返回成功

```

## 被服务器踢下线

```cpp
//.h
UFUNCTION(BlueprintNativeEvent, Category = "SampleTCPClient")
void OnDisConnect();//被服务器踢掉是未知的,需要检测到被服务器踢了后告诉我们被踢了

//.cpp

```





# 建立自己的测试服务器

 
