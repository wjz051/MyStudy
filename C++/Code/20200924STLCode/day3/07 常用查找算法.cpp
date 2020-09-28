#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <algorithm>
using namespace std;
#include <vector>
#include <string>
#include <functional>
/*
find�㷨 ����Ԫ��
@param beg ������ʼ������
@param end ��������������
@param value ���ҵ�Ԫ��
@return ���ز���Ԫ�ص�λ��
*/
void test01()
{
	vector<int>v;
	for (int i = 0; i < 10;i++)
	{
		v.push_back(i);
	}
	vector<int>::iterator pos = find(v.begin(), v.end(), 5);
	if (pos!=v.end())
	{
		cout << "�ҵ������ݣ�" << *pos << endl;
	}
	else
	{
		cout << "δ�ҵ�" << endl;
	}
	
}

class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	bool operator==( const Person&p)
	{
		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
		{
			return true;
		}
		return false;
	}
	
	string m_Name;
	int m_Age;
};
//����find�����Զ�����������
void test02()
{
	vector<Person>v;

	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	vector<Person>::iterator pos = find(v.begin(), v.end(), p2);
	
	if (pos != v.end())
	{
		cout << "�ҵ�������������" << (*pos).m_Name << " ���䣺" << pos->m_Age << endl;
	}
	else
	{
		cout << "δ�ҵ�" << endl;
	}
}


class MyCompare :public binary_function<Person*, Person* ,bool>
{
public:
	bool operator()( Person * p1 , Person * p2) const
	{
		if (p1->m_Name == p2->m_Name && p1->m_Age == p2->m_Age)
		{
			return true;
		}
		return false;
	}

};
void test03()
{
	vector<Person *>v;

	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);

	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);

	Person * p = new Person("bbb", 20);
	vector<Person*>::iterator pos = find_if(v.begin(), v.end(),  bind2nd( MyCompare(), p));

	if (pos != v.end())
	{
		cout << "�ҵ�������������" << (*pos)->m_Name << " ���䣺" << (*pos)->m_Age << endl;
	}
	else
	{
		cout << "δ�ҵ�" << endl;
	}
}


/*
adjacent_find�㷨 ���������ظ�Ԫ��
@param beg ������ʼ������
@param end ��������������
@param  _callback �ص���������ν��(����bool���͵ĺ�������)
@return ��������Ԫ�صĵ�һ��λ�õĵ�����
*/
void test04()
{
	vector<int>v;
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(5);
	v.push_back(6);
	v.push_back(2);

	vector<int>::iterator pos = adjacent_find(v.begin(), v.end());

	if (pos!= v.end())
	{
		cout << "�ҵ��������ظ�Ԫ��Ϊ�� " << *pos << endl;
	}
	else
	{
		cout << "δ�ҵ�" << endl;
	}
	
}

/*
binary_search�㷨 ���ֲ��ҷ�
ע��: �����������в�����
@param beg ������ʼ������
@param end ��������������
@param value ���ҵ�Ԫ��
@return bool ���ҷ���true ����false
*/
void test05()
{
	vector<int>v;
	for (int i = 0; i < 10;i++)
	{
		v.push_back(i);
	}
	
	bool ret =  binary_search(v.begin(), v.end(), 4);
	if (ret)
	{
		cout << "�ҵ���4" << endl;
	}
	else
	{
		cout << "δ�ҵ�" << endl;
	}

}

/*
/*
count�㷨 ͳ��Ԫ�س��ִ���
@param beg ������ʼ������
@param end ��������������
@param  value�ص���������ν��(����bool���͵ĺ�������)
@return int����Ԫ�ظ���
*/

/*
count_if�㷨 ͳ��Ԫ�س��ִ���
@param beg ������ʼ������
@param end ��������������
@param  callback �ص���������ν��(����bool���͵ĺ�������)
@return int����Ԫ�ظ���

*/
class GreaterThenFour
{

public:
	bool operator()(int v)
	{
		return v >= 4;
	}

};
void test06()
{
	
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	v.push_back(4);
	v.push_back(4);
	v.push_back(4);
	v.push_back(4);

	int num = count(v.begin(), v.end(), 4);
	cout << "4�ĸ���Ϊ" << num << endl;

	num = count_if(v.begin(), v.end(), GreaterThenFour());
	cout << "���ڵ��� 4�ĸ���Ϊ" << num << endl;

}


int main(){

	//test01();

	//test02();

	//test03();

	//test04();

	//test05();

	test06();

	system("pause");
	return EXIT_SUCCESS;
}