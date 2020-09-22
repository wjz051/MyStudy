#ifndef __Visitor_H__
#define __Visitor_H__

#include<iostream>
using namespace std;

class Visitor;

class Element
{
public:
	virtual void Accept(Visitor* vis) = 0;
};

class Visitor
{
public:
	virtual void VisitConcreteElementA(Element* elm) = 0;
	virtual void VisitConcreteElementB(Element* elm) = 0;
};

class ConcreteElementA :public Element
{
public:
	void Accept(Visitor* vis)
	{
		vis->VisitConcreteElementA(this);
		cout << "visiting ConcreteElementA..." << endl;
	}
};
class ConcreteElementB :public Element
{
public:
	void Accept(Visitor* vis)
	{
		cout << "visiting ConcreteElementB..." << endl;
		vis->VisitConcreteElementB(this);
	}
};

class ConcreteVisitorA :public Visitor
{
public:
	virtual void VisitConcreteElementA(Element* elm)
	{
		cout << "i will visit ConcreteElementA..."<<endl;
	}
	virtual void VisitConcreteElementB(Element* elm)
	{
		cout << "i will visit ConcreteElementB..."<<endl;
	}
};
class ConcreteVisitorB :public Visitor
{
public:
	virtual void	VisitConcreteElementA(Element* elm)
	{
		cout << "i will visit ConcreteElementA..."<<endl;
	}
	virtual void VisitConcreteElementB(Element* elm)
	{
		cout << "i will visit ConcreteElementB..."<<endl;
	}
};

#endif // __Visitor_H__
