#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//STL �е����� �㷨 ������
void test01(){
	vector<int> v; //STL �еı�׼����֮һ ����̬����
	v.push_back(1); //vector �����ṩ�Ĳ������ݵķ���
	v.push_back(5);
	v.push_back(3);
	v.push_back(7);
	//������
	vector<int>::iterator pStart = v.begin(); //vector �����ṩ�� begin()���� ����ָ���һ��Ԫ�صĵ�����
	vector<int>::iterator pEnd = v.end(); //vector �����ṩ�� end()���� ����ָ�����һ��Ԫ����һ��λ�õĵ�����
	//ͨ������������
	while (pStart != pEnd){
		cout << *pStart << " ";
		pStart++;
	}
	cout << endl;
	//�㷨 count �㷨 ����ͳ��Ԫ�صĸ���
	int n = count(pStart, pEnd, 5);
	cout << "n:" << n << endl;
}
//STL �������������Դ洢�����������ͣ�Ҳ���Դ洢�����
class Teacher
{
public:
	Teacher(int age) :age(age){};
	~Teacher(){};
public:
	int age;
};
void test02(){
	vector<Teacher> v; //�洢 Teacher �������ݵ�����
	Teacher t1(10), t2(20), t3(30);
	v.push_back(t1);
	v.push_back(t2);
	v.push_back(t3);
	vector<Teacher>::iterator pStart = v.begin();
	vector<Teacher>::iterator pEnd = v.end();
	//ͨ������������
	while (pStart != pEnd){
		cout << pStart->age << " ";
		pStart++;
	}
	cout << endl;
}
//�洢 Teacher ����ָ��
void test03(){
	vector<Teacher*> v; //�洢 Teacher ����ָ��
	Teacher* t1 = new Teacher(10);
	Teacher* t2 = new Teacher(20);
	Teacher* t3 = new Teacher(30);
	v.push_back(t1);
	v.push_back(t2);
	v.push_back(t3);
	//�õ�����������
	vector<Teacher*>::iterator pStart = v.begin();
	vector<Teacher*>::iterator pEnd = v.end();
	//ͨ������������
	while (pStart != pEnd){
		cout << (*pStart)->age << " ";
		pStart++;
	}
	cout << endl;
}
//����Ƕ������ �ѵ�(����⣬��������)
void test04()
{
	vector< vector<int> > v;
	vector<int>v1;
	vector<int>v2;
	vector<int>v3;

	for (int i = 0; i < 5; i++)
	{
		v1.push_back(i);
		v2.push_back(i * 10);
		v3.push_back(i * 100);
	}
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);

	for (vector< vector<int> >::iterator it = v.begin(); it != v.end(); it++)
	{
		for (vector<int>::iterator subIt = (*it).begin(); subIt != (*it).end(); subIt++)
		{
			cout << *subIt << " ";
		}
		cout << endl;
	}
}
int main(){
	//test01();
	//test02();
	//test03();
	test04();
	system("pause");
	return EXIT_SUCCESS;
}
