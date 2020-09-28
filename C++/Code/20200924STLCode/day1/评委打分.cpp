#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<algorithm>
#include<ctime>
#include<vector>
#include<deque>

using namespace std;
//��ί��
class Judge
{
public:
	Judge(){};
	Judge(string name)
	{
		this->name = name;	
	}
	string name;
	
	double getgrade()
	{
		return (double)(rand() % 10+1);
	}
};


//����
class swan
{
public:
	swan(){};
	swan(string name)
	{
		this->name = name;
	}

	void getaverage(double average)
	{
		this->average = average;
	}

	double average;
	string name;
};

//��ӡ��ί��Ϣ
void printJudge(vector<Judge> &J)
{

	for (vector<Judge>::iterator it = J.begin(); it != J.end(); ++it)
	{
		cout << "��ί����" << (*it).name << endl;
	}

}

//��ӡѡ����Ϣ
void printPlayer(vector<swan> &S)
{
	for (vector<swan>::iterator it = S.begin(); it != S.end(); ++it)
	{
		cout << "����:" << (*it).name << endl;
		cout << "ƽ�ַ�:" << (*it).average << endl;
	}

}


void StatisticsGrade(vector<swan> &S, vector<Judge> &J)
{
	if ( &S == NULL || &J == NULL)
	{
		throw(0);
	}
	for (vector<swan>::iterator it = S.begin(); it != S.end(); ++it)
	{
		deque<double>V;
		double aver = 0.0;
		//��ȡ������������
		for (vector<Judge>::iterator st = J.begin(); st != J.end(); ++st)
		{
			V.push_back((*st).getgrade());
		}
		//��������
		sort(V.begin(), V.end());
		V.pop_back();
		V.pop_front();
		//
		for (deque<double>::iterator av = V.begin(); av != V.end(); ++av)
		{
			aver += (*av);
		}

		aver /= V.size();
		aver += (double)90.0;
		(*it).getaverage(aver);
	}

}




void personnel(int judge, int playe)
{
	//������������ѡ�֣�������ί
	vector<Judge> J;
	vector<swan> S;
	//������ί��Ϣ��vector����
	for (int i = 0; i < judge; ++i)
	{
		Judge p1;
		char buf[64] = { 0 };
		sprintf(buf, "Judge_%c", 'A'+i);
		p1.name = buf;
		J.push_back(p1);
	}
	//����ѡ����Ϣ��vector������
	for (int i = 0; i < playe; ++i)
	{
		swan p1;
		char buf[64] = { 0 };
		sprintf(buf, "Playe_%c", 'A'+ i);
		p1.name = buf;
		S.push_back(p1);
	}

	try{ StatisticsGrade(S, J); }
	catch (int)
	{
		cout << "������������!" << endl;
	}


	StatisticsGrade(S,J);//������ί����������ѡ������
	printJudge(J);//��ӡ��ί��Ϣ
	printPlayer(S);//��ӡѡ����Ϣ

}







void test()
{
	time_t ts;
	unsigned int data = (unsigned int)time(&ts);
	srand(data);
	personnel(5, 5);

}




int main(){


	test();
	system("pause");
	return EXIT_SUCCESS;
}