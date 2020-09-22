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
			cout << "ConcreteHandleA �ҰѴ���Ȩ����̽ڵ�....."<<endl;
			this->GetSuccessor()->HandleRequest();
		}
		else
		{
			cout << "ConcreteHandleA û�к���ˣ��ұ����Լ�����...."<<endl;
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
			cout << "ConcreteHandleB �ҰѴ���Ȩ����̽ڵ�....."<<endl;
			this->GetSuccessor()->HandleRequest();
		}
		else
		{
			cout << "ConcreteHandleB û�к���ˣ��ұ����Լ�����...."<<endl;
		}
	}
};




#endif // __Responsibility_H__
