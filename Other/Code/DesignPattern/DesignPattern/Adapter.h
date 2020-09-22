#ifndef __Adapter_H__
#define __Adapter_H__

#include<iostream>
using namespace std;

/*
�� C++�е� public �̳м��ǽӿڼ̳�����ʵ�ּ̳У���Ϊ�����ڼ̳��˸����ȿ��Զ����ṩ�����еĽӿڲ����� �ֿ��Ի�ø���Ľӿ�ʵ�֡�

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

/*�ӿڼ̳�*/
class Adapter :public Target, private Adaptee
{
public:
	void Request()
	{
		this->SpecificRequest();
	}
};
/*ʵ�ּ̳�*/
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
