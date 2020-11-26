/*
 * date_iterator_cal.cpp
 *
 *  Created on: 2010-4-4 下午07:45:49
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#include <iostream>
#include <boost/date_time/gregorian/gregorian.hpp>

int main() {
    using namespace std;
    using namespace boost::gregorian;
    cout << "Year: ";
    int y;
    cin >> y;
    cout << "Month: ";
    int m;
    cin >> m;

    date firstDay(y, m, 1);
    cout << "Sun Mon Tue Wed Thu Fri Sat\n";

    date lastDay = firstDay.end_of_month();
    int empty = firstDay.day_of_week();
    for (int i = 0; i < empty; ++i) {
        cout << setw(4) << setfill(' ') << ' ';
    }

    day_iterator it(firstDay);
    for (; it <= lastDay; ++it) {
        cout << setw(3) << it->day();
        cout << (6 == it->day_of_week() ? '\n' : ' ');
    }
}
