#include<iostream>
#include<thread>
using namespace std;

void workFun2(int index)
{
	for (int n = 0; n < 4; n++)
		cout << index << "Hello,other thread." << endl;
}//��ռʽ

//main2-���ݲ�������ں����������߳�����.cpp
int main2()
{
	thread t[4];
	for (int n = 0; n < 4; n++)
	{
		t[n] = thread(workFun2,n);
	}
	for (int n = 0; n < 4; n++)
	{
		t[n].join();//�߳�ִ���꣬��ִ�����߳�
		//t[n].detach();//�����̷߳��룬�����߳�ͬ��ִ��
	}

	for (int n = 0; n < 4; n++)
		cout << "Hello,main thread." << endl;
	while (true)
	{

	}
	return 0;
}