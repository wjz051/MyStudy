/*
 * unique_lock.cpp
 *
 *  Created on: 2010-3-8 下午11:39:16
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */
#include <iostream>
#include <boost/thread.hpp>

using namespace std;

using boost::thread;

boost::mutex m;
int k = 0;

void increment() {
    boost::unique_lock<boost::mutex> lock(m); // alternate:
    //     boost::mutex::scoped_lock lock(m);
    for (int i = 0; i < 5; ++i)
        k += i;
    cout << "increment(): k == " << k << endl;
}

void decrement() {
    boost::lock_guard<boost::mutex> lock(m);
    for (int i = 0; i < 5; ++i)
        k -= i;
    cout << "decrement(): k == " << k << endl;
}

int main() {
    boost::thread t1(increment);
    boost::thread t2(decrement);
    t1.join();
    t2.join();
}
