#ifndef _CELL_TASK_H_
#define _CELL_TASK_H_

#include<thread>
#include<mutex>
#include<list>

/*
������---doTask��������
��������������---addTask(task)��������,OnRun()���������ദ������
*/

//��������-����
class CellTask
{
public:
	CellTask()
	{

	}

	//������
	virtual ~CellTask()
	{

	}
	//ִ������
	virtual void doTask()
	{

	}
private:

};

//������Ϣ��������
class CellSendMsg2ClientTask :public CellTask
{
	CellClient* _pClient;
	netmsg_DataHeader* _pHeader;
public:
	CellSendMsg2ClientTask(CellClient* pClient, netmsg_DataHeader* header)
	{
		_pClient = pClient;
		_pHeader = header;
	}

	//ִ������
	void doTask()
	{
		_pClient->SendData(_pHeader);
		delete _pHeader;
	}
};

//ִ������ķ�������
class CellTaskServer 
{
private:
	//��������
	std::list<CellTask*> _tasks;
	//�������ݻ�����
	std::list<CellTask*> _tasksBuf;
	//�ı����ݻ�����ʱ��Ҫ����
	std::mutex _mutex;
public:
	//�������
	void addTask(CellTask* task)
	{
		std::lock_guard<std::mutex> lock(_mutex);
		_tasksBuf.push_back(task);
	}
	//���������߳�
	void Start()
	{
		//�߳�
		std::thread t(std::mem_fn(&CellTaskServer::OnRun),this);
		t.detach();
	}
protected:
	//��������
	void OnRun()
	{
		while (true)
		{
			//�ӻ�����ȡ������
			if (!_tasksBuf.empty())
			{
				std::lock_guard<std::mutex> lock(_mutex);
				for (auto pTask : _tasksBuf)
				{
					_tasks.push_back(pTask);
				}
				_tasksBuf.clear();
			}
			//���û������
			if (_tasks.empty())
			{
				std::chrono::milliseconds t(1);
				std::this_thread::sleep_for(t);
				continue;
			}
			//��������
			for (auto pTask : _tasks)
			{
				pTask->doTask();
				delete pTask;
			}
			//�������
			_tasks.clear();
		}

	}
};
#endif // !_CELL_TASK_H_
