/*
	create by zt  
	2017 4 26
	�ļ� ���ܡ�����

	func()�����������  ����1 ������
*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <vector>
#include <string>
#include <deque>
#include <algorithm>
#include <ctime>
/*
��5��ѡ�֣�ѡ��ABCDE��10����ί�ֱ��ÿһ��ѡ�ִ�֣�ȥ����߷֣�ȥ����ί����ͷ֣�ȡƽ���֡�
//1. ��������ѡ�֣��ŵ�vector��
//2. ����vector������ȡ����ÿһ��ѡ�֣�ִ��forѭ�������԰�10�����ִ�ִ浽deque������
//3. sort�㷨��deque�����з�������pop_back pop_frontȥ����ߺ���ͷ�
//4. deque��������һ�飬�ۼӷ������ۼӷ���/d.size()
//5. person.score = ƽ����
*/

class Person
{
public:
	Person(string name, int score)
	{
		this->m_Name = name;
		this->m_Socre = score;
	}

	string m_Name; //����
	int m_Socre; //���� ƽ����
};


void createPerson( vector<Person>&v)
{
	string nameSeed = "ABCDE";
	for (int i = 0; i < 5;i++)
	{
		string name = "ѡ��";
		name += nameSeed[i];

		int score = 0;
		Person p(name, score);

		v.push_back(p);
	}
}


void setScore(vector<Person>&v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end();it++)
	{

		//��5���˽��д��
		deque<int>d;
		for (int i = 0; i < 10;i++)
		{
			int score = rand() % 41 + 60; //60 ~ 100

			d.push_back(score);
		}

		//�ȿ��´��
		//for (deque<int>::iterator dit = d.begin(); dit != d.end();dit++)
		//{
		//	cout << *dit << " ";
		//}
		//cout << endl;

		//���� ��С����
		sort(d.begin(), d.end());

		//ȥ�� ��� �� ���
		d.pop_back(); //���
		d.pop_front();

		int sum = 0;//�ܷ�
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			sum += *dit;
		}

		//ƽ����
		int avg = sum / d.size();

		it->m_Socre = avg;
	}

}

void showSocre(vector<Person> &v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "������" << it->m_Name << " ����ƽ����Ϊ�� " << it->m_Socre << endl;
	}

}


int main(){

	//�������������
	srand((unsigned int)time(NULL));

	//��������  ��� ѡ��
	vector<Person>v;

	//����5��ѡ��
	createPerson(v);
	
	//���
	setScore(v);

	//չʾƽ����
	showSocre(v);


	//����
	//for (vector<Person>::iterator it = v.begin(); it != v.end();it++)
	//{
	//	cout << "������" << (*it).m_Name << endl;
	//}

	
	

	system("pause");
	return EXIT_SUCCESS;
}