#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>//������������Ҫ������ͷ�ļ�
using namespace std;

//����������
class MyPrint :public binary_function<int, int, void >
{
public:
	void operator()(int v,int start) const
	{
		cout << "v=" << v << " start=" << start << " v+start=" << v + start << endl;
	
	}

};





void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; ++i)
	{
		v.push_back(i);
	}
	cout << "��������ʼֵ" << endl;
	int num;
	cin >> num;
	//for_each(v.begin(), v.end(), bind1st(MyPrint(), num));
	//bind1st�ǽ������󶨵���һ������
	//bind2nd�ǽ���������󶨵��׵ڶ�������
	//��Ա����������
	for_each(v.begin(), v.end(), bind2nd(MyPrint(), num));
}


//1�������� bind2nd(MyPrint(), num)
//2���̳��� binary_function<��������1, ��������2, �������� >
//3����const���� operator()

class GreaterThenFive :public unary_function < int, bool >
{
	bool operator()(int v)const
	{
		return v > 5;
	}
};


//ȡ��������
void test02()
{
	vector<int>v;
	for (int i = 0; i < 10; ++i)
	{
		v.push_back(i);
	}
	//���Ҵ���5������
	//�����Ϊ��С��5����
	vector<int>::iterator pos = find_if(v.begin(), v.end(), not1(GreaterThenFive()));

}



int main(){

	//test01();
	test02();
	system("pause");
	return EXIT_SUCCESS;
}