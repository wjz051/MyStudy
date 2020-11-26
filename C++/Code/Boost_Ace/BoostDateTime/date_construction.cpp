/*
 * date_construction.cpp
 *
 *  Created on: 2010-4-4 下午07:06:32
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
    cout << d << endl;

    date d1(neg_infin);
    date d2(pos_infin);
    date d3(not_a_date_time);

    date d4(max_date_time);
    cout << "max_date: " << d4 << endl;
    date d5(min_date_time);
    cout << "min_date: " << d5 << endl;

    date d6 = from_string("2010-02-18");
    date d7 = from_undelimited_string("20101208");
    cout << d6 << '/' << d7 << endl;

    cout << day_clock::local_day() << endl;
    cout << day_clock::universal_day() << endl;

}
