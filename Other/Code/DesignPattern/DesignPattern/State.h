#ifndef __State_H__
#define __State_H__

#include<iostream>
using namespace std;

class State;

class Context
{
public:
	Context(State* state)
	{
		this->_state = state;
	}
	void OprationInterface()
	{
		_state->OperationInterface(this);
	}
	void OperationChangState()
	{
		_state->OperationChangeState(this);
	}
private:
	friend class State; //表明在 State 类中可以访问 Context 类的 private 字段
	bool ChangeState(State* state)
	{
		this->_state = state;
		return true;
	}
private:
	State* _state;
};

class State
{
public:
	virtual void OperationInterface(Context* con)
	{
		cout << "State::.." << endl;
	}
	virtual void	OperationChangeState(Context* con) {}
protected:
	bool ChangeState(Context* con, State* st)
	{
		con->ChangeState(st);
		return true;
	}
};
class ConcreteStateA :public State
{
public:
	virtual void	OperationInterface(Context* con)
	{
		cout << "ConcreteStateA::OperationInterface......"<<endl;
	}
	virtual void	OperationChangeState(Context* con)
	{
		OperationInterface(con);
		this->ChangeState(con, new ConcreteStateB());
	}

};
class ConcreteStateB :public State
{
public:
	virtual void	OperationInterface(Context* con)
	{
		cout << "ConcreteStateB::OperationInterface......"<<endl;
	}
	virtual void	OperationChangeState(Context* con)
	{
		OperationInterface(con);
		this->ChangeState(con, new ConcreteStateA());
	}
};


#endif // __State_H__
