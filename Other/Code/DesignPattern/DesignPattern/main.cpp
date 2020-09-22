#include<iostream>
using namespace std;

#include "Bridge.h"
#include "Adapter.h"
//#include "Decorator.h"
#include "Composite.h"
#include "Flyweight.h"
#include "Facade.h"
#include "Proxy.h"

#include "Template.h"
#include "Strategy.h"
//#include "State.h"
//#include "Observer.h"
#include "Memento.h"
//#include "Mediator.h"
#include "Command.h"
#include "Visitor.h"
#include "Responsibility.h"
#include "Iterator.h"
//#include "Interpreter.h"

void StructurePattern()
{
	/*Bridge*/
	AbstractionImp* imp = new ConcreteAbstractionImpA();
	Abstraction* abs = new RefinedAbstraction(imp);
	abs->Operation();

	/*Adapter*/
	Adaptee* ade = new Adaptee;
	Target* adt = new Adapter2(ade);
	adt->Request();

	/*Decorator
	Component* com = new ConcreteComponent();
	Decorator* dec = new ConcreteDecorator(com);
	dec->Operation();*/

	/*Composite*/
	Leaf* l = new Leaf();
	l->Operation();
	Composite* com = new Composite();
	com->Add(l);
	com->Operation();
	Component* ll = com->GetChild(0);
	ll->Operation();

	/*Flyweight*/
	FlyweightFactory* fc = new FlyweightFactory();
	Flyweight* fw1 =	fc->GetFlyweight("hello");
	Flyweight* fw2 =	fc->GetFlyweight("world!");
	Flyweight* fw3 =	fc->GetFlyweight("hello");

	/*Facade*/
	Facade* f = new Facade();
	f->OperationWrapper();

	/*Proxy*/
	Subject* sub = new ConcreteSubject();
	Proxy* p = new Proxy(sub);
	p->Request();


}

void BehaviorPattern()
{
	/*Template*/
	AbstractClass* p1 = new ConcreteClass1();
	AbstractClass* p2 = new ConcreteClass2();
	p1->TemplateMethod();
	p2->TemplateMethod();

	/*Strategy*/
	Strategy* ps = new ConcreteStrategyA();
	Context* pc = new Context(ps);
	pc->DoAction();
	if (NULL != pc)
		delete pc;

	/*State
	State* st = new ConcreteStateA();
	Context* con = new Context(st);
	con->OprationInterface();
	con->OprationInterface();
	con->OprationInterface();
	if (con != NULL)
		delete con;
	if (st != NULL)
		st = NULL;*/

	/*Observer
	ConcreteSubject* sub = new	ConcreteSubject();
	Observer* o1 = new	ConcreteObserverA(sub);
	Observer* o2 = new	ConcreteObserverB(sub);
	sub->SetState("old");
	sub->Notify();
	sub->SetState("new"); // 也可以由Observer调用
	sub->Notify();*/

	/*Memento*/
	Originator* o = new Originator("");
	o->SetState("old"); //备忘前状态
	o->PrintState();
	Memento* m = o->CreateMemento(); //将状态备忘
	o->SetState("new"); //修改状态
	o->PrintState();
	o->RestoreToMemento(m); //恢复修改前状态
	o->PrintState();

	/*Mediator
	ConcreteMediator* Mediator = new	ConcreteMediator();
	ConcreteColleageA* c1 = new	ConcreteColleageA(Mediator);
	ConcreteColleageB* c2 = new	ConcreteColleageB(Mediator);
	Mediator->IntroColleage(c1, c2);
	c1->SetState("old");
	c2->SetState("old");
	c1->Aciton();
	c2->Aciton();
	cout << endl;
	c1->SetState("new");
	c1->Aciton();
	c2->Aciton();
	cout << endl;
	c2->SetState("old");
	c2->Aciton();
	c1->Aciton();*/

	/*Command*/
	Reciever* rev = new Reciever();
	Command* cmd = new ConcreteCommand(rev);
	Invoker* inv = new Invoker(cmd);
	inv->Invoke();

	/*Visitor*/
	Visitor* vis = new ConcreteVisitorA();
	Element* elm = new ConcreteElementA();
	elm->Accept(vis);

	/*Responsibility*/
	Handle* h1 = new ConcreteHandleA();
	Handle* h2 = new ConcreteHandleB();
	h1->SetSuccessor(h2);
	h1->HandleRequest();

	/*Iterator*/
	Aggregate* ag = new ConcreteAggregate();
	Iterator* it = new ConcreteIterator(ag);
	for (; !(it->IsDone()); it->Next())
	{
		cout << it->CurrentItem() << endl;
	}

	/*Interpreter
	Context* ct = new Context();
	AbstractExpression* te = new TerminalExpression("hello");
	AbstractExpression* nte = new NonterminalExpression(te, 2);
	nte->Interpret(*ct);*/
	
}

int main()
{ 
	StructurePattern();
	BehaviorPattern();

	cout << "Hello World !" << endl;
	system("pause");
	return 0;
}
