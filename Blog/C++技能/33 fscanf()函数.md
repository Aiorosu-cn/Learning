[TOC]

# 描述

C 库函数 **int fscanf(FILE \*stream, const char \*format, ...)** 从流 stream 读取格式化输入。

# 声明

下面是 fscanf() 函数的声明。

```
int fscanf(FILE *stream, const char *format, ...)
```

- **stream** -- 这是指向 FILE 对象的指针，该 FILE 对象标识了流。
- **format** -- 这是 C 字符串，包含了以下各项中的一个或多个：*空格字符、非空格字符* 和 *format 说明符*。

# 返回值

如果成功，该函数返回成功匹配和赋值的个数。如果到达文件末尾或发生读错误，则返回 EOF。