/*
 * function_intro.cpp
 *
 *  Created on: 2010-3-3 下午10:05:55
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#include <iostream>
#include <algorithm>

#include <boost/function.hpp>

using namespace std;

struct int_div {
    float operator()(int x, int y) const {
        return ((float) x) / y;
    }
};

float float_div(float x, float y) {
    return x / y;
}

void test(boost::function<float(float x, float y)> const& f) {
    cout << f(12, 45) << endl;
}
struct X {
    int foo(int) {
        return 0;
    }
};

int main() {
    boost::function<float(int x, int y)> f1;
    boost::function2<float, int, int> f2;
    f1 = int_div();
    f2 = int_div();
    cout << f1(5, 3) << endl;
    cout << f2(12, 9) << endl;

    test(&float_div);

    boost::function<int(X*, int)> f3;
    f3 = &X::foo;
    X x;
    f3(&x, 5);

    // 或按下面的方式，使用functionN
    boost::function2<int, X*, int> f4;
    f4 = &X::foo;
    X x2;
    f3(&x2, 5);

    // 当然最好的是使用bind，而不是function<>！
}
