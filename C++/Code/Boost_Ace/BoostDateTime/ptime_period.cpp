/*
 * ptime_period.cpp
 *
 *  Created on: 2010-4-4 下午09:15:39
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#include <iostream>

#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>

int main() {
    using namespace std;
    using namespace boost::posix_time;
    using namespace boost::gregorian;

    date d1 = day_clock::local_day();
    time_period
            tp1(ptime(d1, hours(1)), ptime(d1, hours(1) + milliseconds(23)));
    cout << tp1 << endl;

    time_period tp2(second_clock::local_time(), seconds(35));
    cout << tp2 << endl;

    tp2.shift(hours(1));
    cout << tp2 << endl;

    tp2.expand(hours(1));
    cout << tp2 << endl;

    cout << to_simple_string(tp1) << endl;

}
