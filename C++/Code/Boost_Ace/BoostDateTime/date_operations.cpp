/*
 * date_operations.cpp
 *
 *  Created on: 2010-4-4 下午07:15:51
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#include <iostream>
#include <boost/date_time/gregorian/gregorian.hpp>

int main() {
    using namespace std;
    using namespace boost::gregorian;
    date d(2010, Apr, 8);//date d(2010, 4, 8);

    cout << d << " is " << d.day_of_week() << endl;
    cout << d << " is " << d.day_of_year() << "th day of the year." << endl;
    cout << d.year() << "-" << d.month() << " last day: " << d.end_of_month()
            << endl;
    cout << d << " is " << d.week_number() << "th week of the year." << endl;

    tm t = to_tm(d);
    cout << t.tm_year + 1900 << ' ' << t.tm_mon + 1 << endl;
}
