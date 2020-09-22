#ifndef __Observer_H__
#define __Observer_H__

/*
Observer ģʽҲ��Ϊ���������ģ� publish-subscribe����Ŀ�����֪ͨ�ķ����ߣ��۲�������֪ͨ�Ķ����ߣ�����֪ͨ����
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
		{ //����ģ��� iterator ���÷�
			(*it)->Update(this);
		}
	}

	virtual void SetState(const string& st) = 0;
	virtual string GetState() = 0;

protected:
	Subject()
	{ //��ģ���ʹ��֮ǰһ��Ҫ new������
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
	//���� Subject ��Ϊ����������������һ��View ���ڶ���� Subject��
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
	//���� Subject ��Ϊ����������������һ��View ���ڶ���� Subject��
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
