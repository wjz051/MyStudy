/*
 * lambda_statements.cpp
 *
 *  Created on: 2010-3-3 下午11:06:20
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#include <iostream>
#include <algorithm>

#include <boost/lambda/lambda.hpp>
#include <boost/lambda/if.hpp>
#include <boost/lambda/loops.hpp>
#include <boost/lambda/switch.hpp>

using namespace std;

int main() {
    using namespace boost::lambda;
    // 下面代码需要包含<boost/lambda/if.hpp>
    int a[] = { 98, 21, 32 };
    for_each(a, a + 3, if_then(_1 % 2 == 0, cout << _1 << ' '));
    cout << endl;

    for_each(a, a + 3, if_(_1 % 2 == 0)[cout << _1 << ' '] .else_[cout << ++_1
            << ' ']); // same above
    cout << endl;

    // 下面代码需要包含<boost/lambda/loops.hpp>
    int am[5][10];
    int i;
    for_each(am, am + 5, for_loop(var(i) = 0, var(i) < 10, ++var(i), _1[var(i)]
            += 1));
    for_each(am, am + 5, for_(var(i) = 0, var(i) < 10, ++var(i))[_1[var(i)]
            += 1]); // same above

    // 下面代码需要包含<boost/lambda/switch.hpp>
    int b[] = {12, 23 ,36, 9};
    std::for_each(b, b + 4,
            (switch_statement(_1,
             case_statement<12> (std::cout << constant("zero")),
             case_statement<23> (std::cout << constant("one")),
             default_statement(cout << constant("other: ") << _1)),
             cout << constant("\n")));
}
