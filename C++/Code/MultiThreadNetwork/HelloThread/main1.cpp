#include<iostream>
#include<thread>
using namespace std;

void workFun()
{
	for (int n = 0; n < 4; n++)
		cout << "Hello,other thread." << endl;
}//��ռʽ

//main1-�����̣߳�join��detach�����߳�.cpp
int main1()
{
	thread t(workFun);
	t.detach();
	//t.join();
	for (int n = 0; n < 4; n++)
		cout << "Hello,main thread." << endl;
	while (true)
	{

	}
	return 0;
}