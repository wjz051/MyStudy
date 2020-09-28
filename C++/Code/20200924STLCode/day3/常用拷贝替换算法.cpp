#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
#include<functional>
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
	vector<int>v1;
	 
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	v1.resize(v.size());
	copy(v.begin(), v.end(), v1.begin());

	for_each(v1.begin(), v1.end(), [](int a){cout << a << ' '; });


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

void test02()
{
	vector<int>v1;
	for (int i = 0; i < 10; ++i)
	{
		v1.push_back(i);
	}
	for_each(v1.begin(), v1.end(), [](int a){cout << a << " "; });
	cout << endl;
	replace(v1.begin(), v1.end(), 3, 300);
	for_each(v1.begin(), v1.end(), [](int a){cout << a << " "; });
	cout << endl;

}

class compare :public binary_function<int, int, bool>
{
public:
	bool operator()(int a, int b)const
	{
		if (a > b)
		{
			return true;
		}
		return false;
	}
};

void test03()
{
	vector<int>v;
	for (int i = 0; i < 10; ++i)
	{
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), [](int a){cout << a << " "; });
	cout << endl;
	replace_if(v.begin(), v.end(), bind2nd(compare(),5), 5);
	for_each(v.begin(), v.end(), [](int a){cout << a << " "; });
}


/*
swap�㷨 ��������������Ԫ��
@param c1����1
@param c2����2
*/


void testt04()
{
	vector<int>v;
	vector<int>v1;
	for (int i = 0; i < 10; ++i)
	{
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), [](int a){cout << a << ' '; });
	cout << endl;
	v1.reserve(v.size());
	swap(v, v1);
	for_each(v1.begin(), v1.end(), [](int a){cout << a << ' '; });
	cout << endl;
	cout << v.size() << endl;
	for_each(v.begin(), v.end(), [](int a){cout << a << ' '; });
	cout << endl;
}



int main(){


	//test01();
	//test02();
	//test03();
	testt04();
	system("pause");
	return EXIT_SUCCESS;
}