#ifndef __Decorator_H__
#define __Decorator_H__

#include<iostream>
using namespace std;

class Component
{
public:
	virtual void Operation(){}
};

class ConcreteComponent :public Component
{
public:
	void Operation()
	{
		std::cout << "ConcreteComponent operation..." << std::endl;
	}
};

class Decorator :public Component
{
public:
	Decorator(Component* com)
	{
		this->_com = com;
	}
	void Operation(){}
protected:
	Component* _com;
};

class ConcreteDecorator :public Decorator
{
public:
	ConcreteDecorator(Component* com) :Decorator(com) { }
	void Operation()
	{
		_com->Operation();
		this->AddedBehavior();
	}
	void AddedBehavior()
	{
		std::cout << "ConcreteDecorator::AddedBehacior...."<<std::endl;
	}
};

#endif // __Decorator_H__
