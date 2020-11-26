/*
 * bind_functor_ref.cpp
 *
 *  Created on: 2010-3-3 下午09:36:32
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <cassert>

#include <boost/bind.hpp>
#include <boost/ref.hpp>

using namespace std;

struct F2 {
    int s;
    typedef void result_type;
    void operator()(int x) {
        s += x;
    }
};

int main() {
    F2 f2 = { 0 };
    int a[] = { 1, 2, 3 };
    std::for_each(a, a + 3, boost::bind(boost::ref(f2), _1)); // 传f2的引用

    //    std::for_each(a, a + 3, boost::bind(f2, _1)); // 传f2的副本
    cout << f2.s << endl;
    assert(f2.s == 6); // 这样f2对象的状态得以延续
}
