#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;


/*
�����㷨 ��������Ԫ��
@param beg ��ʼ������
@param end ����������
@param _callback  �����ص����ߺ�������
@return ��������
*/

//void myPrint(int v)
//{
//	cout << v << endl;
//}

struct myPrint01
{
	void operator()(int v)
	{
		cout << v << endl;
	}
};

void test01()
{
	vector<int>v;
	for (int i = 0; i < 10;i++)
	{
		v.push_back(i);
	}

	for_each(v.begin(), v.end(), myPrint01());
}


struct myPrint02
{
	void operator()(int v)
	{
		cout << v << endl;
		m_Count++;
	}
	int m_Count;
};
//2 for_each�з���ֵ
void test02()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	myPrint02 print2 = for_each(v.begin(), v.end(), myPrint02());
	cout << print2.m_Count << endl;
}

//3 for_each���԰󶨲����������
struct myPrint03 :public binary_function<int,int,void>
{
	void operator()(int v ,int start) const
	{
		cout << v  + start << endl;
	}
};

void test03()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	for_each(v.begin(), v.end(), bind2nd(myPrint03(), 10000));
}


/*
transform�㷨 ��ָ����������Ԫ�ذ��˵���һ������
ע�� : transform �����Ŀ�����������ڴ棬������Ҫ������ǰ������ڴ�
@param beg1 Դ������ʼ������
@param end1 Դ��������������
@param beg2 Ŀ��������ʼ������
@param _cakkback �ص��������ߺ�������
@return ����Ŀ������������
*/

class TransForm
{
public:
	int operator()(int val)
	{
		return val + 10;
	}
};
void test04()
{
	vector<int>v; //ԭ����
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	vector<int>vTarget; //Ŀ������
	vTarget.resize(v.size());

	transform(v.begin(), v.end(), vTarget.begin(), TransForm());

	for_each(vTarget.begin(), vTarget.end(), [](int val){ cout << val << " "; });

}

//transform �ڶ����÷� ����������������Ӱ��˵�Ŀ������
class TransForm2
{
public:
	int operator()(int val ,int val2)
	{
		return val + val2;
	}
};

void test05()
{
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 10;i++)
	{
		v1.push_back(100 + i);
		v2.push_back(200 + i);
	}
	vector<int>vTarget; //Ŀ������
	vTarget.resize(v1.size());
	transform(v1.begin(), v1.end(), v2.begin(), vTarget.begin(), TransForm2());

	// 300 302...
	for_each(vTarget.begin(), vTarget.end(), [](int val){ cout << val << " "; });

}

int main(){

	//test01();

	//test02();

	//test03();

	//test04();

	test05();
	system("pause");
	return EXIT_SUCCESS;
}