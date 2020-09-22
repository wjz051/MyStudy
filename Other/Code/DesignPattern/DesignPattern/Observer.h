#ifndef __Observer_H__
#define __Observer_H__

/*
Observer 模式也称为发布－订阅（ publish-subscribe），目标就是通知的发布者，观察者则是通知的订阅者（接受通知）。
*/

#include<iostream>
#include <list>
#include <string>

using namespace std;

class Subject
{
public:
	virtual ~Subject();
	virtual void Attach(Observer* obv)
	{
		_obvs->push_front(obv);
	}

	virtual void Detach(Observer* obv)
	{
		if (obv != NULL)
			_obvs->remove(obv);
	}

	virtual void Notify()
	{
		list<Observer*>::iterator it;
		it = _obvs->begin();
		for (; it != _obvs->end(); it++)
		{ //关于模板和 iterator 的用法
			(*it)->Update(this);
		}
	}

	virtual void SetState(const string& st) = 0;
	virtual string GetState() = 0;

protected:
	Subject()
	{ //在模板的使用之前一定要 new，创建
		_obvs = new list<Observer*>;
	}

private:
	list<Observer* >* _obvs;
};

class ConcreteSubject :public Subject
{
public:
	string GetState()
	{
		return _st;
	}
	void SetState(const string& st)
	{
		_st = st;
	}

private:
	string _st;
};

class Observer
{
public:
	virtual ~Observer();
	virtual void Update(Subject* sub) = 0;
	virtual void PrintInfo() = 0;
protected:
	string _st;
};
class ConcreteObserverA :public Observer
{
public:
	ConcreteObserverA(Subject* sub)
	{
		_sub = sub;
		_sub->Attach(this);
	}
	virtual ~ConcreteObserverA()
	{
		_sub->Detach(this);
		if (_sub != 0)
			delete _sub;
	}
	virtual Subject* GetSubject()
	{
		return _sub;
	}
	//传入 Subject 作为参数，这样可以让一个View 属于多个的 Subject。
	void Update(Subject* sub)
	{
		_st = sub->GetState();
		PrintInfo();
	}
	void PrintInfo()
	{
		cout << "ConcreteObserverA observer...."<<_sub->GetState()<<endl;
	}

private:
	Subject* _sub;
};

class ConcreteObserverB :public Observer
{
public:
	virtual Subject* GetSubject()
	{
		return _sub;
	}
	ConcreteObserverB(Subject* sub)
	{
		_sub = sub;
		_sub->Attach(this);
	}
	virtual ~ConcreteObserverB()
	{
		_sub->Detach(this);
		if (_sub != 0)
		{
			delete _sub;
		}
	}
	//传入 Subject 作为参数，这样可以让一个View 属于多个的 Subject。
	void Update(Subject* sub)
	{
		_st = sub->GetState();
		PrintInfo();
	}

	void PrintInfo()
	{
		cout << "ConcreteObserverB observer...."<<_sub->GetState()<<endl;
	}

private:
	Subject* _sub;
};

#endif // __Observer_H__
