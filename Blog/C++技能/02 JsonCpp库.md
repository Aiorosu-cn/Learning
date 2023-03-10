# JsonCpp库安装

## 使用cmake

使用cmake-gui安装,cmakelists在哪个路径就是哪个路径

点击configure,选平台和版本

出来的红色不是错误,是需要选的配置文件

最后一步键generate,就创建成功了

lib里有静态库和动态链接的引入库

最后要的是bin,example,include,lib4个文件夹



# 使用jsoncpp

在源码当中`json.h`文件为

```cpp
#ifndef JSON_JSON_H_INCLUDED
#define JSON_JSON_H_INCLUDED

#include "config.h"
#include "json_features.h"
#include "reader.h"
#include "value.h"
#include "writer.h"
```

由上可知jsoncpp有3种对象:

- value
- reader
- writer

> 包含头文件json.h
>
> 使用静态库的时候最好保持静态库的版本和使用库的vs版本要一致,不然可能编译错误,如果使用动态库那就没有问题
>
> json::value 是一个节点
>
> 使用R"()"原始字符串格式技巧
>
> 两种对象
>
> json::value和json::Reader,当使用reader可以解析



## 创建json格式的节点

```cpp
	Json::Value root;
	Json::Value data;
	root["test"] = "testdata";
	data["number"] = 1;
	root["data"] = data;
	root["test2"] = true;
//{"test":"testdata","data":{"number":1},"test2":true}
```



## 将节点序列化为字符串

使用writer,将

```cpp
	//将json对象序列化为字符串
	//使用旧的方法
	Json::FastWriter writer;//定义一个写出对象
	//将root json对象格式化为字符串
	std::string json_file = writer.write(root);
	printf("%s\n", json_file.c_str());
	//使用新的方法
	Json::StreamWriterBuilder builder;
	std::string json_file2 = Json::writeString(builder, root);
	printf("%s\n", json_file2.c_str());
```

## 写出到流对象

```cpp
//写出到流对象
	Json::Value root;
	Json::StreamWriterBuilder builder;
	const std::unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());

	root["name"] = "Mr·XIE";
	root["Age"] = 35;
	//写到输出流
	writer->write(root, &std::cout);
	//写到文件流
	std::fstream fs;//创建了一个文件流
	fs.open("test.json",std::ios::out);//打开了一个test.json的文件进行写出
	if (fs.is_open())//是否打开成功
	{
		writer->write(root, &fs);//将数据写出
		fs.close();//关闭文件
	}
```



## json字符串解析到json对象

```cpp
	//从json字符串解析到json对象

	Json::Value root;
	Json::Reader reader;
	//C++11引入了原始字符串格式，用户避免在字符串中加入转移字符\
	//const char* str1 = "test";
	//const wchar_t* str2 = L"test";//使用L在字符串前面表示该字符串是unicode字符，
	//const char* str = "{\"name\":\"Mr.XIE\",\"age\":35}";
	//const char* str3 = R"({"name":"Mr.XIE","age":35})";//表示原始字符串
	std::string jsonstr = R"({"name":"Mr.XIE","age":35})";
	if (reader.parse(jsonstr,root))
	{
		std::cout << root["name"].asCString() << "," << root["age"].asInt() << std::endl;
	}
```





## 判断json的语法错误

```cpp
//解析并报告错误
	//read from stream
	//调试时请将json文件拖放到执行文件或者设置命令行参数来进行测试
	Json::Value root;
	std::ifstream ifs;
	ifs.open(argv[1]);//argv[1] 通过命令行传入的文件路径

	Json::CharReaderBuilder builder;
	builder["collectComments"] = true;
	JSONCPP_STRING errs;
	if (!parseFromStream(builder, ifs, &root, &errs)) {
		std::cout << errs << std::endl;
		system("pause");
		return EXIT_FAILURE;
	}
	std::cout << root << std::endl;
```



