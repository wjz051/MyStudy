/*
 * bind_mem_fun.cpp
 *
 *  Created on: 2010-3-3 下午09:40:52
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <cassert>

#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>
#include <boost/ref.hpp>

using namespace std;

struct X {
    bool f(int a) {
        return true;
    }
};

int main() {
    X x;
    boost::shared_ptr<X> p(new X);

    int i = 5;
    boost::bind(&X::f, boost::ref(x), _1)(i); // x.f(i), as std::mem_fun_ref
    boost::bind(&X::f, &x, _1)(i); //(&x)->f(i), same as std::mem_fun
    boost::bind(&X::f, x, _1)(i); // (internal copy of x).f(i), as std::mem_fun_ref
    boost::bind(&X::f, p, _1)(i); // (internal copy of p)->f(i), as std::mem_fun
}
