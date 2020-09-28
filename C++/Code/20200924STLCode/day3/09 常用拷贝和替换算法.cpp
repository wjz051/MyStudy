#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

/*
copy�㷨 ��������ָ����Χ��Ԫ�ؿ�������һ������
@param beg ������ʼ������
@param end ��������������
@param dest Ŀ����ʼ������
*/

void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	vector<int>vTarget;
	vTarget.resize(v.size());

	copy(v.begin(), v.end(), vTarget.begin());

	//for_each(vTarget.begin(), vTarget.end(), [](int val){ cout << val << " "; });

	copy(vTarget.begin(), vTarget.end(), ostream_iterator<int>(cout, " "));
}

/*
replace�㷨 ��������ָ����Χ�ľ�Ԫ���޸�Ϊ��Ԫ��
@param beg ������ʼ������
@param end ��������������
@param oldvalue ��Ԫ��
@param oldvalue ��Ԫ��

replace_if�㷨 ��������ָ����Χ����������Ԫ���滻Ϊ��Ԫ��
@param beg ������ʼ������
@param end ��������������
@param callback�����ص�����ν��(����Bool���͵ĺ�������)
@param oldvalue ��Ԫ��
*/
class MyCompare
{
public:
	bool operator()(int v)
	{
		return v > 3;
	}
};
void test02()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	//���� �������е�3  �滻��300
	replace(v.begin(), v.end(), 3, 300);

	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	//����  �����������д���3������ ���滻�� 30000

	replace_if(v.begin(), v.end(), MyCompare(), 30000);

	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
}

/*
swap�㷨 ��������������Ԫ��
@param c1����1
@param c2����2
*/

void test03()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}

	vector<int>v2;
	v2.push_back(10);
	v2.push_back(30);
	v2.push_back(20);
	v2.push_back(40);

	cout << "����ǰ���ݣ�" << endl;

	copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	cout << "�����������:" << endl;

	swap(v1, v2);

	copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

}


int main(){

	//test01();

	//test02();

	test03();

	system("pause");
	return EXIT_SUCCESS;
}