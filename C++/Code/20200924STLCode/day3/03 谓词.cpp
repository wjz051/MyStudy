#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

class GreaterThen20
{
public:
	bool operator()(int val)
	{
		return val > 20;
	}
};

//һԪν��
void test01()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	//���ҵ�һ������20������

	//���������� ��������  ��������
	vector<int>::iterator pos = find_if(v.begin(), v.end(), GreaterThen20());
	if (pos!=v.end())
	{
		cout << "�ҵ�����20������Ϊ��" << *pos << endl;
	}
	else
	{
		cout << "δ�ҵ�" << endl;
	}
}

//��Ԫν��
class MyCompare
{
public:
	bool operator()(int v1 ,int v2)
	{
		return v1 > v2;
	}
};
void test02()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	sort(v.begin(), v.end(), MyCompare());

	//��������  lambda���ʽ  [](){};
	for_each(v.begin(), v.end(), [](int val){ cout << val << " "; });
}


int main(){

//	test01();

	test02();

	system("pause");
	return EXIT_SUCCESS;
}