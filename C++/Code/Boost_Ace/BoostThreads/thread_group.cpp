/*
 * thread_group.cpp
 *
 *  Created on: 2010-3-8 下午10:22:47
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#include <iostream>
#include <boost/thread.hpp>

using namespace std;

using boost::thread;

void f1() {
    cout << "f1()" << endl;
}

void f2() {
    cout << "f2()" << endl;
}

int main() {
    boost::thread_group grp;
    for (int i = 0; i < 3; ++i)
        grp.create_thread(f1);
    grp.add_thread(new boost::thread(f2));

    cout << grp.size() << endl;
    grp.join_all();
}
