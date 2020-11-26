/*
 * date_duration.cpp
 *
 *  Created on: 2010-4-4 下午07:28:21
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#include <iostream>
#include <boost/date_time/gregorian/gregorian.hpp>

int main() {
    using namespace std;
    using namespace boost::gregorian;

    date d1 = day_clock::local_day();
    date d2(2010, Jan, 2);
    date_duration dd = d1 - d2;
    cout << d1 << " - " << d2 << " = " << dd << " days" << endl;

    //    date_duration dd2(36);
    days dd2(36);
    d2 += dd2;
    cout << d2 << endl;

    months m1(18);
    d1 += m1; // 加上18个月
    cout << d1 << endl;

}
