/*
 * mutex_test.cpp
 *
 *  Created on: 2010-3-8 下午11:20:04
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#include <iostream>
#include <boost/thread.hpp>

using namespace std;

using boost::thread;

typedef boost::mutex Mutex;
Mutex m;

void print10(const int& id) {
    m.lock();
    cout << "thread #" << id << ": ";
    //    boost::this_thread::sleep(boost::posix_time::milliseconds(500));
    for (int i = 1; i < 11; ++i) {
        boost::this_thread::sleep(boost::posix_time::milliseconds(50));
        cout << i << ' ';
    }
    cout << endl;
    m.unlock();
}

int main() {
    thread t1(print10, 1);
    thread t2(print10, 2);
    thread t3(print10, 3);

    t1.join();
    t2.join();
    t3.join();
}
