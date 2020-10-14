#include<iostream>
using namespace std;

/*定义和声明一个多参数模板函数，递归方式展开*/
void Show1(){}   //定义零个参数函数，递归调用到零个参数函数时。调用该函数，然后终止继续递归
template<typename T,typename ... Args>  //Args是一个模板参数包
void Show1(const T &value,const Args &... args)     //args是一个函数参数包
{
    cout<<"Show1 value=="<<value<<endl;
    Show1(args...);  //递归调用，依次展开每个参数。不能用args[2]方式调用，只能依次展开
}
 
/*定义和声明一个多参数模板函数，非递归方式展开*/
template<typename T>
void Print(T arg)
{
    cout<<"Show2 Print(arg)=="<<arg<<endl;
}
template<typename ... Args>
void Show2(Args ... args)
{
    int a[]={(Print(args),0)...};
    for(int i=0;i<sizeof(a);i++)
        cout<<"Show2 a["<<i<<"]=="<<a[i]<<endl;
}


template<typename T>
T sum(T t)
{
    return t;
}
template<typename T, typename ... Types>
T sum (T first, Types ... rest)
{
    return first + sum<T>(rest...);
}


#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <map>

// 在C++11之前，类模板和函数模板只能含有固定数量的模板参数。C++11增强了模板功能，允许模板定义中包含0到任意个模板参数，这就是可变参数模板。

// 可变参数模板和普通模板的语义是一样的，只是写法上稍有区别，声明可变参数模板时需要在typename或class后面带上省略号“...”
/*
省略号“...”的作用有两个：
    1)    声明一个参数包，这个参数包中可以包含0到任意个模板参数
    2)    在模板定义的右边，可以将参数包展开成一个一个独立的参数
*/
template<class ... T>
void func(T ... args) // T叫模板参数包，args叫函数参数包
{//可变参数模板函数

}


// 一个可变参数模板函数的定义
template<class ... T> 
void func1(T ... args)
{//可变参数模板函数
    //sizeof...（sizeof后面有3个小点）计算变参个数
    cout << "num = " << sizeof...(args) << endl;
}

// 通过递归函数展开参数包，需要提供一个参数包展开的函数和一个递归终止函数。
//递归终止函数
void debug()
{
    cout << "empty\n";
}

//展开函数
template <class T, class ... Args>
void debug(T first, Args ... last)
{
    cout << "parameter " << first << endl;
    debug(last...);
}

// 非递归方式展开
template <class T>
void print(T arg)
{
    cout << arg << endl;
}

template <class ... Args>
void expand(Args ... args)
{
    int a[] = { (print(args), 0)... };
}


void mytest()
{
    func1();     // num = 0
    func1(1);    // num = 1
    func1(2, 1.0);   // num = 2

    debug(1, 2, 3, 4);
    /*
    运行结果：
        parameter 1
        parameter 2
        parameter 3
        parameter 4
        empty
    */

    expand(1, 2, 3, 4);

    return;
}
 
/*调用按钮函数*/
int main()
{
    Show1(1,2.0,"33","string");
    Show2(66,8888.0,"dsd","sd545sd2s");

    cout<<sum(1,2,3,4)<<endl;//10

    mytest();

    return 0;

}
