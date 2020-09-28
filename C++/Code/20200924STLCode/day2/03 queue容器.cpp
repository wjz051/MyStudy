#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <queue>

/*
queue���캯��---����
queue<T> queT;//queue����ģ����ʵ�֣�queue�����Ĭ�Ϲ�����ʽ��
queue(const queue &que);//�������캯��
3.5.3.2 queue��ȡ�������ɾ������
push(elem);//����β���Ԫ��
pop();//�Ӷ�ͷ�Ƴ���һ��Ԫ��
back();//�������һ��Ԫ��
front();//���ص�һ��Ԫ��

3.5.3.3 queue��ֵ����
queue& operator=(const queue &que);//���صȺŲ�����
3.5.3.4 queue��С����
empty();//�ж϶����Ƿ�Ϊ��
size();//���ض��еĴ�С

*/

void test01()
{
	queue<int>q;
	q.push(10);//����β���Ԫ��
	q.push(20); 
	q.push(30); 
	q.push(40);

	while (!q.empty())
	{

		//  10 40  20 40  30  40  40  40
		cout << "��ͷ: " << q.front() << endl; 
		cout << "��β: " << q.back() << endl; 
		//������ͷԪ��
		q.pop();
	}

	cout << "size : " << q.size() << endl;




}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}