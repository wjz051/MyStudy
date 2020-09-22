#ifndef __Memento_H__
#define __Memento_H__

#include<iostream>
#include <string>
using namespace std;

class Memento
{
private:
	//这是最关键的地方，将 Originator 为friend 类， 可以访问内部信息， 但是其他类不能访问
	friend class Originator;
	Memento(const string& sdt)
	{
		_sdt = sdt;
	}
	void SetState(const string& sdt)
	{
		_sdt = sdt;
	}
	string GetState()
	{
		return _sdt;
	}
private:
	string _sdt;
};

class Originator
{
public:
	Originator(const string& sdt)
	{
		_sdt = sdt;
		_mt = 0;
	}
	Memento* CreateMemento()
	{
		return new Memento(_sdt);
	}
	void SetMemento(Memento* men){}
	void RestoreToMemento(Memento* mt)
	{
		this->_sdt = mt->GetState();
	}
	string GetState()
	{
		return _sdt;
	}
	void SetState(const string& sdt)
	{
		_sdt = sdt;
	}
	void PrintState()
	{
		cout << this->_sdt << "....." << endl;
	}

private:
	string _sdt;
	Memento* _mt;
};


#endif // __Memento_H__
