/*
 * date_generator.cpp
 *
 *  Created on: 2010-4-4 下午07:59:36
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#include <iostream>
#include <boost/date_time/gregorian/gregorian.hpp>

int main() {
    using namespace std;
    using namespace boost::gregorian;

    // examples:2010年4月的最后一个星期一是哪天？
    last_day_of_the_week_in_month lwdm(Monday, Apr);
    date d1 = lwdm.get_date(2010); //2010-Apr-26
    cout << d1 << endl;

    // examples: 2010年4月的第一个星期一是哪天？
    first_day_of_the_week_in_month fdm(Monday, Apr);
    date d2 = fdm.get_date(2010);//2010-Apr-05
    cout << d2 << endl;

    // 2010年4月的第三个星期一是哪天？
    typedef nth_day_of_the_week_in_month nth_dow;
    nth_dow ndm(nth_dow::third, Monday, Apr);
    date d3 = ndm.get_date(2010);//2010-Apr-19
    cout << d3 << endl;

    // examples: 每年中的某个特定的日期  
    partial_date pd(1, Oct);
    date d4 = pd.get_date(2010); //2010-Oct-01
    cout << d4 << endl;

    // examples: 2010年4月1日之后的第一个星期一是哪天？
    first_day_of_the_week_after fdaf(Sunday);
    date d5 = fdaf.get_date(date(2010, Apr, 1)); //2010-Apr-04
    cout << d5 << endl;

    // examples: 2010年4月1日之前的第一个星期一是那天？
    first_day_of_the_week_before fdbf(Monday);
    date d6 = fdbf.get_date(date(2010, Apr, 1)); //2010-Mar-29
    cout << d6 << endl;

    // 日期产生器的诉算法
    // examples:
    date d7(2010, Apr, 1); // 星期四 
    greg_weekday gw1(Friday);
    days ds1 = days_until_weekday(d7, gw1); // 3天
    cout << ds1 << endl;

    // 计算从给定日期到前一个给定周日的天数。
    // examples:
    date d8(2010, Apr, 1); // 星期四 
    greg_weekday gw2(Friday);
    days ds2 = days_before_weekday(d8, gw2); // 4天
    cout << ds2 << endl;

    cout << gregorian_calendar::day_number(date::ymd_type(2010, Apr, 4))
            << endl;
    cout << gregorian_calendar::epoch().year << endl;
}
