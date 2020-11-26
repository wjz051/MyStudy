/*
 * bind_fun_ptr.cpp
 *
 *  Created on: 2010-3-3 下午09:27:59
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <xfunctional>

#include <boost/bind.hpp>
#include <boost/ref.hpp>

using namespace std;

int f(int a, int b) {
    return a + b;
}

int g(int a, int b, int c) {
    return a + b + c;
}

int main() {
    boost::bind(f, 1, 8); // 产生一个无元函数对象，返回f(1,8)
    boost::bind(g, 1, 8, 12); // 同上
    int x = 108;
    bind(f, _1, 5)(x); // 返回f(x,5)
    std::bind2nd(std::ptr_fun(f), 5)(x); // 同上，标准库版本
    bind(f, 5, _1)(x); // 返回f(5, x)
    std::bind1st(std::ptr_fun(f), 5)(x); // 同上，标准库版本

    bind(f, boost::ref(x), _1)(32); // 传参数的引用，而不是参数的副本
    bind(f, boost::cref(42), _1)(28); // 参数的const引用
}
