/*
 * thread_interrupts2.cpp
 *
 *  Created on: 2010-3-8 下午10:05:38
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#include <iostream>
#include <boost/thread.hpp>

using namespace std;

using boost::thread;

void print10(const int& id) {
    boost::this_thread::disable_interruption di;
    cout << boost::this_thread::interruption_enabled() << endl;
    cout << "thread #" << id << ": ";
    //    boost::this_thread::sleep(boost::posix_time::seconds(2));

    boost::system_time const timeout = boost::get_system_time()
            + boost::posix_time::seconds(2);
    thread::sleep(timeout);

    for (int i = 1; i < 11; ++i)
        cout << i << ' ';
    cout << endl;
    boost::this_thread::restore_interruption ri(di);
    cout << boost::this_thread::interruption_enabled() << endl;
}

int main() {
    thread t1(print10, 1);
    thread t2(print10, 2);
    thread t3(print10, 3);
    t3.interrupt();

    t1.join();
    t2.join();
    t3.join();
}
