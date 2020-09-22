#ifndef __Proxy_H__
#define __Proxy_H__

#include<iostream>

using namespace std;

class Subject
{
public:
	virtual void Request() = 0;
};

class ConcreteSubject :public Subject
{
public:
	void Request()
	{
		cout << "ConcreteSubject......request...." <<endl;
	}
};

class Proxy
{
public:
	Proxy(Subject* sub)
	{
		_sub = sub;
	}
	void Request()
	{
		cout << "Proxy request...." << endl;
		_sub->Request();
	}
private:
	Subject* _sub;
};


#endif // __Proxy_H__
