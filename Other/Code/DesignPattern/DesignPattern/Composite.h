#ifndef __Composite_H__
#define __Composite_H__

#include<iostream>
#include <vector>
using namespace std;

class Component
{
public:
	virtual void Operation() = 0;
	virtual void Add(const Component&){}
	virtual void Remove(const Component&){}
	virtual Component* GetChild(int)
	{ 
		return 0; 
	}
};

class Composite :public Component
{
public:
	void Operation()
	{
		vector<Component*>::iterator comIter = comVec.begin();
		for (; comIter != comVec.end(); comIter++)
		{
			(*comIter)->Operation();
		}
	}
	void Add(Component* com)
	{
		comVec.push_back(com);
	}
	void Remove(Component* com)
	{
		//comVec.erase(&com);
	}
	Component* GetChild(int index)
	{
		return comVec[index];
	}

private:
	vector<Component*> comVec;
};

class Leaf :public Component
{
public:
	void Operation()
	{
		cout << "Leaf operation....." << endl;
	}
};


#endif // __Composite_H__
