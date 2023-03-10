

[TOC]

# 什么是slate插件

*Slate*是使用C++代码来实现*Widget*功能的框架。*Slate*中已经有定义好的*Widget*元素可以使用，也可以使用这些*Widget*元素创建新的*Widget*

  

# 工程准备

- 下载UI源码
- 双击setup.bat,下载依赖
- 双击GenerateProjectFiles.bat,产生工程文件
- 编译工程文件

# UE中的UI模块

UE C++当中,UI使用**slateViewer**模块

使用win窗口程序显示UId



# C++配置slate

在buid.cs中添加`Slate,SlateCore,StandaloneRenderer`3个模块

incude  slate的头文件

编译核心object 和 applicationcore要设置为true

