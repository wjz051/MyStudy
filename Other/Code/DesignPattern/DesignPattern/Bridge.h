#ifndef __Bridge_H__
#define __Bridge_H__

#include<iostream>
using namespace std;

class AbstractionImp
{
public:
	virtual void Operation() 
	{
		cout << "AbstractionImp....imp..." << endl;
	}
};
class ConcreteAbstractionImpA :public AbstractionImp
{
public:
	virtual void Operation()
	{
		cout << "ConcreteAbstractionImpA...." << endl;
	}
};
class ConcreteAbstractionImpB :public	AbstractionImp
{
public:
	virtual void Operation()
	{
		cout << "ConcreteAbstractionImpB...." << endl;
	}
};

class Abstraction
{
public:
	virtual void Operation() = 0;
};

class RefinedAbstraction :public Abstraction
{
public:
	RefinedAbstraction(AbstractionImp*imp)
	{
		_imp = imp;
	}

	void Operation()
	{
		_imp->Operation();
	}
private:
	AbstractionImp* _imp;
};

#endif // __Bridge_H__
