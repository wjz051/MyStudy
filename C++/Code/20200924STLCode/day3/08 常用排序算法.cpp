#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <functional>
#include <ctime>
/*
merge�㷨 ����Ԫ�غϲ������洢����һ������  ���������� ����Ҳ�������
@param beg1 ����1��ʼ������
@param end1 ����1����������
@param beg2 ����2��ʼ������
@param end2 ����2����������
@param dest  Ŀ��������ʼ������
*/
void test01()
{
	vector<int>v1;
	vector<int>v2;

	for (int i = 0; i < 10;i++)
	{
		v1.push_back(i);
		v2.push_back(i + 1);
	}

	vector<int>vTarget;
	vTarget.resize(v1.size() + v2.size());
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

	for_each(vTarget.begin(), vTarget.end(), [](int v){ cout << v << " "; });
}

/*
sort�㷨 ����Ԫ������
ע��:�������������������
@param beg ����1��ʼ������
@param end ����1����������
@param _callback �ص���������ν��(����bool���͵ĺ�������)
*/
void test02()
{
	vector<int>v1;

	v1.push_back(10);
	v1.push_back(40);
	v1.push_back(20);
	v1.push_back(90);
	v1.push_back(50);


	sort(v1.begin(), v1.end());
	for_each(v1.begin(), v1.end(), [](int val){cout << val << " "; });
	cout << endl;

	sort(v1.begin(), v1.end(), greater<int>());
	for_each(v1.begin(), v1.end(), [](int val){cout << val << " "; });
	cout << endl;
}

//random_shuffle(iterator beg, iterator end) ϴ��
void test03()
{
	vector<int>v;
	for (int i = 0; i < 10;i++)
	{
		v.push_back(i);
	}
	random_shuffle(v.begin(), v.end());
	for_each(v.begin(), v.end(), [](int val){cout << val << " "; });
}

//reverse(iterator beg, iterator end)
void test04()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	reverse(v.begin(), v.end());
	for_each(v.begin(), v.end(), [](int val){cout << val << " "; });
}



int main(){
	srand((unsigned int)time(NULL));

	//test01();

	//test02();

	//test03();

	test04();

	system("pause");
	return EXIT_SUCCESS;
}