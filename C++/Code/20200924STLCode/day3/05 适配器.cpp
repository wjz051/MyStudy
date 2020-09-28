#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
using namespace std;


class MyPrint:public binary_function<int,int,void>
{
public:
	void operator()(int v ,int start) const
	{
		cout << "v = "<< v << " start = "<< start << " v+start = "<< v  + start<< endl;
	}

};

void test01()
{
	vector<int>v;
	for (int i = 0; i < 10;i++)
	{
		v.push_back(i);
	}
	cout << "��������ʼֵ" << endl;
	int num;
	cin >> num;

	//for_each(v.begin(), v.end(), bind2nd( MyPrint(),num) );
	for_each(v.begin(), v.end(), bind1st(MyPrint(), num));
}

//��һ�� �� ���� bind2nd
//�̳��� binary_function<��������1 ����������2 ������ֵ����>
//��const���� operator()

class GreaterThenFive:public unary_function<int,bool>
{
public:
	bool operator()(int v) const
	{
		return v > 5;
	}
};
//ȡ��������
void test02()
{
	//һԪȡ��
	vector<int>v;
	for (int i = 0; i < 10;i++)
	{
		v.push_back(i);
	}

	//���Ҵ���5������
	//�����Ϊ ��С��5������
	//vector<int>::iterator pos =  find_if(v.begin(), v.end(), not1( GreaterThenFive()));

	vector<int>::iterator pos = find_if(v.begin(), v.end(),  not1( bind2nd(greater<int>(),5) ));
	if (pos!= v.end())
	{
		cout << "�ҵ�С��5������Ϊ " << *pos << endl;
	}
	else
	{
		cout << "δ�ҵ�" << endl;
	}
}
//һԪȡ��������  not1
//�̳� unary_function <��������1������ֵ����>
//const����


void MyPrint03(int v ,int start) 
{
	cout << v + start << endl;
}
//����ָ��������
void test03()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	//������ָ�� ����Ϊ ��������
	// ptr_fun
	for_each(v.begin(), v.end(), bind2nd( ptr_fun( MyPrint03) ,100 ));
}

//��Ա����������
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	void showPerson()
	{
		cout << "��Ա�����У������� " << m_Name << " ���䣺" << m_Age << endl;
	}
	void plusAge()
	{
		this->m_Age = this->m_Age + 100;
	}

	string m_Name;
	int m_Age;
};

void MyPrintPerson( Person & p)
{
	cout << "������ " << p.m_Name << " ���䣺" << p.m_Age << endl;
}

void test04()
{
	vector<Person>v;

	Person p1("aaa", 10);
	Person p2("bbb", 15);
	Person p3("ccc", 18);
	Person p4("ddd", 40);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	//��Ա����������
	// mem_fun_ref
	for_each(v.begin(), v.end(),  mem_fun_ref(&Person::showPerson));
	for_each(v.begin(), v.end(), mem_fun_ref(&Person::plusAge));
	for_each(v.begin(), v.end(), mem_fun_ref(&Person::showPerson));

	
}

int main(){
	//test01();

	//test02();

	//test03();

	test04();

	system("pause");
	return EXIT_SUCCESS;
}