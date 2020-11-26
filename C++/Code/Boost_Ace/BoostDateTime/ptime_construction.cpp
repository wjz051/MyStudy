/*
 * ptime_construction.cpp
 *
 *  Created on: 2010-4-4 下午08:44:55
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */
#include <iostream>
#include <string>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>

int main() {
    using namespace std;
    using namespace boost::posix_time;
    using namespace boost::gregorian;

    ptime t1(date(2002, Jan, 10), time_duration(1, 2, 3));
    cout << t1 << endl;
    ptime
            t2(date(2002, Jan, 10), hours(1) + boost::posix_time::microseconds(
                    5));
    //    ptime
    //                t2(date(2002, Jan, 10), hours(1) + boost::posix_time::nanoseconds(
    //                        5));
    cout << t2 << endl;

    // spec_values
    ptime d1(neg_infin);
    ptime d2(pos_infin);
    ptime d3(not_a_date_time);
    ptime d4(max_date_time);
    ptime d5(min_date_time);

    // 从字符串构造 
    std::string ts("2002-01-20 23:59:59.050");
    ptime t3(time_from_string(ts));
    cout << t3 << endl;

    // 从不带分隔的字符串构造。 
    std::string ts2("20020131T235959");
    ptime t4(from_iso_string(ts2));
    cout << t4 << endl;

    cout << to_simple_string(t3) << endl;
    cout << to_iso_string(t3) << endl;
    cout << to_iso_extended_string(t3) << endl;
}
