/*bind是一个boost中的非常庞大的函数家族，其根据绑定的参数个数
 * 和绑定的调用对象的类型总共可分为数十个不同形式，是标准函数
 * std::bindist和bind2nd的泛化，其支持任意的函数对象、函数、
 * 函数指针和成员函数指针，还可给任意参数绑定特定值或将标准参数
 * 发送到任意位置，其接口摘要如下：其接受的第一个参数是可调用
 * 对象f,包括函数、函数指针、函数对象和成员函数等等，最多接受9
 * 个成员函数，其返回一个被自动推导出来为f的返回值类型，在调用
 * 之前此函数对象会把之前存储的参数转发给f完成
 *
 * bind的占位符:
 * 占位符被定义为_1、_2、_3..._9位于一个匿名名字空间，占位符可以
 * 取代bind中参数的位置，在发生函数调用时才接受真正的参数。占位符
 * 的名字表示其在调用式中的顺序，而在绑定表达式没有要求，并且出现
 * 次数也没有限制。
 * 无论真实参数还是占位符均可以，绑定表达式中必须提供要求的所有参数i
 */

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <boost/bind.hpp>

using namespace boost;
using namespace std;

int f(int a,int b)
{
     return (a+b);
}
int g(int a,int b,int c)
{
     return (a+b+c);
}
typedef int (*f_type)(int,int);
typedef int (*g_type)(int,int,int);

class demo
{
public:
    int f(int a,int b)
    {
         return (a+b);
    }
};
struct func
{
    int operator()(int a,int b)
    {
         return (a*b);
    }       
};

int main( int argc,char **argv)
{
    /*绑定普通函数:
     * 变形,其他的类比：
     * 1.bind(f,_1,9)(x);   //f(x,9)
     * 2.bind(f,_1,_2)(x,y);    //f(x,y)
     * 3.bind(f,_2,_1)(x,y);    //f(y,x)
     * 4.bind(f,_1,_1)(x,y);    //f(x,x)
     * 5.bind(g,_1,_8,_2)(x,y); //g(x,8,y)
     * 6.bind(g,_3,_2,_2)(x,y,z);   //g(z,y,y)*/
    cout << bind(f,1,2)() << endl;
    cout << bind(g,2,3,4)() << endl;

    /*绑定函数指针*/
    f_type fp = f;
    g_type fg = g;
    int x = 1,y = 2,z = 3;
    cout << bind(fp,_1,18)(x) << endl;
    cout << bind(fg,_1,_3,_3)(x,y,z) << endl;

    /*绑定成员函数:
     * 绑定类的成员函数必须牺牲一个占位符的位置
     * 进而通过对象作为第一个参数来调用第一个成员函数
     * 因为成员函数指针不能直接调用operator(),必须绑定到
     * 一个对象或指针，通过this指针来调用
     * */
    demo a,&ra = a; //类的实例或引用
    demo *p = &a;   //指针
    //注意：在成员函数之前必须加上取地址操作符，以表明其是成员函数指针，否则编译无法通过
    cout << bind(&demo::f,a,_1,20)(80) << endl; 
    cout << bind(&demo::f,ra,_2,_1)(20,10) << endl;
    cout << bind(&demo::f,p,_1,_1)(30,30) << endl;

    /*绑定成员变量：
     * bind对类的另一个操作是public成员变量，其可以有选择地去操作一些成员变量*/
    typedef pair<int,string> pis_t;
    pis_t pp(12,"xiaoming");
    cout << bind(&pis_t::first,pp)();
    cout << bind(&pis_t::second,pp)() << endl;

    /*绑定函数对象：
     * 若函数有内部类型定义result_type，bind可以进行自动推导；
     * 否则需要在编写时增加typedef result_type工作
     * */
     cout << bind<int>(func(),_1,_2)(10,20) << endl;

     /*与ref的配合：
      * bind是采用拷贝的方式来存储对象和参数，开销较大，为了减少这种开销，我们可以搭配ref库
      * 一起使用，但是这可能会引起bind的调用延后。若调用时引用的变量或者函数对象被销毁，那么
      * 结果未知*/
     int m = 30;
     cout << bind(g,_1,cref(m),ref(m))(10) << endl;
     cout << bind<int>(ref(f),_1,_2)(10,20) << endl;



     return (0);
}