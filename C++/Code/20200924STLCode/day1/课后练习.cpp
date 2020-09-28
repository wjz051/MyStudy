#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
#include<deque>
#include<algorithm>
#include<ctime>
#define N 10
using namespace std;
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
	//��ʼ������
	Person(string name)
	{
		this->name = name;
		this->score = 0;	
	}

	//��ȡ����
	void getscre(int *arr,int len)
	{
		this->arr = arr;
		this->arrsize = len;
	}

	//��ӡ����
	void print()
	{
		for (int i = 0; i < this->arrsize; ++i)
		{
			cout <<*(arr + i) << endl;
		}
	}

	//��ȡƽ��ֵ
	void getScore(int score)
	{
		this->score = score;
	}

	//��ӡ������Ϣ
	void show()
	{
		cout << "����:" << this->name << endl;
		cout << "ƽ����:" << this->score << endl;
	}

	//���غ�������
	int retarrsize()
	{
		return this->arrsize;
	}

	//��������
	int *setarr()
	{
		return this->arr;
	}

private:
	int *arr;
	string name;
	int score;
	int arrsize;
};




void test()
{
	vector<Person *>v;


	Person p1("A");
	Person p2("B");
	Person p3("C");
	Person p4("D");
	Person p5("E");

	time_t ts;
	unsigned int data = time(&ts);
	srand(data);
	int arr1[N] = { 0 };
	for (int i = 0; i < N; ++i)
	{
		arr1[i] = rand() % 100 + 1;
	}


	//����,ȥ��������С��

	p1.getscre(arr1,N);
	p2.getscre(arr1,N);
	p3.getscre(arr1,N);
	p4.getscre(arr1,N);
	p5.getscre(arr1,N);

	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	v.push_back(&p5);
	p1.print();
	cout << "------------------------" << endl;

	for (vector<Person *>::iterator it = v.begin(); it != v.end(); ++it)
	{
		int ave = 0;
		deque<int>v1;
		for (int i = 0; i < (*it)->retarrsize(); ++i)
		{
			v1.push_back((*it)->setarr()[i]);
		}
		//����
		sort(v1.begin(), v1.end());
		v1.pop_front();
		v1.pop_back();

		//��ƽ����
		for (deque<int>::iterator tt = v1.begin(); tt != v1.end(); ++tt)
		{
			ave += (*tt);
		}
		ave /= v1.size();

		//��ƽ��ֵ����ȥ
		(*it)->getScore(ave);
	}


	p1.show();
	p2.show();
	p3.show();
	p4.show();
	p5.show();

}




int main(){


	test();
	//string::npos;
	system("pause");
	return EXIT_SUCCESS;
}