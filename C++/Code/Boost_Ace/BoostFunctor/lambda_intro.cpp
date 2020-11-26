/*
 * lambda_intro.cpp
 *
 *  Created on: 2010-3-3 下午10:22:00
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#include <iostream>
#include <algorithm>

#include <boost/lambda/lambda.hpp>

using namespace std;

template<int n>
void add(int& src) {
    src += n;
}

struct PrintV {
    void operator()(int v) {
        cout << v << ' ';
    }
};

void f1() {
    int a[] = { 12, 3, 6, 98, 23 };
    for_each(a, a + 5, add<12> ); // 使用函数指针
    for_each(a, a + 5, PrintV()); // 使用函数对象
    cout << endl;
}

void f2() {
    using namespace boost::lambda;
    int a[] = { 12, 3, 6, 98, 23 };
    for_each(a, a + 5, _1 += 12); // 使用函数指针
    for_each(a, a + 5, cout << _1 << ' '); // 使用函数对象
    cout << endl;
}

int main() {
    f1();
    f2();
}
