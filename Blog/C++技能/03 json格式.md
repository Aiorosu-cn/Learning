# json介绍

json是 javaScript对象表示发
JSON 比 XML 更小、更快，更易解析。

json数据形式:

> 数据在键值对中
>
> 数据由逗号分割
>
> 大括号保存对象

json有5中类型,其中数组可以包括多个对象,对象里可以有多个键值对

> 数组:方括号括起来的
>
> 数字:没有引号
>
> 布尔:写true或false
>
> 字符串:双引号括起来
>
> 节点对象:Json::对象
>
> 空值:null

json是一个树形结构



# json格式

可以使用中括号或者`.`来访问对象的值

```javascript

var myObj, x;
myObj = { "name":"runoob", "alexa":10000, "site":null };
x = myObj["name"];
x = myObj.name;
//这里x都会获取name的值 runoob

```

JSON 中数组值必须是合法的 JSON 数据类型（字符串, 数字, 对象, 数组, 布尔值或 null）



应用很广泛:有在线格式化工具

各个语言都有支持json的库

c++ : jsoncpp库

安装库需要用cmake和python,需要下载





