#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<functional>
using namespace std;


/*
template<class T> T plus<T>//�ӷ��º���
template<class T> T minus<T>//�����º���
template<class T> T multiplies<T>//�˷��º���
template<class T> T divides<T>//�����º���
template<class T> T modulus<T>//ȡģ�º���
template<class T> T negate<T>//ȡ���º���


*/

/*
template<class T> bool equal_to<T>//����
template<class T> bool not_equal_to<T>//������
template<class T> bool greater<T>//����
template<class T> bool greater_equal<T>//���ڵ���
template<class T> bool less<T>//С��
template<class T> bool less_equal<T>//С�ڵ���


*/

void test()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	plus<int>p;
	cout << p(1, 1) << endl;


}

int main(){


	test();
	system("pause");
	return EXIT_SUCCESS;
}