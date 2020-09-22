#ifndef __Interpreter_H__
#define __Interpreter_H__

#include<iostream>
#include<string>
using namespace std;

class Context
{
};

class AbstractExpression
{
public:
	virtual void Interpret(const Context& c){}
};
class TerminalExpression :public	AbstractExpression
{
public:
	TerminalExpression(const string& statement)
	{
		this->_statement = statement;
	}
	void Interpret(const Context& c)
	{
		cout << this->_statement << "TerminalExpression"<<endl;
	}
private:
	string _statement;
};

class NonterminalExpression :public	AbstractExpression
{
public:
	NonterminalExpression(AbstractExpression* expression, int times)
	{
		this->_expression = expression;
		this->_times = times;
	}
	void Interpret(const Context& c)
	{
		for (int i = 0; i < _times; i++)
		{
			this->_expression->Interpret(c);
		}
	}
private:
	AbstractExpression* _expression;
	int _times;
};


#endif // __Interpreter_H__
