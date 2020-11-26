/*
 * call_once.cpp
 *
 *  Created on: 2010-3-9 上午12:46:46
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#include <iostream>
#include <boost/thread.hpp>

using namespace std;

using boost::thread;

boost::once_flag once = BOOST_ONCE_INIT; // 注意这个操作不要遗漏了

void func() {
    cout << "Will be called but one time!" << endl;
}

void threadFunc() {
//    func();
    boost::call_once(&func, once);
}

int main() {
    boost::thread_group threads;
    for (int i = 0; i < 5; ++i)
        threads.create_thread(&threadFunc);
    threads.join_all();
}
