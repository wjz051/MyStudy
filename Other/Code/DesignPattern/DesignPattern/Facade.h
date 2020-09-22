#ifndef __Facade_H__
#define __Facade_H__

#include<iostream>
using namespace std;

class Subsystem1
{
public:
	void Operation()
	{
		cout << "Subsystem1 operation.." << endl;
	}
};
class Subsystem2
{
public:
	void Operation()
	{
		cout << "Subsystem2 operation.." << endl;
	}
};
class Facade
{
public:
	Facade()
	{
		this->_subs1 = new Subsystem1();
		this->_subs2 = new Subsystem2();
	}
	void OperationWrapper()
	{
		this->_subs1->Operation();
		this->_subs2->Operation();
	}
private:
	Subsystem1* _subs1;
	Subsystem2* _subs2;
};



#endif // __Facade_H__
