#ifndef __Template_H__
#define __Template_H__

class AbstractClass
{
public:
	void TemplateMethod()
	{
		this->PrimitiveOperation1();
		this->PrimitiveOperation2();
	}
protected:
	virtual void PrimitiveOperation1() = 0;
	virtual void PrimitiveOperation2() = 0;
};

class ConcreteClass1 :public AbstractClass
{
protected:
	void PrimitiveOperation1()
	{
		cout << "ConcreteClass1...PrimitiveOperation1"<<endl;
	}
	void PrimitiveOperation2()
	{
		cout << "ConcreteClass1...PrimitiveOperation2"<<endl;
	}
};

class ConcreteClass2 :public AbstractClass
{
protected:
	void PrimitiveOperation1()
	{
		cout << "ConcreteClass2...PrimitiveOperation1" << endl;
	}
	void PrimitiveOperation2()
	{
		cout << "ConcreteClass2...PrimitiveOperation2" << endl;
	}
};


#endif // __Template_H__
