# 初始化

有时候自定义类无法使用花括号进行初始化

他的特殊性是C++11出现的

不然有的东西只能在初始化的时候用花括号初始,后面就不能用花括号了

```cpp
class test
{
    public:
    test()
    {
        pdata = nullptr;
        size = 0;
    }
    //相当于把参数打包传到vector里面
    test(std::initalizer_list<int>)
    {
        std::vector<int> a(1);
        size = a.size();
        if(size > 0)
        {
            pdata = new int[size];
            for(int i = 0;i < size;i++)
            {
                pdata[i] = a.[i];
                printf("%d",a[i]);
			}
            printf("\n");
        }
    }
    private:
    sizt_t size;
    int * pdata;
}
```

我希望是他能自动知道开5个堆,并支持花括号的赋值;

```cpp
int main()
{
    test a = {1,2,3,4,5};
}
```

