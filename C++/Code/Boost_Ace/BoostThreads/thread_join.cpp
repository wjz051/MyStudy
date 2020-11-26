/*
 * thread_join.cpp
 *
 *  Created on: 2010-3-8 下午09:40:37
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#include <iostream>
#include <boost/thread.hpp>

using namespace std;

void threadEunc(const int& id) {
    boost::this_thread::sleep(boost::posix_time::seconds(2));
    cout << "thread #" << id << ": hello boost threads!" << endl;
}

int main() {
    // Free function
    boost::thread t1(threadEunc, 1);

//    t1.join();
    cout << "end of main thread" << endl;
}
