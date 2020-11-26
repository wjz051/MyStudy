/*
 * upgrade_lock.cpp
 *
 *  Created on: 2010-3-8 下午11:51:48
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#include <iostream>
#include <boost/thread.hpp>

using namespace std;

using boost::thread;

boost::shared_mutex m;
int k = 1;

void f(int id) {
    boost::upgrade_lock<boost::shared_mutex> lock(m);
    cout << "thread #" << id << ": " << k << endl;
    if (k < 6) {
        // boost::unique_lock<boost::shared_mutex> lock2(boost::move(lock)); // alternate:
        boost::upgrade_to_unique_lock<boost::shared_mutex> lock2(lock);
        k += 3;
    }
}

int main() {
    boost::thread t1(f, 1);
    boost::thread t2(f, 2);
    boost::thread t3(f, 3);

    t1.join();
    t2.join();
    t3.join();
}
