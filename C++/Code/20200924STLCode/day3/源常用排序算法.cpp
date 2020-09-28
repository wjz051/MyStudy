#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<functional>
#include<ctime>
#include<vector>
#include<string>
using namespace std;
/*
merge�㷨 ����Ԫ�غϲ������洢����һ������  ���������� ����Ҳ�������
@param beg1 ����1��ʼ������
@param end1 ����1����������
@param beg2 ����2��ʼ������
@param end2 ����2����������
@param dest  Ŀ��������ʼ������
*/


void print(int v)
{
	cout << v << " ";
}



void test()
{
	vector<int>p1;
	vector<int>p2;

	for (int i = 0; i < 10; ++i)
	{
		p1.push_back(i*2);
		p2.push_back(i * 2 + 1);
	}
	vector<int>p3;
	p3.resize(p1.size() + p2.size());
	
	merge(p1.begin(), p1.end(), p2.begin(), p2.end(),p3.begin());
	//����������Ԫ��  [](��������������){cout << v <<" "; }
	//for_each(p3.begin(), p3.end(), [](int v){cout << v <<" "; });
	for_each(p3.begin(), p3.end(), print);
}

class Person
{
public:
	Person(){}
	Person(string name, int age)
	{
		this->m_name = name;
		this->m_age = age;
	}
	string m_name;
	int m_age;
};

class compare
{
public:
	bool operator()(Person &p1, Person &p2)
	{
		return p1.m_age > p2.m_age;
	}
};





void test02()
{
	Person p1("aaa", 10);
	Person p2("bbb", 12);
	Person p3("ccc", 14);
	Person p4("ddd", 16);
	Person p5("eee", 18);

	Person p6("fff", 11);
	Person p7("ggg", 13);
	Person p8("kkk", 15);
	Person p9("nnn", 17);

	
	vector<Person>v1;
	vector<Person>v2;
	v1.push_back(p1);
	v1.push_back(p2);
	v1.push_back(p3);
	v1.push_back(p4);
	v1.push_back(p5);
	v2.push_back(p6);
	v2.push_back(p7);
	v2.push_back(p8);
	v2.push_back(p9);
	

	vector<Person>v3;
	v3.resize(v1.size() + v2.size());
	
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin(), compare());

	for (vector<Person>::iterator it = v3.begin(); it != v3.end(); ++it)
	{
		cout << it->m_name << it->m_age << endl;
	}
}

/*
sort�㷨 ����Ԫ������
ע��:�������������������
@param beg ����1��ʼ������
@param end ����1����������
@param _callback �ص���������ν��(����bool���͵ĺ�������)
*/

void test03()
{
	vector<int>v1;
	v1.push_back(10);
	v1.push_back(50);
	v1.push_back(30);
	v1.push_back(20);
	v1.push_back(60);
	v1.push_back(40);

	//sort ����algorithmͷ�ļ�
	sort(v1.begin(), v1.end());
	for_each(v1.begin(), v1.end(), [](int v){cout << v << " "; });
}


//random_shuffle(iterator beg, iterator end) ϴ��
void test04()
{
	vector<int>v;
	for (int i = 0; i < 10; ++i)
	{
		v.push_back(i);
	}
	//ϴ���㷨
	random_shuffle(v.begin(), v.end());
	for_each(v.begin(), v.end(), [](int v){cout << v << " "; });
}






void test05()
{
	vector<Person>v1;
	Person p1("aaa", 10);
	Person p2("bbb", 12);
	Person p3("ccc", 14);
	Person p4("ddd", 16);
	Person p5("eee", 18);

	Person p6("fff", 11);
	Person p7("ggg", 13);
	Person p8("kkk", 15);
	Person p9("nnn", 17);
	v1.push_back(p1);
	v1.push_back(p2);
	v1.push_back(p3);
	v1.push_back(p4);
	v1.push_back(p5);

	sort(v1.begin(), v1.end(), compare());

	for (vector<Person>::iterator it = v1.begin(); it != v1.end(); ++it)
	{
		cout << it->m_name << it->m_age << endl;
	}
}

class myprint
{
public:
	void operator()(int pr)
	{
		cout << pr << endl;
	}
};




//random_shuffle(iterator beg, iterator end) ϴ��
void test07()
{
	vector<int>v;

	for (int i = 0; i < 10; ++i)
	{
		v.push_back(i);
	}

	for_each(v.begin(), v.end(), myprint());
	//ϴ���㷨
	random_shuffle(v.begin(), v.end());
	
	for_each(v.begin(), v.end(), myprint());

}

void test08()
{
	myprint p1;
	p1(10);


}




int main()
{
	srand((unsigned int)time(NULL));
	//test();
	//test02();
	//test03();
	//test04();
	//test05();
	//test07();
	test08();
	system("pause");
	return EXIT_SUCCESS;
}
