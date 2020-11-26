/*
 * condition_variable1.cpp
 *
 *  Created on: 2010-3-9 上午12:29:59
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#include <iostream>
#include <boost/thread.hpp>

using namespace std;

using boost::thread;

boost::condition_variable cond; // 关联多个线程的条件变量
boost::mutex m; // 保护共享资源 k 的互斥体
int k = 0; // 共享资源

void f1(const int& id) {
    boost::unique_lock<boost::mutex> lock(m);
    while (k < 5) {
        cout << "thread #" << id << ": k < 5, waiting ..." << endl;
        cond.wait(lock); // #1
    }
    cout << "thread #" << id << ": now k >= 5, printing ..." << endl;
}

void f2(const int& id) {
    {
        boost::unique_lock<boost::mutex> lock(m);
        cout << "thread #" << id << ": k will be changed ..." << endl;
        k += 5;
    }
    cond.notify_all(); // #2 不需lock
}

int main() {
    // 如果f2()中是 cond.notify_one()，结果？
    boost::thread t1(f1, 1);
    boost::thread t2(f1, 2);
    boost::thread t3(f2, 100);

    t1.join();
    t2.join();
    t3.join();
}
