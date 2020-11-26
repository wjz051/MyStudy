/*
 * tss_test.cpp
 *
 *  Created on: 2010-3-9 上午01:04:33
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#include <iostream>
#include <boost/thread.hpp>

using namespace std;

using boost::thread;

boost::thread_specific_ptr<int> value;
int k;
void increment() {
    int* p = value.get();

    ++*p;
    ++k;
}

void thread_proc(int id) {
    value.reset(new int(0)); //initialize the thread's storage
    for (int i = 0; i < 5; ++i) {
        increment();
        int* p = value.get();
        cout << "thread #" << id << ": " << *p << endl;
        cout << "thread #" << id << ": " << k << endl;
        //        assert(*p == i+1);
    }
}

int main() {
    boost::thread_group threads;
    for (int i = 0; i < 5; ++i)
        threads.create_thread(boost::bind(thread_proc, i));
    threads.join_all();
}
