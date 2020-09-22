#ifndef __Iterator_H__
#define __Iterator_H__

#include<iostream>
using namespace std;

/*
通过将 Iterator 对象声明位 Aggregate 的友元来给予 Iterator一些特权，获得访问 Aggregate 私有数据和方法的机会
*/

class Iterator
{
public:
	virtual void First() = 0;
	virtual void Next() = 0;
	virtual bool IsDone() = 0;
	virtual int CurrentItem() = 0;
};

class Aggregate
{
public:
	virtual Iterator* CreateIterator() = 0;
	virtual int GetItem(int idx) = 0;
	virtual int GetSize() = 0;
};

class ConcreteIterator :public Iterator
{
public:
	ConcreteIterator(Aggregate* ag, int idx = 0)
	{
		this->_ag = ag;
		this->_idx = idx;
	}
	void First()
	{
		_idx = 0;
	}
	void Next()
	{
		if (_idx < _ag->GetSize())
			_idx++;
	}
	bool IsDone()
	{
		return (_idx == _ag->GetSize());
	}
	int CurrentItem()
	{
		return _ag->GetItem(_idx);
	}
private:
	Aggregate* _ag;
	int _idx;
};

class ConcreteAggregate :public Aggregate
{
public:
	enum { SIZE = 3 };
	ConcreteAggregate()
	{
		for (int i = 0; i < SIZE; i++)
			_objs[i] = i;
	}
	Iterator* CreateIterator()
	{
		return new ConcreteIterator(this);
	}
	int GetItem(int idx)
	{
		if (idx < this->GetSize())
			return _objs[idx];
		else
			return -1;
	}
	int GetSize()
	{
		return SIZE;
	}
private:
	int _objs[SIZE];
};


#endif // __Iterator_H__
