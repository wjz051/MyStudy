/*
 * bind_apply.cpp
 *
 *  Created on: 2010-3-3 下午09:50:30
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
#include <boost/bind/apply.hpp>
#include <boost/ref.hpp>

using namespace std;

void f1(int i) {
    cout << "f1() " << i << endl;
}
void f2(int i) {
    cout << "f2() " << i << endl;
}

int main() {
    typedef void (*pf)(int);
    std::vector<pf> v;
    v.push_back(f1);
    v.push_back(f2);
    v.push_back(f2);
    v.push_back(f2);

    int k = 0;
    std::for_each(v.begin(), v.end(), boost::bind(boost::apply<void>(), _1, k));
    //    std::for_each(v.begin(), v.end(), boost::bind(_1, 5));
}
