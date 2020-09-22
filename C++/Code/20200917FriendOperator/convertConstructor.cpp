/*
Convert Constructor
目标 实现其它类型到本类类型的转化。
原理 转换构造函数， 本质是一个构造函数。 是只有一个参数的构造函数。 如有多
个参数， 只能称为构造函数， 而不是转换函数。 转换构造， 强调的是一转一。
应用 用于传参或是作返回
*/

/*
Complex c (1,2);
Complex c2 = c + 2;//Complex(double real) 类型转化构造函数 在目标类中
---实现double默认转换成complex
Complex(const double &real)
{
    return Complex(real,0);
}
Complex c (1,2);
double a = 2 + c; //operator double() 类型转化操作符函数 在源类中
---实现complex默认转换成double
operator double()
{
    return _real;
}
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

class Point2D;

class Point3D
{ 
    friend Point3D operator+(const Point3D &a,const Point3D &b);
public:
    Point3D(int x=0, int y=0 ,int z=0)
        :_x(x),_y(y),_z(z){}

    //转化构造函数的本质， 也是构造函数
    explicit Point3D(const Point2D & d2); 

    void dumpFormat()
    {
        cout<<"("<<_x<<","<<_y<<","<<_z<<")"<<endl;
    }
private:
    int _x;
    int _y;
    int _z;
};

Point3D operator+(const Point3D &a,const Point3D &b)
{
    cout<<"Point3D operator+(const Point3D &a,const Point3D &b)"<<endl;
    return Point3D(a._x+b._x,a._y+b._y,a._z+b._z);
}

class Point2D
{
    friend class Point3D;
public:
    Point2D(int x=0, int y=0 )
        :_x(x),_y(y){}

    //类型转化操作符函数 在源类中
    operator Point3D()
    {
        cout<<"operator Point3D()"<<endl;
        return Point3D(_x,_y,rand()%100);
    }
private:
    int _x;
    int _y;
};

Point3D::Point3D(const Point2D & d2)
{
    cout<<"Point3D(const Point2D & d2)"<<endl;
    this->_x = d2._x;
    this->_y = d2._y;
    this->_z = rand()%100;
} 

void foo(Point3D d3)
{
    d3.dumpFormat();
}

int main()
{
    srand(time(NULL));
    Point2D d2(10,100);
    // Point3D d3 = d2; 加 explicit 后 编不过
    // Point3D d3(d2); 显示调用 编过
    // Point3D d3 = (Point3D)d2; 强转 编过
    Point3D d3 = static_cast<Point3D>(d2);
    d3.dumpFormat();

    Point3D d4=d3+d2;
    d4.dumpFormat();
    // foo(d2); 加 explicit 后 编不过
    foo((Point3D)d2);
    return 0;
}

