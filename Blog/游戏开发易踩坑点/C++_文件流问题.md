TXT文件内容

```txt
12
(-9,0)
(-2,-2)
(-2,2)
(-1,-1)
```

用C++文件流读取所有的数字

```cpp
	std::ifstream file(filename);
	//从文件读取字符
	int a,b
	file >> a;
	file >> b;
```

ifstream是按照换行或者空格来判定每次读取的数据,负数是可以解析的,但是上面不行,因为第二行开始有括号,导致无法读取

当我尝试用使用seekg跳过括号的时候,发现会失败

出问题的地方在于**使用`>>`读取文件时,文件的游标并会改变位置**,但是因为txt是/r/n,加上`(`一共是3个字符,所以需要跳跃3次

```cpp
file.seekg(1, std::ios_base::cur);//失败
file.seekg(3, std::ios_base::cur);//成功读取到b
```

修改循环,发现循环一次,游标就为-1了,说明文件读取失败,为啥?目前我解决不了,于是只能重新seek一下,最终这样能跑起来了

```cpp
for (int i = 0; i < mVertextNum; i++)
	{
		file.seekg(3, std::ios_base::cur);		//忽略(/r/n 和括号
		file >> mVertexts[i].x;
		file.seekg(1, std::ios_base::cur);		//忽略逗号
		file >> mVertexts[i].y;
		file.seekg(1, std::ios_base::cur);		//忽略)括号
		//a = file.tellg();  每次到这里就显示-1,文件就读到尾巴了,为什么为什么为什么为什么为什么
		file.seekg(0, std::ios_base::cur);
	}
```

