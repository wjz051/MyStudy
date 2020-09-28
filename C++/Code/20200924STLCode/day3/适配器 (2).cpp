#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<string>
using namespace std;

//1��������bind2nd
//2���̳��� binary_function<��������1����������2������ֵ����>
//3����const���� operaator()

//
//class MyPrint :public binary_function < int, int ,void >
//{
//public:
//	void operator()(int a, int b)const
//	{
//		cout << "v=" << a << " b=" << b << endl;
//	}
//};
//
//
//
//void teat01()
//{
//	vector<int>v;
//	for (int i = 0; i < 10; ++i)
//	{
//		v.push_back(i);
//	}
//	//�滻�ṹ���еĲ���������滻��һ�����������еĵ����ݴ��ݸ��ڶ���
//	for_each(v.begin(), v.end(), bind2nd(MyPrint(), 10));
//}
//binary_function<int,int, bool>
class compare:public unary_function<int,bool>
{
public:
	bool operator()(int i)const
	{
		return i > 5;
	}
};



void test02()
{
	//һԪȡ��
	//not1
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	//���Ҵ���5������
	//��Ҫ��Ϊ ��С��5������
	//vector<>                                                  //��������
	vector<int>::iterator pos=find_if(v.begin(), v.end(), not1(bind2nd(greater<int>(), 5)));
	cout << *pos << endl;
}





void compareper(int a,int sta)
{
	cout << a + sta << endl;
};



void test03()
{
	vector < int > v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	//�������������ǽ�����ָ������Ϊ��������Ȼ���100�󶨵ĵ���������Ĳ�����
	for_each(v.begin(), v.end(), bind2nd(ptr_fun(compareper), 100));

}


void test07()
{
	mem_fun_ref()


}




int main(){


	//teat01();
	//est02();
	test03();
	system("pause");
	return EXIT_SUCCESS;
}