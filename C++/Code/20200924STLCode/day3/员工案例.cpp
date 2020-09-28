#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<ctime>
using namespace std;
enum{ RENLI, MEISHU, JISHU };
//Ա����
class worlk
{
public:

	string m_name;
	int m_money;
};

//������
void insert(vector<worlk> &v, multimap<int, worlk> &m)
{
	for (vector<worlk>::iterator it = v.begin(); it != v.end(); ++it)
	{
		m.insert(make_pair(rand() % 3, *it));
	}
}

//��ӡ
void print(multimap<int, worlk> &m)
{
	for (multimap<int, worlk>::iterator it = m.begin(); it != m.end(); it++)
	{

		cout << "����:" << it->second.m_name << " ����:" << it->second.m_money << endl;
	}
}

//�ֲ�����ʾ
void printfwordk(multimap<int, worlk> &m)
{
	
	multimap<int, worlk>::iterator it = m.find(RENLI);
	int pos=m.count(RENLI);
	int size = 0;
	cout << "������" << endl;
	for (; it != m.end(), size < pos; size++, it++)
	{
		cout << "����:" << (*it).second.m_name << " ����:" << (*it).second.m_money << endl;
	}
	pos = m.count(MEISHU);
	size = 0;
	cout << "������" << endl;
	for (; it != m.end(), size < pos; size++, it++)
	{
		cout << "����:" << (*it).second.m_name << " ����:" << (*it).second.m_money << endl;
	}
	pos = m.count(JISHU);
	size = 0;
	cout << "������" << endl;
	for (; it != m.end(), size < pos; size++, it++)
	{
		cout << "����:" << (*it).second.m_name << " ����:" << (*it).second.m_money << endl;
	}
}




void test()
{
	vector<worlk> v;
	multimap<int, worlk> m;
	string str = "ABCDE";
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 5; ++i)
	{
		worlk p1;
		string name = "Ա��";
		name += str[i];
		p1.m_name = name;
		p1.m_money = rand() % 10000 + 10000;
		v.push_back(p1);
	}
	insert(v, m);
	print(m);
	printfwordk(m);
	
}



int main(){


	test();
	system("pause");
	return EXIT_SUCCESS;
}