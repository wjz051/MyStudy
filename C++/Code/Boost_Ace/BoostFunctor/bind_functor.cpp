/*
 * bind_functor.cpp
 *
 *  Created on: 2010-3-3 下午09:32:49
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

#include <boost/bind.hpp>
#include <boost/ref.hpp>

using namespace std;

struct F {
    int operator()(int a, int b) {
        return a - b;
    }
    bool operator()(long a, long b) {
        return a == b;
    }
};

int main() {
    F f;
    int x = 108;
    // 由于函数对象 F 内部没有定义 return_type 类型，
    // 所以下面需显式写成bind<int>
    boost::bind<int> (f, _1, _1)(x); // f(x, x)

    // 由于函数对象less<>内部定义了return_type类型，
    // 所以下面的bind不需显式写成bind<int>
    boost::bind(std::less<int>(), _1, 9)(x); // x < 9
}
