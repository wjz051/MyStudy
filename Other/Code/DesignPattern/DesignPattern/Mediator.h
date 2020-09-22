#ifndef __Mediator_H__
#define __Mediator_H__

#include<iostream>
#include <string>
using namespace std;

class Colleage;

class Mediator
{
public:
	virtual void DoActionFromAtoB() = 0;
	virtual void DoActionFromBtoA() = 0;
};

class ConcreteMediator :public Mediator
{
public:
	ConcreteMediator(){}
	ConcreteMediator(Colleage* clgA, Colleage* clgB)
	{
		this->_clgA = clgA;
		this->_clgB = clgB;
	}
	void SetConcreteColleageA(Colleage*	clgA)
	{
		this->_clgA = clgA;
	}
	void SetConcreteColleageB(Colleage*	clgB)
	{
		this->_clgB = clgB;
	}
	Colleage* GetConcreteColleageA()
	{
		return _clgA;
	}
	Colleage* GetConcreteColleageB()
	{
		return _clgB;
	}
	void IntroColleage(Colleage*	clgA, Colleage* clgB)
	{
		this->_clgA = clgA;
		this->_clgB = clgB;
	}
	void DoActionFromAtoB()
	{
		_clgB->SetState(_clgA->GetState());
	}
	void DoActionFromBtoA()
	{
		_clgA->SetState(_clgB->GetState());
	}

private:
	Colleage* _clgA;
	Colleage* _clgB;
};

class Colleage
{
public:
	virtual void Aciton() = 0;
	virtual void SetState(const string& sdt) = 0;
	virtual string GetState() = 0;
protected:
	Colleage(Mediator* mdt)
	{
		this->_mdt = mdt;
	}
	Mediator* _mdt;
};
class ConcreteColleageA :public Colleage
{
public:
	ConcreteColleageA(Mediator* mdt) :Colleage(mdt) { }
	void Aciton()
	{
		_mdt->DoActionFromAtoB();
		cout << "State of ConcreteColleageB:" << " "<<this->GetState()<<endl;
	}
	void SetState(const string& sdt)
	{
		_sdt = sdt;
	}
	string GetState()
	{
		return _sdt;
	}
private:
	string _sdt;
};
class ConcreteColleageB :public Colleage
{
public:
	ConcreteColleageB(Mediator* mdt) :Colleage(mdt) { }
	void Aciton()
	{
		_mdt->DoActionFromBtoA();
		cout << "State of ConcreteColleageB:" << " "<<this->GetState()<<endl;
	}
	void SetState(const string& sdt)
	{
		_sdt = sdt;
	}
	string GetState()
	{
		return _sdt;
	}
private:
	string _sdt;
};

#endif // __Mediator_H__
