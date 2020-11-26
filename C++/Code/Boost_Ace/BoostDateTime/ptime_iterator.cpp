/*
 * ptime_iterator.cpp
 *
 *  Created on: 2010-4-4 下午09:26:58
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

    date d(2010, Apr, 4);
    ptime start(d);
    ptime end = start + hours(1);
    time_iterator titr(start, minutes(15)); //每次递增15分钟
    //生成 00:00:00, 00:15:00, 00:30:00, 00:45:00
    while (titr < end) {
        std::cout << to_simple_string(*titr) << std::endl;
        ++titr;
    }
    std::cout << "Now backward" << std::endl;
    //produces 01:00:00, 00:45:00, 00:30:00, 00:15:00
    while (titr > start) {
        std::cout << to_simple_string(*titr) << std::endl;
        --titr;
    }

}
