/*
 * thread_create.cpp
 *
 *  Created on: 2010-3-8 下午09:17:39
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#include <iostream>
#include <boost/thread.hpp>

using namespace std;

struct ThreadFunc2 {
    void operator ()(const int& id) {
        cout << "thread #" << id << ": hello boost threads!" << endl;
    }

    void memThreadFunc(const int& id) {
        cout << "thread #" << id << ": hello boost threads!" << endl;
    }
};

void threadEunc(const int& id) {
    cout << "thread #" << id << ": hello boost threads!" << endl;
}

struct ThreadFunc {
    void operator ()(const int& id) {
        cout << "thread #" << id << ": hello boost threads!" << endl;
    }
};

int main() {
    // Free function
    boost::thread t1(threadEunc, 1);

    ThreadFunc2 threadObj;
    // Function Object
    boost::thread t2(threadObj, 2);

    // Member function
    boost::thread t3(&ThreadFunc2::memThreadFunc, &threadObj, 3);

    ThreadFunc threadObj2;
    // Reference of Function Object
    boost::thread t4(boost::ref(threadObj2), 4);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
}
