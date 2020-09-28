#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
using namespace std;

//���� vector
#include <vector>

//ʹ��ϵͳ�㷨��ͷ�ļ�
#include <algorithm>



// ������ ��������  ��ָ�����
//��ָͨ��Ҳ��һ�ֵ�����
void test01()
{
	int array[5] = { 1, 3, 5, 6, 8 };

	int * p = array; //ָ��ָ�������׵�ַ  &array[0]

	for (int i = 0; i < 5;i ++)
	{
		//cout << array[i] << endl;
		cout << *(p++) << endl;
	}
}


void myPrint(int v)
{
	cout << v << endl;
}

void test02()
{
	//��������
	vector<int> v; //����һ������  ��������д��int�������� ��������v
	//�������м�������

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	//���������е�����
	//���õ�����

	vector<int>::iterator itBegin = v.begin(); // itBeginָ�����v�����е���ʼλ��

	vector<int>::iterator itEnd = v.end(); //itEndָ��v���������һ��λ�õ���һ����ַ

	//while (itBegin != itEnd)
	//{
	//	cout << *itBegin << endl;

	//	itBegin++;
	//}


	//�ڶ��ֱ�����ʽ
	//for (int i = 0; i < 10;i++)
	//for (vector<int>::iterator it = v.begin(); it != v.end();it++)
	//{
	//	cout << *it << endl;
	//}

	//�����ַ�ʽ �����㷨
	for_each(v.begin(), v.end(), myPrint);


}
//�����Զ�����������
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	string m_Name;
	int m_Age;
};

void test03()
{
	vector<Person> v;
	Person p1("��ͷ����", 10);
	Person p2("Сͷ�ְ�", 32);
	Person p3("����������", 30);
	Person p4("Χȹ����", 28);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	//����
	for (vector<Person>::iterator it = v.begin(); it != v.end();it++)
	{
		cout << "����: " << (*it).m_Name << " ���䣺" << it->m_Age << endl;
	}
}

//����Զ����������͵�ָ��
void test04()
{
	vector<Person *> v;
	Person p1("��ͷ����", 10);
	Person p2("Сͷ�ְ�", 32);
	Person p3("����������", 30);
	Person p4("Χȹ����", 28);

	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);

	for (vector<Person*>::iterator it = v.begin(); it != v.end();it++)
	{
		cout << "�������� " << (*it)->m_Name << " ���䣺 " << (*it)->m_Age << endl;
	}

}

//����Ƕ������
void test05()
{
	vector<vector<int>> v;

	vector<int>v1;
	vector<int>v2;
	vector<int>v3;


	for (int i = 0; i < 5;i++)
	{
		v1.push_back(i);
		v2.push_back(i + 10);
		v3.push_back(i + 100);
	}
	//��С�������뵽��������
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);

	//������������
	for (vector<vector<int>>::iterator it = v.begin(); it != v.end();it++)
	{
		for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end();vit++)
		{
			cout << *vit << " ";
		}
		cout << endl;
		 
	}

}


int main(){

	//test01();

	//test02();
	//test03();
	//test04();
	test05();
	return EXIT_SUCCESS;
}