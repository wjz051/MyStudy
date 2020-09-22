#ifndef __Adapter_H__
#define __Adapter_H__

#include<iostream>
using namespace std;

/*
在 C++中的 public 继承既是接口继承又是实现继承，因为子类在继承了父类后既可以对外提供父类中的接口操作， 又可以获得父类的接口实现。

*/

class Target
{
public:
	virtual void Request()
	{
		std::cout << "Target::Request" << std::endl;
	}
};

class Adaptee
{
public:
	void SpecificRequest()
	{
		std::cout << "Adaptee::SpecificRequest" <<std::endl;
	}
};

/*接口继承*/
class Adapter :public Target, private Adaptee
{
public:
	void Request()
	{
		this->SpecificRequest();
	}
};
/*实现继承*/
class Adapter2 :public Target
{
public:
	Adapter2(Adaptee* ade)
	{
		this->_ade = ade;
	}
	void Request()
	{
		_ade->SpecificRequest();
	}
private:
	Adaptee* _ade;
};

#endif // __Adapter_H__
