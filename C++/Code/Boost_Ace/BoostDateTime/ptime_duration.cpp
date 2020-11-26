/*
 * ptime_duration.cpp
 *
 *  Created on: 2010-4-4 下午09:06:02
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

    time_duration td = hours(1) + seconds(10); //01:00:10
    td = hours(1) + microseconds(5); //01:00:00.000005
    cout << td << endl;

    // 注意，是否存在更高分辨率的类(如：纳秒)取决于库的安装。
    // 另一个方法是利用 time_duration 的 ticks_per_second()
    // 方法来编写可移植的代码，这样可以不管库是如何编译的。
    // 以下是计算分辨率无关的计数值的常用方式。
    //    count * (time_duration_ticks_per_second / count_ticks_per_second);

    // 例如，假设我们想用表示十分之一秒的计数值来构造时间。即每一 tick 为0.1秒。 
    int number_of_tenths = 5;
    //创建一个分辨率无关的计数值 -- 除以10，因为一秒分为10份 
    int count = number_of_tenths * (time_duration::ticks_per_second() / 1000000);
    time_duration td2(1, 2, 3, count); //01:02:03.5 //与分辨率设置无关 
    cout << to_iso_string(td2) << endl;
}
