#ifndef __Responsibility_H__
#define __Responsibility_H__

#include<iostream>
using namespace std;

class Handle
{
public:
	virtual void HandleRequest() = 0;
	void SetSuccessor(Handle* succ)
	{
		_succ = succ;
	}
	Handle* GetSuccessor()
	{
		return _succ;
	}
private:
	Handle* _succ;
};

class ConcreteHandleA :public Handle
{
public:
	void HandleRequest()
	{
		if (this->GetSuccessor() != 0)
		{
			cout << "ConcreteHandleA 我把处理权给后继节点....."<<endl;
			this->GetSuccessor()->HandleRequest();
		}
		else
		{
			cout << "ConcreteHandleA 没有后继了，我必须自己处理...."<<endl;
		}
	}
};

class ConcreteHandleB :public Handle
{
public:
	void HandleRequest()
	{
		if (this->GetSuccessor() != 0)
		{
			cout << "ConcreteHandleB 我把处理权给后继节点....."<<endl;
			this->GetSuccessor()->HandleRequest();
		}
		else
		{
			cout << "ConcreteHandleB 没有后继了，我必须自己处理...."<<endl;
		}
	}
};




#endif // __Responsibility_H__
