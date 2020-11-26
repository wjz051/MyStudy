/*
 * thread_interrupts.cpp
 *
 *  Created on: 2010-3-8 下午09:51:03
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#include <iostream>
#include <boost/thread.hpp>

using namespace std;

using boost::thread;

void f1(const int& id) {
    cout << "thread #" << id << ": started" << endl;
    boost::system_time const timeout = boost::get_system_time()
            + boost::posix_time::seconds(3);
    thread::sleep(timeout);
    cout << "thread #" << id << ": ended" << endl;
}

void f2(const int& id) {
    cout << "thread #" << id << ": started" << endl;
    thread::yield();
    cout << "thread #" << id << ": ended" << endl;
}

void f3(const int& id) {
    cout << "thread #" << id << ": started" << endl;
    boost::this_thread::interruption_point();
    cout << "thread #" << id << ": ended" << endl;
}

int main() {
    thread t1(f1, 1);
    t1.interrupt();
    thread t2(f2, 2);
    thread t3(f3, 3);
    t3.interrupt();

    t1.join();
    t2.join();
    t3.join();
}
