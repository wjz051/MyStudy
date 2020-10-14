#include<chrono>
#include<thread>
#include<iostream>

#include<condition_variable>
/*
封装condition_variable条件变量作为信号量

1.wait()阻塞当前线程
2.wakeup()唤醒当前线程

根据linux下条件变量的机制，condition_variable在wait成员函数内部会先调用参数unique_lock的unlock临时解锁，
让出锁的拥有权（以让其它线程获得该锁使用权加锁，改变条件，解锁），然后自己等待notify信号，
等到之后，再调用参数unique_lock的lock加锁，处理相关逻辑，最后unique_lock对象销毁时自动解锁。
也即是说condition_variable的wait函数内伪代码如下：
condition_variable::wait(std::unique_lock<std::mutex>& lk)
{
	  lk.unlock();
	  waiting_signal();
	  lk.lock();
}
*/
class CELLSemaphore
{
public:
	//阻塞当前线程
	void wait()
	{
        std::cout<<"wait begin1"<<std::endl;
		std::unique_lock<std::mutex> lock(_mutex);
        std::cout<<"wait begin2"<<std::endl;
		if (++_wait > 0)
		{
            std::cout<<"wait begin3"<<std::endl;
			//阻塞等待
			_cv.wait(lock, [this]()->bool{
				return _wakeup > 0;
			});
            std::cout<<"wait end"<<std::endl;
			--_wakeup;
		}
	}
	//唤醒当前线程
	void wakeup()
	{
        std::cout<<"wakeup begin1"<<std::endl;
		std::lock_guard<std::mutex> lock(_mutex);
        std::cout<<"wakeup begin2"<<std::endl;
		if (--_wait >= 0)
		{
            std::cout<<"wakeup begin3"<<std::endl;
			++_wakeup;
			_cv.notify_one();
            std::cout<<"wakeup end"<<std::endl;
		}
	}

private:
	//改变数据缓冲区时需要加锁
	std::mutex _mutex;
	//阻塞等待-条件变量
	std::condition_variable _cv;
	//等待计数
	int _wait = 0;
	//唤醒计数
	int _wakeup = 0;
};

class CELLThread
{
private:
	typedef std::function<void(CELLThread*)> EventCall;
public:
	//启动线程
	void Start(
		EventCall onCreate = nullptr,
		EventCall onRun = nullptr,
		EventCall onDestory = nullptr)
	{
		std::lock_guard<std::mutex> lock(_mutex);
		if (!_isRun)
		{
			_isRun = true;

			if (onCreate)
				_onCreate = onCreate;
			if (onRun)
				_onRun = onRun;
			if (onDestory)
				_onDestory = onDestory;

			//线程
			std::thread t(std::mem_fn(&CELLThread::OnWork), this);
			t.detach();
		}
	}

	//关闭线程
	void Close()
	{
		std::lock_guard<std::mutex> lock(_mutex);
		if (_isRun)
		{
			_isRun = false;
			_sem.wait();
		}
	}
	//在工作函数中退出
	//不需要使用信号量来阻塞等待
	//如果使用会阻塞
	void Exit()
	{
		std::lock_guard<std::mutex> lock(_mutex);
		if (_isRun)
		{
			_isRun = false;
		}
	}

	//线程是否启动运行状态
	bool isRun()
	{
		return _isRun;
	}
protected:
	//线程的运行时的工作函数
	void OnWork()
	{
		if (_onCreate)
			_onCreate(this);
		if (_onRun)
			_onRun(this);
		if (_onDestory)
			_onDestory(this);

		_sem.wakeup();
	}
private:
	EventCall _onCreate;
	EventCall _onRun;
	EventCall _onDestory;
	//不同线程中改变数据时需要加锁
	std::mutex _mutex;
	//控制线程的终止、退出
	CELLSemaphore _sem;
	//线程是否启动运行中
	bool	_isRun = false;
};

int main()
{
    CELLThread thread;
    thread.Start(nullptr,[](CELLThread *t){
            while(t->isRun())
             std::cout<<"123"<<std::endl;
    });

    _sleep(2);
    thread.Close();

    getchar();

    return 0;
}


//虚假唤醒