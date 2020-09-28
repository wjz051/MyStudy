#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <list>
#include <algorithm>
#include <string>
using namespace std;

//list��˫��ѭ������
// void test01()
// {
// 	list<int> myList;
// 	for (int i = 0; i < 10; i++){
// 		myList.push_back(i);
// 	}

// 	list<int>::_Nodeptr node = myList._Myhead->_Next;

// 	for ( int i = 0; i < myList._Mysize * 2; i++){
// 		cout << "Node:" << node->_Myval << endl;
// 		node = node->_Next;
// 		if (node == myList._Myhead){
// 			node = node->_Next;
// 		}
// 	}


// }

//list����API
/*
list���캯��
list<T> lstT;//list���ò���ģ����ʵ��,�����Ĭ�Ϲ�����ʽ��
list(beg,end);//���캯����[beg, end)�����е�Ԫ�ؿ���������
list(n,elem);//���캯����n��elem����������
list(const list &lst);//�������캯����
3.6.4.2 list����Ԫ�ز����ɾ������
push_back(elem);//������β������һ��Ԫ��
pop_back();//ɾ�����������һ��Ԫ��
push_front(elem);//��������ͷ����һ��Ԫ��
pop_front();//��������ͷ�Ƴ���һ��Ԫ��
insert(pos,elem);//��posλ�ò�elemԪ�صĿ��������������ݵ�λ�á�
insert(pos,n,elem);//��posλ�ò���n��elem���ݣ��޷���ֵ��
insert(pos,beg,end);//��posλ�ò���[beg,end)��������ݣ��޷���ֵ��
clear();//�Ƴ���������������
erase(beg,end);//ɾ��[beg,end)��������ݣ�������һ�����ݵ�λ�á�
erase(pos);//ɾ��posλ�õ����ݣ�������һ�����ݵ�λ�á�
remove(elem);//ɾ��������������elemֵƥ���Ԫ�ء�
*/

void printList(list<int>&L)
{
	for (list<int>::iterator it = L.begin(); it != L.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test02()
{
	list<int>L(10,10);
	list<int>L2(L.begin(), L.end());

	printList(L);
	printList(L2);
	L2.push_back(100);

	//�����ӡ
	for (list<int>::reverse_iterator it = L2.rbegin(); it != L2.rend();it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	//list��������֧���������
	list<int>::iterator itBegin = L2.begin();
	//itBegin = itBegin + 1;


	//��������
	list<int>L3;
	L3.push_back(10);
	L3.push_back(30);
	L3.push_back(20);
	L3.push_front(100);
	L3.push_front(300);
	L3.push_front(200);

	printList(L3); //  200 300 100 10 30 20 

	//ɾ����������
	L3.pop_front(); //ͷɾ
	L3.pop_back(); //βɾ
	printList(L3); // 300 100 10 30

	L3.insert(L3.begin(), 1000);
	printList(L3); // 1000 300 100 10 30

	//remove(elem);//ɾ��������������elemֵƥ���Ԫ�ء�
	L3.push_back(10);// 1000 300 100 10 30 10
	L3.remove(10); //���� ֱ�ӷ�ֵ

	printList(L3);//1000 300 100  30
}


/*
list��С����
size();//����������Ԫ�صĸ���
empty();//�ж������Ƿ�Ϊ��
resize(num);//����ָ�������ĳ���Ϊnum��
�������䳤������Ĭ��ֵ�����λ�á�
���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����
resize(num, elem);//����ָ�������ĳ���Ϊnum��
�������䳤������elemֵ�����λ�á�
���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����

3.6.4.4 list��ֵ����
assign(beg, end);//��[beg, end)�����е����ݿ�����ֵ������
assign(n, elem);//��n��elem������ֵ������
list& operator=(const list &lst);//���صȺŲ�����
swap(lst);//��lst�뱾���Ԫ�ػ�����
3.6.4.5 list���ݵĴ�ȡ
front();//���ص�һ��Ԫ�ء�
back();//�������һ��Ԫ�ء�
*/

void test03()
{
	list<int>L3;
	L3.push_back(10);
	L3.push_back(30);
	L3.push_back(20);
	L3.push_front(100);
	L3.push_front(300);
	L3.push_front(200);

	cout << "��С��" << L3.size() << endl;
	if (L3.empty())
	{
		cout << "L3Ϊ��" << endl;
	}
	else
	{
		cout << "L3��Ϊ��" << endl;
	}

	L3.resize(10);
	printList(L3);

	L3.resize(3);
	printList(L3);

	list<int> L4;
	L4.assign(L3.begin(), L3.end());

	//200 300 100
	cout << "front: " << L4.front() << endl;
	cout << "back: " << L4.back() << endl;
}

/*
list��ת����
reverse();//��ת��������lst����1,3,5Ԫ�أ����д˷�����lst�Ͱ���5,3,1Ԫ�ء�
sort(); //list����
*/

bool myCompare(int v1, int v2)
{	
	return v1 > v2; //����
}

void test04()
{
	list<int>L;

	L.push_back(10);
	L.push_back(20);
	L.push_back(40);
	L.push_back(30);

	L.reverse();
	printList(L); // 30 40 20 10

	//���в�֧��������ʵĵ����� ��������ϵͳ�ṩ���㷨
	// �����֧����ϵͳ�ṩ�㷨����ô������ڲ����ṩ
	//sort(L.begin(), L.end()); 
	L.sort(); //��С����

	printList(L);

	//�Ӵ�С
	L.sort(myCompare);
	printList(L);

}

//�Զ�����������
class Person
{
public:
	Person(string name, int age,int height)
	{
		this->m_Name = name;
		this->m_Age = age;
		this->m_Height = height;
	}

	//���� == ��remove ����ɾ���Զ����person����
	bool operator==( const  Person & p)
	{
		if ( this->m_Name == p.m_Name && this->m_Age == p.m_Age && this->m_Height == p.m_Height)
		{
			return true;
		}
		return false;
	}

	string m_Name;
	int m_Age;
	int m_Height; //��� 
};

//Person������� ������� ��ͬ  ������ߵ���������
bool myComparePerson( Person & p1,Person & p2 )
{
	//if (p1.m_Age > p2.m_Age)
	//{
	//	return true;
	//}
	//return false;

	if (p1.m_Age == p2.m_Age)
	{
		return p1.m_Height < p2.m_Height;
	}
	else
	{
		return p1.m_Age > p2.m_Age;
	}
	

}

void test05()
{
	list<Person> L;

	Person p1("��ɪ", 10 , 165);
	Person p2("��������", 20 , 170);
	Person p3("��ǹ", 17,177);
	Person p4("���׸�˹", 19, 120);
	Person p5("MT", 18,200);
	Person p6("����", 18, 166);
	Person p7("��ʣ", 18, 210);

	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
	L.push_back(p6);
	L.push_back(p7);

	//���� ��ӡ����ʱ�� ��������Ľ��� ���
	//�����Զ����������� ������Ҫָ���������
	L.sort( myComparePerson);
	for (list<Person>::iterator it = L.begin(); it != L.end();it++)
	{
		cout << "������ " << it->m_Name << " ���䣺 " << it->m_Age << " ��ߣ�"<< it->m_Height<< endl;
	}

	//ɾ�� ���� 
	cout << " -------------------- " << endl;

	L.remove(p6);
	for (list<Person>::iterator it = L.begin(); it != L.end(); it++)
	{
		cout << "������ " << it->m_Name << " ���䣺 " << it->m_Age << " ��ߣ�" << it->m_Height << endl;
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