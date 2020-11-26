### 函数指针

[TOC]

#### (*(void(*)()) 0)() 含义
1. `void(*)()` 函数指针  
2. `(void(*)()) 0` 地址为0的函数指针
3. `*(void(*)()) 0` 地址为0的函数
4. `(*(void(*)()) 0)()` 地址为0的函数调用

#### 关于C语言函数传参现在汇总于下：
数据原型|应用|调用格式|声明格式
-------|----|-------|-------
int arr[3]|等价传递|foo(arr,3)|foo(int *p,int n)
int arr[3][4]|等价传递|foo(arr,3)|foo(int(*p)[4],int n)
int *p|等价传递|foo(p)|foo(int*p)
int *p= NULL|初始化|foo(&p)|foo(int**p)
int **p|等价传递|foo(p)|foo(int **p)
int **P=NULL|初始化|foo(&p)|foo(int ***p)
char *argv[4]|等价传递|foo(argv,4)|foo(char **p,int n)
char (*p)[4]|等价传递|foo(p)|foo(int(*p)[4])
void func(int ,int)|回调传递|foo(func)|void foo(void (*p)(int ,int))


#### myStrcmp
```cpp
int myStrcmp(const char * s1, const char * s2)
{
    // for(;*s1 && *s2; s1++,s2++) // 再简洁,该如何写呢？
    // {
    //     if(*s1 == *s2)
    //         continue;
    //     else
    //         return *s1 -*s2;
    // } 
    for(;*s1 && *s2 && *s1 == *s2; s1++,s2++);
    return *s1 -*s2;
}
```


