/*
 * recursive_mutex.cpp
 *
 *  Created on: 2010-3-8 下午11:11:33
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#include <iostream>
#include <boost/thread.hpp>

using namespace std;

using boost::thread;

//typedef boost::mutex Mutex;
typedef boost::recursive_mutex Mutex;
Mutex m;

void f1() {
    m.lock();
    cout << "f1()" << endl;
    m.unlock();
}

void f2() {
    m.lock();
    cout << "f2()" << endl;
    f1();
    m.unlock();
}

int main() {
    thread t1(f2);
    thread t2(f2);

    t1.join();
    t2.join();
}
