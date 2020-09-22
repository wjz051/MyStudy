#include<iostream>
using namespace std;

/*
一元运算符
~ ! - ++ --                          建议成员重载

二元运算符
+= -= /= *= ^= &= != %= >>= <<=  =  建议成员重载

其他建议非成员函数，友元全局重载


*/

class Complex
{
    //重载流运算符--只能是友元重载，全局函数
    friend ostream& operator<<(ostream &os,const Complex &c);
    friend istream& operator>>(istream &os,Complex &c);

    //二元运算符友元重载
    friend const Complex operator+(const Complex &a,const Complex &b);
    friend const Complex operator-(const Complex &a,const Complex &b);
public:
    Complex(int real=0,int image=0)
        :_real(real),_image(image)
    {
        cout<<"Complex "<<_real<<","<<_image<<endl;
    }

    Complex(const Complex &a)
    {
        cout<<"Complex(const Complex &a) "<<a._real<<","<<a._image<<endl;
        _real=a._real;
        _image=a._image;
    }

/*
Convert Constructor
目标 实现其它类型到本类类型的转化。
原理 转换构造函数， 本质是一个构造函数。 是只有一个参数的构造函数。 如有多
个参数， 只能称为构造函数， 而不是转换函数。 转换构造， 强调的是一转一。
应用 用于传参或是作返回
*/
    Complex(const double &i)
    {
        cout<<"Convert Constructor Complex(const double &i)"<<endl;
        _real=i;
        _image=0;
    }

    //重载一元运算符- -a
    const Complex operator-(void) const
    {
        cout<<"const Complex operator-(void) const "<<endl;
        return Complex(-_real,-_image);
    }

    //重载一元运算符++  ++a
    Complex& operator++()
    {
        cout<<"Complex& operator++()"<<endl;
        ++_real;
        ++_image;
        return *this;
    }

    //重载一元运算符++  a++  哑元
    const Complex operator++(int)
    {
        cout<<"const Complex operator++(int)"<<endl;
        Complex a=*this;
        _real++;
        _image++;
        return a;
    }

    //重载二元运算符=  a=b=c
    Complex& operator=(const Complex &a)
    {
        cout<<"Complex operator=(const Complex &a) "<<a._real<<","<<a._image<<endl;
        _real=a._real;
        _image=a._image;
        return *this;
    }

    //重载二元运算符+=  a+=b+=c (a+=b)+=c
    Complex& operator+=(const Complex &a)
    {
        cout<<"Complex operator+=(const Complex &a) "<<a._real<<","<<a._image<<endl;
        _real+=a._real;
        _image+=a._image;
        return *this;
    }

    // //成员重载+  a+b+c
    // Complex operator+(const Complex &a)
    // {
    //     Complex c;
    //     c._real=_real+a._real;
    //     c._image=_image+a._image;
    //     return c;
    // }


private:
    int _real;
    int _image;
};

ostream& operator<<(ostream &os,const Complex &c)
{
    os<<"<"<<c._real<<","<<c._image<<">";
    return os;
}

istream& operator>>(istream &is,Complex &c)
{
    is>>c._real>>c._image;
    return is;
}

const Complex operator+(const Complex &a,const Complex &b)
{
    Complex c;
    c._real=b._real+a._real;
    c._image=b._image+a._image;
    return c;
}

const Complex operator-(const Complex &a,const Complex &b)
{
    Complex c;
    c._real=a._real-b._real;
    c._image=a._image-b._image;
    return c;
}

int main()
{
    Complex a(1,2),b(3,4);
    Complex c=a+b;
    cout<<c<<endl;

    c=c+2.0;
    cout<<c<<endl;


    cout<<++c<<endl;

    c+=b;
    cout<<c++<<endl;

    cout<<-c<<endl;
    cout<<"Hello Operator"<<endl;
    return 0;
}