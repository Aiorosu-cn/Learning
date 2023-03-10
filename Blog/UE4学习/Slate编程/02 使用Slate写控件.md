[TOC]

# 继承 UI

大部分的的UI类在**Runtime/Slate/public/Widgets/**中



# 创建一个button

创建的基本思路就是在生成的windows中生成

```cpp
TSharedPtr<SWindwo> MainWindows = SNew(SWindow).ClientSize(FVector2D(800,600))
[MyButton.ToSharedRef()];
```





# 创建布局 Canvas

