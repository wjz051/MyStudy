/*
 * unique_lock2.cpp
 *
 *  Created on: 2010-3-8 下午11:43:59
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#include <iostream>
#include <boost/thread.hpp>

using namespace std;

using boost::thread;

boost::mutex m;
vector<string> strings;

void loadStrings(vector<string>& v) {
    // ...
}

void updateStrings() {
    boost::unique_lock<boost::mutex> lock(m);
    if (strings.empty()) {
        // loadStrings() 操作不涉及数据竞态，所以不需锁定
        lock.unlock();
        vector<string> localStrings;
        loadStrings(localStrings);

        // 更改共享数据前，重新获取锁
        lock.lock();
        copy(localStrings.begin(), localStrings.end(), back_inserter<string> (
                strings));
    }
}

int main() {
    thread t1(updateStrings);
    thread t2(updateStrings);

    t1.join();
    t2.join();
}
