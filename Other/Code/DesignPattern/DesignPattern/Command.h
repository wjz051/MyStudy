#ifndef __Command_H__
#define __Command_H__

#include<iostream>
using namespace std;

class Reciever
{
public:
	void Action()
	{
		std::cout << "Reciever action......."<<std::endl;
	}
};


class Command
{
public:
	virtual void Excute() = 0;
};

class ConcreteCommand :public Command
{
public:
	ConcreteCommand(Reciever* rev)
	{
		_rev = rev;
	}
	void Excute()
	{
		_rev->Action();
	}
private:
	Reciever* _rev;
};

class Invoker
{
public:
	Invoker(Command* cmd)
	{
		_cmd = cmd;
	}
	void Invoke()
	{
		_cmd->Excute();
	}
private:
	Command* _cmd;
};

#endif // __Command_H__
