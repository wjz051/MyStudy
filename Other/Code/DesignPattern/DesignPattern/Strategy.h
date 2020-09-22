#ifndef __Strategy_H__
#define __Strategy_H__

#include<iostream>

using namespace std;

class Strategy
{
public:
	virtual ~Strategy()
	{
		cout << "~Strategy....." << endl;
	}

	virtual void AlgrithmInterface() = 0;
};

class ConcreteStrategyA :public Strategy
{
public:
	~ConcreteStrategyA()
	{
		cout << "~ConcreteStrategyA....." << endl;
	}

	void AlgrithmInterface()
	{
		cout << "testConcreteStrategyA....."<<endl;
	}
};
class ConcreteStrategyB :public Strategy
{
public:
	~ConcreteStrategyB()
	{
		cout << "~ConcreteStrategyB....." << endl;
	}

	void AlgrithmInterface()
	{
		cout << "testConcreteStrategyB....."<<endl;
	}
};

/**
*这个类是 Strategy 模式的关键，也是 Strategy模式和 Template 模式的根本区别所在。
*Strategy 通过“组合”（委托） 方式实现算法（实现）的异构，而 Template 模式则采取的是继承的方式
*这两个模式的区别也是继承和组合两种实现接口重用的方式的区别
*/
class Context
{
public:
	Context(Strategy* stg)
	{
		_stg = stg;
	}
	~Context()
	{
		if (_stg)
			delete _stg;
	}

	void DoAction()
	{
		_stg->AlgrithmInterface();
	}
private:
	Strategy* _stg;
};

#endif // __Strategy_H__
