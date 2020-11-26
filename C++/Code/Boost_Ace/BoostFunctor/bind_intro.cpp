/*
 * bind_intro.cpp
 *
 *  Created on: 2010-3-3 下午08:58:11
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

using namespace std;

int fn(int a, int b) {
    return a + b;
}

int f2(int a, int b, int c) {
    return a + b * c;
}

struct Temp {
    void f(int i) {
        cout << i << " Temp::f()" << endl;
    }
};

void testF() {
    vector<Temp*> v;
    v.push_back(new Temp);
    v.push_back(new Temp);
    v.push_back(new Temp);
    v.push_back(new Temp);

    cout << "std::bind2nd & mem_fun: " << endl;
    for_each(v.begin(), v.end(), bind2nd(mem_fun(&Temp::f), 5));
    cout << "boost::bind: " << endl;
    for_each(v.begin(), v.end(), boost::bind(&Temp::f, _1, 5));
}

int main() {
    testF();

    int a[] = { 1, 2, 3, 4, 5, 6 };
    transform(a, a + 6, a, bind2nd(plus<int> (), 10));
    copy(a, a + 6, ostream_iterator<int> (cout, " "));
    cout << endl;

    transform(a, a + 6, a, boost::bind(plus<int> (), _1, 100));
    copy(a, a + 6, ostream_iterator<int> (cout, " "));
    cout << endl;

    transform(a, a + 6, a, bind1st(minus<int> (), 15));
    copy(a, a + 6, ostream_iterator<int> (cout, " "));
    cout << endl;

    transform(a, a + 6, a, boost::bind(minus<int> (), 15, _1));
    copy(a, a + 6, ostream_iterator<int> (cout, " "));
    cout << endl;

    transform(a, a + 6, a, bind2nd(ptr_fun(fn), 15));
    copy(a, a + 6, ostream_iterator<int> (cout, " "));
    cout << endl;

    transform(a, a + 6, a, boost::bind(fn, _1, 15));
    copy(a, a + 6, ostream_iterator<int> (cout, " "));
    cout << endl;

    // More arguments (> 2)
    transform(a, a + 6, a, boost::bind(f2, _1, 15, 6));
    copy(a, a + 6, ostream_iterator<int> (cout, " "));
    cout << endl;
}
