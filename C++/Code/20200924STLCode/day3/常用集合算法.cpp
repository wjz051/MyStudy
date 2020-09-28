#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
/*
set_intersection�㷨 ������set���ϵĽ���
ע��:�������ϱ�������������
@param beg1 ����1��ʼ������
@param end1 ����1����������
@param beg2 ����2��ʼ������
@param end2 ����2����������
@param dest  Ŀ��������ʼ������
@return Ŀ�����������һ��Ԫ�صĵ�������ַ
*/

void test()
{
	vector<int>v1;
	for (int i = 0; i < 10; ++i)
	{
		v1.push_back(i);
	}

	vector<int>v2;
	for (int i = 0; i < 10; ++i)
	{
		v2.push_back(i+1);
	}
	vector<int>v3;
	v3.resize(v1.size()>v2.size() ? v2.size() : v1.size());


	vector<int>::iterator pos = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	for_each(v3.begin(), pos, [](int a){cout << a << ' '; });

}

/*
set_union�㷨 ������set���ϵĲ���
ע��:�������ϱ�������������
@param beg1 ����1��ʼ������
@param end1 ����1����������
@param beg2 ����2��ʼ������
@param end2 ����2����������
@param dest  Ŀ��������ʼ������
@return Ŀ�����������һ��Ԫ�صĵ�������ַ
*/

void test01()
{
	vector<int>v1;
	for (int i = 0; i < 10; ++i)
	{
		v1.push_back(i);
	}

	vector<int>v2;
	for (int i = 0; i < 10; ++i)
	{
		v2.push_back(i + 1);
	}
	vector<int>v3;
	v3.resize(v1.size() + v2.size());
	vector<int>::iterator pos=set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	for_each(v3.begin(), pos, [](int a){cout << a << ' '; });
}

/*
set_difference�㷨 ������set���ϵĲ
ע��:�������ϱ�������������
@param beg1 ����1��ʼ������
@param end1 ����1����������
@param beg2 ����2��ʼ������
@param end2 ����2����������
@param dest  Ŀ��������ʼ������
@return Ŀ�����������һ��Ԫ�صĵ�������ַ
*/

void test03()
{
	vector<int>v1;
	for (int i = 0; i < 10; ++i)
	{
		v1.push_back(i);
	}

	vector<int>v2;
	for (int i = 0; i < 10; ++i)
	{
		v2.push_back(i + 5);
	}
	vector<int>v3;
	v3.resize(v2.size() > v1.size() ? v2.size() : v1.size());
	cout << v3.size() << endl;
	for_each(v1.begin(), v1.end(), [](int a){cout << a << ' '; });
	cout << endl;
	for_each(v2.begin(), v2.end(), [](int a){cout << a << ' '; });
	cout << endl;
	vector<int>::iterator pos = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	for_each(v3.begin(), pos, [](int a){cout << a << ' '; });

}





int main(){


	//test();
	//test01();
	test03();
	system("pause");
	return EXIT_SUCCESS;
}