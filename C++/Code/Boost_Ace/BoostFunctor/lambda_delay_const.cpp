/*
 * lambda_delay_const.cpp
 *
 *  Created on: 2010-3-3 下午10:51:31
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#include <iostream>
#include <algorithm>

#include <boost/lambda/lambda.hpp>

using namespace std;

int main() {
    using namespace boost::lambda;

    int a[] = { 12, 6, 92 };
    cout << "for_each(a, a + 3, cout << _1 << '*')" << endl;
    for_each(a, a + 3, cout << _1 << '*'); // 12 6 92
    cout << endl;

    // 下面的  ' ' 立即求值
    cout << "for_each(a, a + 3, cout << '*' << _1)" << endl;
    for_each(a, a + 3, cout << '*' << _1); // 12692
    cout << endl;

    cout << "for_each(a, a + 3, cout << constant('*') << _1)" << endl;
    for_each(a, a + 3, cout << constant('*') << _1); // 12 6 92
    cout << endl;

    int index = 0;
    // 输出： 1:12
    //      6
    //      92
    cout << "for_each(a, a + 3, cout << ++index << ':' << _1 << '\n')" << endl;
    for_each(a, a + 3, cout << ++index << ':' << _1 << '\n');

    // 下面输出正常：
    cout << "for_each(a, a + 3, cout << ++var(index) << ':' << _1 << '\n')"
            << endl;
    for_each(a, a + 3, cout << ++var(index) << ':' << _1 << '\n');

    // Demo for Named objects
    int i1 = 0;
    int j1;
    for_each(a, a + 3, (var(j1) = _1, _1 = var(i1)/*, var(i1) = var(j1)*/));

    // 等价于：
    int i2 = 0;
    int j2;
    var_type<int>::type vi(var(i2)), vj(var(j2));
    for_each(a, a + 3, (vj = _1, _1 = vi/*, vi = vj*/));

    // 下面是命名延迟常量的示例：
    constant_type<char>::type space(constant(' '));
    for_each(a, a + 3, cout << space << _1);
}
