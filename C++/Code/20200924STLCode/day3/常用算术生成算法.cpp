#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<numeric>
#include<iterator>
#include<vector>
#include<algorithm>
using namespace std;
/*
accumulate�㷨 ��������Ԫ���ۼ��ܺ�
@param beg ������ʼ������
@param end ��������������
@param value ��ʼֵ�������ۼ�֮���ټ������ֵ
*/

void test01()
{
	vector<int>v;
	for (int i = 0; i < 5; ++i)
	{
		v.push_back(i);
	}
	cout << accumulate(v.begin(), v.end(), 0) << endl;

}

/*
fill�㷨 �����������Ԫ��
@param beg ������ʼ������
@param end ��������������
@param value t���Ԫ��
*/

void test02()
{
	vector<int>v;
	//for (int i = 0; i < 5; ++i)
	//{
	//	v.push_back(i);
	//}
	//fill(v.begin(), v.end(), 20);
	v.resize(10);
	fill(v.begin(), v.end(), 10);
	for_each(v.begin(), v.end(), [](int a){cout << a << endl; });

}




int main(){


	//test01();
	test02();
	system("pause");
	return EXIT_SUCCESS;
}