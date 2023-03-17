

# INI文件

windows系统中用作简单配置用的一种文件格式，有两种ini文件，一种是系统ini文件，一种是自己定义的ini文件，唯一的区别是需要用不同的函数访问，否则会失败。

## ini的格式

```ini
[小节名 section]
键 = 值
```

在没有新的小节出现之前，所有的键值对归属于第一个它前面的小节
同一个小节之内配置项名字不要重复，不同小节之间可以重复

# 操作的函数

参数中文件的路径不支持相对路径，只支持全路径，

```CPP
//操作INI文件的主要函数：
GetPrivateProfileSection 读取ini文件中指定section的键值对
GetPrivateProfileSectionNames 读取ini文件所有的section name
GetPrivateProfileString 读取指定section的键值对的值

//既是写入函数也是删除函数，如果对应的值是空的话，将删除键，如果键名协程NULL，会删除整个小节。
WritePrivateProfileSection 替换ini文件中指定section的所有的键值对
WritePrivateProfileString 写入指定的键值对值到对应的section

//按照类型操作ini文件的
WritePrivateProfileStruct ，这是 把ini内容当做一个结构体来操作，比较复杂不是很好用
GetPrivateProfileInt  ， 把值当做整数来写
GetPrivateProfileStruct 

//操作winini的文件
GetProfileInt
GetProfileSection
GetProfileString
WriteProfileSection
WriteProfileString
```

例子：

 ```CPP
     //返回值表示的是得到结果的字节长度    
 	DWORD ret = GetPrivateProfileStringA(
     "小节2",//小节的名字
     "配置2",//配置项键的名字
     "读取失败",//读取失败的情况下默认返回的值
     buf,//读取到的结果的存储缓冲区
     MAX_PATH,//缓冲区大小
     filename.c_str());//文件的路径，要求全路径
 ```



函数列表

| 函数名                                                       | 头文件    | 作用                                                         |
| ------------------------------------------------------------ | --------- | ------------------------------------------------------------ |
| int _access(    const char *path,    int mode  );            | <io.h>    | mode 为0时,只判断文件是否存在,返回-1时文件不存在             |
| DWORD  GetPrivateProfileSectionNamesA(   [out] LPSTR   lpszReturnBuffer,   <br />[in]   DWORD nSize,   <br />[in]   LPCSTR lpFileName  ); | Windows.h | 读取所有section的名字,不包括方括号 。返回所有section的字符数量  将section下所有数据放在缓冲区中,不包括终止字符，读出来的结果是小节1\0小节2\0小节3\0\0，用\0做结果的区分，最后是2个\0。 |
| DWORD  GetPrivateProfileSectionA(   <br />[in]   LPCSTR lpAppName,   <br />[out] LPSTR   lpReturnedString,   <br />[in]   DWORD nSize,  <br /> [in]   LPCSTR lpFileName  ); | Windows.h | 检索初始化文件的指定部分的所有键和值。                       |
| DWORD  GetPrivateProfileStringA(  <br /> [in]   LPCSTR lpAppName,  <br /> [in]   LPCSTR lpKeyName,  <br /> [in]   LPCSTR lpDefault,  <br /> [out] LPSTR   lpReturnedString,  <br /> [in]   DWORD nSize,  <br /> [in]   LPCSTR lpFileName  ); |           | 从初始化文件的指定部分中检索字符串。    读取指定section的键对应的值  将键对应的值复制到缓冲区,不包括终止空字符  //小节的名字,如果为NULL,返回所有小节名字  //配置项键的名字,如果为NULL,返回所有键的名字  //读取失败的情况下默认返回的值  //读取到的结果的存储缓冲区  //缓冲区大小  //文件的路径，要求全路径 |
| WritePrivateProfileSection                                   | Windows.h | 替换ini文件中指定section的所有的键值对，                     |
| WritePrivateProfileStringA(<br />  LPCSTR lpAppName, <br /> LPCSTR lpKeyName,  <br />LPCSTR lpString, <br /> LPCSTR lpFileName    ); | Windows.h | 写入指定的键值对值到对应的section，  如果键名为NULL 小节会被删除  如果值为NULL，键会被删除  WritePrivateProfileStringA("小节2",NULL,NULL  , filename.c_str()); |
| GetCurrentDirectoryA( <br /> DWORD  nBufferLength,  <br /> LPSTR lpBuffer    ); |           | 获取文件的当前目录，但是不包括文件的名字    //如果是调试环境下，获取到的是配置项中调试选项中的工作目录    //如果是直接运行，获取到的是程序的运行目录 |
| errno_t fopen_s(    <br />FILE** pFile,   <br /> const char *filename,  <br />  const char *mode  ); |           | 与传统fopen相比多了第一个参数,                               |
| string::find()                                               |           | 搜索成功时，则为搜索的子字符串的首个字符的索引；否则为  npos。 |
| size_type find(    value_type char_value,    size_type offset = 0) const; |           | 注意还有个默认参数                                           |
| MAX_PATH                                                     |           | 系统支持的最长文件路径                                       |
| _access()                                                    |           | 判断文件是否存在，不等于-1就是存在的                         |





# 配置类封装

建立一个配置项类，随便给一个ini文件，可以通过函数解析成ini文件。

使用vector存储小节名字

使用map存储每个小节下的键值对

```CPP
//ini配置文件类
class ConfigINI
{
public:
	//解析一个任意未知内容的ini文件
	bool LoadINI(const char* inifile);
protected:
private:
	
};
```

## 小节名的读取

- 声明一块内存，大小和文件大小一样
- 使用获取小节名函数`GetPrivateProfileSectionNamesA`，获取小节名的API，存入内存中，里面有获取的所有小节名字

- 通过读内存出来的结果是`小节1\0小节2\0小节3\0\0`，用\0做结果的区分，最后是2个\0的特点，把每个小节名存在数组中，并且判断读完了。
- 通过找`=`来分割键和值；





## 键值对的读取

- 声明一块内存，大小和文件大小一样
- 使用获取键值对函数`GetPrivateProfileSectionA`，获取小节下所有键值对信息，也是以\0做分割。

> 跳点技巧：
>
> 使用函数读取到所有小节名字后,查找\0,然后利用string读取到\0会停止的特性,读取一个\0前的字符,然后移动指针位置,指向\0的下一个位置开始读取键值对的做法,通过寻找=,替换为\0,利用上面的方法一次次读取键值对;

```cpp
#include "MyConfig.h"
#include <windows.h>
#include <vector>
#include <string>
#include <io.h>
#include <map>

//获取文件大小
size_t GetFileSize(const std::string& filename)
{
	//判断文件是否存在
	if (_access(filename.c_str(), 0)!=-1)//不等于-1表示存在
	{
		FILE* pfile = nullptr;
		fopen_s(&pfile, filename.c_str(), "r");//文件打开模式,如果带+号一般会创建文件
		if (pfile!=nullptr)
		{
			//将读写位置移动到文件末尾
			fseek(pfile,0,SEEK_END);
			size_t pos = ftell(pfile);//得到的就是文件的大小
			fclose(pfile);
			pfile = nullptr;
			return pos;
		}
	}
	return 0;
}

//需要获取小节下所有的键值对的值
std::map<std::string, std::string> GetAllKeyValue(
	std::string inifile, //文件名
	std::string sectionname)//小节名
{
	//查找':'
	size_t isfind = inifile.find(':');
	if (isfind == std::string::npos)
	{
		//没有找到':'，说明不是全路径
		char filepath[MAX_PATH] = {};
		GetCurrentDirectoryA(MAX_PATH, filepath);
		std::string path = filepath;
		path += "\\";
		inifile = path + inifile;
	}

	//用于存储所有的小节名字的数组
	std::map<std::string, std::string> keyvalues;

	//获取一下文件的大小
	size_t fileszie = GetFileSize(inifile);
	if (fileszie == 0)
	{
		return keyvalues;
	}
	char* buf = new char[fileszie];
	GetPrivateProfileSectionA(
		sectionname.c_str(),buf,fileszie,inifile.c_str());
	for (int i = 0;i<fileszie;++i)
	{
		int k = 0;
		while (buf[i+k] != '\0')
		{
			++k;
		}
		std::string temp = &buf[i];//得到的是一整条键值对的信息
		//key=value;
		size_t equalpos = temp.find('=');
		buf[i + equalpos]='\0';
		std::string key=&buf[i];
		std::string value = &buf[i+equalpos+1];
		//将结果加入到键值对
		keyvalues[key]=value;
		i=i+k;
		if (buf[i+1]=='\0')
		{
			break;
		}
	}
	delete [] buf;
	return keyvalues;
}

//需要获取所有的小节的名字
std::vector<std::string> GetAllSectionNames(std::string inifile)
{
	//查找':'
	size_t isfind = inifile.find(':');
	if (isfind == std::string::npos)
	{
		//没有找到':'，说明不是全路径
		char filepath[MAX_PATH]={};
		GetCurrentDirectoryA(MAX_PATH,filepath);
		std::string path = filepath;
		path+="\\";
		inifile = path+inifile;
	}

	//用于存储所有的小节名字的数组
	std::vector<std::string> sections;

	//获取一下文件的大小
	size_t fileszie = GetFileSize(inifile);
	if (fileszie == 0)
	{
		return sections;
	}
	char* buf = new char[fileszie];
	GetPrivateProfileSectionNamesA(buf,fileszie,inifile.c_str());
	for (int i = 0;i<fileszie;++i)
	{
		int k = 0;
		while (buf[i+k]!='\0')
		{
			++k;
		}
		//跳出while的时候，就是得到了一个完整的小节名
		std::string temp = &buf[i];
		sections.push_back(temp);
		i = i+k;//跳到了'\0'的位置
		if (buf[i+1] == '\0')
		{
			//表示所有的小节名已经读取结束了
			break;
		}
	}
	delete [] buf;
	return sections;
}


bool ConfigINI::LoadINI(const char* inifile)
{
	std::vector<std::string> sections = GetAllSectionNames(inifile);
	for (auto& s:sections)
	{
		printf("[%s]\n",s.c_str());
		std::map<std::string,std::string> kvs = GetAllKeyValue(inifile,s);
		for (auto& kv:kvs)
		{
			printf("%s = %s\n",kv.first.c_str(),kv.second.c_str());
		}
	}
	return false;
}

```

