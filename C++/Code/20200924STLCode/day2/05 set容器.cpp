#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//set  multisetͷ�ļ�
#include <set>
#include <string>

/*
set���캯��
set<T> st;//setĬ�Ϲ��캯����
mulitset<T> mst; //multisetĬ�Ϲ��캯��:
set(const set &st);//�������캯��
3.7.2.2 set��ֵ����
set& operator=(const set &st);//���صȺŲ�����
swap(st);//����������������
3.7.2.3 set��С����
size();//����������Ԫ�ص���Ŀ
empty();//�ж������Ƿ�Ϊ��

3.7.2.4 set�����ɾ������
insert(elem);//�������в���Ԫ�ء�
clear();//�������Ԫ��
erase(pos);//ɾ��pos��������ָ��Ԫ�أ�������һ��Ԫ�صĵ�������
erase(beg, end);//ɾ������[beg,end)������Ԫ�� ��������һ��Ԫ�صĵ�������
erase(elem);//ɾ��������ֵΪelem��Ԫ�ء�

*/

void printSet( set<int>& s)
{
	for (set<int>::iterator it = s.begin(); it != s.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	set<int>s1;
	//����ʽ���� key�������򣬴�С����
	s1.insert(5);
	s1.insert(1);
	s1.insert(9);
	s1.insert(3);
	s1.insert(7);
	printSet(s1);

	if (s1.empty())
	{
		cout << "��" << endl;
	}
	else
	{
		cout << "size = " << s1.size() << endl;
	}

	s1.erase(s1.begin()); // 3 5 7 9
	printSet(s1);
	s1.erase(3); //  5 7 9
	printSet(s1);
}

/*
set���Ҳ���
find(key);//���Ҽ�key�Ƿ����,�����ڣ����ظü���Ԫ�صĵ��������������ڣ�����set.end();
count(key);//���Ҽ�key��Ԫ�ظ���
lower_bound(keyElem);//���ص�һ��key>=keyElemԪ�صĵ�������
upper_bound(keyElem);//���ص�һ��key>keyElemԪ�صĵ�������
equal_range(keyElem);//����������key��keyElem��ȵ������޵�������������

*/

void test02()
{
	set<int>s1;
	s1.insert(5);
	s1.insert(1);
	s1.insert(9);
	s1.insert(3);
	s1.insert(7);
	//����set û��value  key����value

	set<int>::iterator pos = s1.find(2);
	//�ж��Ƿ��ҵ�
	if (pos != s1.end())
	{
		cout << "�ҵ��ˣ�ֵΪ��" << *pos << endl;
	}
	else
	{
		cout << "δ�ҵ�" << endl;
	}

	//count(key);//���Ҽ�key��Ԫ�ظ��� set���� ��� 0����1 

	int num =  s1.count(2);
	cout <<  "2�ĸ���Ϊ�� " << num << endl;


	//lower_bound(keyElem);//���ص�һ��key>=keyElemԪ�صĵ�������
	set<int>::iterator it =  s1.lower_bound(3); // 10����δ�ҵ�
	if (it!= s1.end())
	{
		cout << "�ҵ��� lower_bound (3)��ֵΪ��" << *it << endl;
	}
	else
	{
		cout << "δ�ҵ�" << endl;
	}
	// upper_bound(keyElem);//���ص�һ��key>keyElemԪ�صĵ�������
	set<int>::iterator it2 = s1.upper_bound(3);
	if (it2 != s1.end())
	{
		cout << "�ҵ��� upper_bound (3)��ֵΪ��" << *it2 << endl;
	}
	else
	{
		cout << "δ�ҵ�" << endl;
	}

	//equal_range(keyElem);//����������key��keyElem��ȵ������޵�������������
	//������ ����lower_bound   upper_bound
	pair<set<int>::iterator, set<int>::iterator>  ret =  s1.equal_range(3);
	//��ȡ��һ��ֵ

	if (ret.first != s1.end())
	{
		cout << "�ҵ�equal_range�� lower_bound ��ֵ ��" << *(ret.first) << endl;
	}
	else
	{
		cout << "δ�ҵ�" << endl;
	}

	//��ȡ�ڶ���ֵ
	if (ret.second != s1.end())
	{
		cout << "�ҵ�equal_range�� upper_bound ��ֵ ��" << *(ret.second) << endl;
	}
	else
	{
		cout << "δ�ҵ�" << endl;
	}
	
}


//set���� ����������ظ��ļ�ֵ
void test03()
{
	set<int> s1;
	pair<set<int>::iterator,bool> ret =  s1.insert(10);

	if (ret.second)
	{
		cout << "����ɹ�" << endl;
	}
	else
	{
		cout << "����ʧ��" << endl;
	}

	ret = s1.insert(10);
	if (ret.second)
	{
		cout << "�ڶ��β���ɹ�" << endl;
	}
	else
	{
		cout << "�ڶ��β���ʧ��" << endl;
	}

	printSet(s1);
	

	//multiset��������ظ�ֵ
	multiset<int> mul;
	mul.insert(10);
	mul.insert(10);

}

//ָ��set������� �Ӵ�С
//�º���
class myCompare
{
public:
	//���� ()
	bool operator()( int v1 ,int v2)
	{
		return v1 > v2;
	}
};


//set��������
void test04()
{
	set<int,myCompare>s1;
	
	s1.insert(5);
	s1.insert(1);
	s1.insert(9);
	s1.insert(3);
	s1.insert(7);

	//printSet(s1);

	//�Ӵ�С����
	//�ڲ���֮ǰ��ָ���������

	for (set<int, myCompare>::iterator it = s1.begin(); it != s1.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;

}

//�Զ�����������
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

class myComparePerson
{
public:
	bool operator()( const Person & p1, const Person & p2)
	{
		if (p1.m_Age > p2.m_Age) //����
		{
			return true;
		}
		return false;
	}

};

void test05()
{
	set<Person, myComparePerson> s1;

	Person p1("����", 100);
	Person p2("����", 90);
	Person p3("����", 10);
	Person p4("үү", 1000);

	s1.insert(p1);
	s1.insert(p2);
	s1.insert(p3);
	s1.insert(p4);

	//�����Զ����������ͣ�������ָ�����������

	//��ʾ
	for (set<Person, myComparePerson>::iterator it = s1.begin(); it != s1.end();it++)
	{
		cout << "������" << (*it).m_Name << " ���䣺 " << it->m_Age << endl;
	}

}

int main(){

	//test01();

	test02();

	//test03();

	//test04();

	//test05();

	// system("pause");
	return 0;
}