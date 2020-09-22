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
*������� Strategy ģʽ�Ĺؼ���Ҳ�� Strategyģʽ�� Template ģʽ�ĸ����������ڡ�
*Strategy ͨ������ϡ���ί�У� ��ʽʵ���㷨��ʵ�֣����칹���� Template ģʽ���ȡ���Ǽ̳еķ�ʽ
*������ģʽ������Ҳ�Ǽ̳к��������ʵ�ֽӿ����õķ�ʽ������
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
