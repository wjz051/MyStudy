#include<iostream>
#include<thread>
#include<mutex>//��
#include"CELLTimestamp.hpp"
using namespace std;

mutex m;
const int tCount = 4;
int sum = 0;
void workFun3(int index)
{
	for (int n = 0; n < 20000; n++)
	{
		//�Խ���
		lock_guard<mutex> lg(m);

		//�ٽ�����-��ʼ
		//m.lock();
		sum++;
		//m.unlock();
		//�ٽ�����-����
	}

	//cout << index << "Hello,main thread." << n << endl;
}//��ռʽ

//main3-�����ٽ�����.cpp
int main3()
{
	thread t[tCount];
	for (int n = 0; n < tCount; n++)
	{
		t[n] = thread(workFun3,n);
	}
	CELLTimestamp tTime;
	for (int n = 0; n < tCount; n++)
	{
		t[n].join();
		//t[n].detach();
	}
	cout << tTime.getElapsedTimeInMilliSec()<<",sum=" <<sum<< endl;
	sum = 0;
	tTime.update();
	for (int n = 0; n < 80000; n++)
	{
		sum++;
	}
	cout << tTime.getElapsedTimeInMilliSec() << ",sum=" << sum << endl;
	cout << "Hello,main thread." << endl;
	return 0;
}