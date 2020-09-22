#ifndef __Flyweight_H__
#define __Flyweight_H__

#include<iostream>
#include <string>
#include <vector>

using namespace std;


class Flyweight
{
public:
	virtual void Operation(const string& extrinsicState){}
	string GetIntrinsicState()
	{
		return this->_intrinsicState;
	}
protected:
	Flyweight(string intrinsicState)
	{
		this->_intrinsicState = intrinsicState;
	}
private:
	string _intrinsicState;
};

class ConcreteFlyweight :public Flyweight
{
public:
	ConcreteFlyweight(string intrinsicState) :Flyweight(intrinsicState)
	{
		cout << "ConcreteFlyweight Build....."<<intrinsicState<<endl;
	}
	void Operation(const string& extrinsicState)
	{
		cout << "ConcreteFlyweight: �� ��["<<this->GetIntrinsicState()<<"] �� ��["<<extrinsicState<<"]"<<endl;
	}
};


class FlyweightFactory
{
public:
	Flyweight* GetFlyweight(const string& key)
	{
		vector<Flyweight*>::iterator it = _fly.begin();
		for (; it != _fly.end(); it++)
		{
			//�ҵ��ˣ���һ���ã� ^_^
			if ((*it)->GetIntrinsicState() == key)
			{
				cout << "already created by users...."<<endl;
				return *it;
			}
		}
		Flyweight* fn = new ConcreteFlyweight(key);
		_fly.push_back(fn);
		return fn;
	}
private:
	vector<Flyweight*> _fly;
};


#endif // __Flyweight_H__
